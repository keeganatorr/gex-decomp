"""Independent, read-only PE/i386 COFF checks for retained exact artifacts."""
import struct


def span(data, offset, size):
    if offset < 0 or size < 0 or offset + size > len(data):
        raise ValueError('Truncated binary range')
    return data[offset:offset + size]


def unpack(fmt, data, offset):
    return struct.unpack(fmt, span(data, offset, struct.calcsize(fmt)))


def image_bytes(image, address, size):
    if image[:2] != b'MZ' or size <= 0:
        raise ValueError('Not a nonempty PE range')
    pe, = unpack('<I', image, 0x3c)
    if span(image, pe, 4) != b'PE\0\0':
        raise ValueError('Not PE')
    machine, count = unpack('<HH', image, pe + 4)
    optional_size, = unpack('<H', image, pe + 20)
    optional = pe + 24
    magic, = unpack('<H', image, optional)
    if machine != 0x14c or magic != 0x10b or optional_size < 32:
        raise ValueError('Not PE32/i386')
    base, = unpack('<I', image, optional + 28)
    rva = address - base
    for index in range(count):
        sh = optional + optional_size + index * 40
        section_rva, = unpack('<I', image, sh + 12)
        raw_size, = unpack('<I', image, sh + 16)
        raw, = unpack('<I', image, sh + 20)
        if section_rva <= rva and rva + size <= section_rva + raw_size:
            return span(image, raw + rva - section_rva, size)
    raise ValueError('Range is not completely raw-backed')


def resolve_object(data, target_symbol, address, bindings):
    machine, count, _, symbols_at, symbol_count, optional_size, _ = unpack('<HHIIIHH', data, 0)
    if machine != 0x14c or optional_size or not 1 <= count <= 96 or not 1 <= symbol_count <= 65536:
        raise ValueError('Unsupported COFF header')
    span(data, 20, count * 40)
    span(data, symbols_at, symbol_count * 18)
    strings_at = symbols_at + symbol_count * 18
    strings_size, = unpack('<I', data, strings_at)
    if strings_size < 4:
        raise ValueError('Invalid COFF string table')
    strings = span(data, strings_at, strings_size)
    symbols = {}
    index = 0
    while index < symbol_count:
        name_bytes, value, section, kind, storage, auxiliaries = unpack('<8sIhHBB', data, symbols_at + index * 18)
        if name_bytes[:4] == bytes(4):
            offset, = struct.unpack('<I', name_bytes[4:])
            if not 4 <= offset < len(strings) or b'\0' not in strings[offset:]:
                raise ValueError('Invalid long symbol')
            name = strings[offset:].split(b'\0', 1)[0].decode('ascii')
        else:
            name = name_bytes.split(b'\0', 1)[0].decode('ascii')
        symbols[index] = (name, value, section, kind, storage)
        index += 1 + auxiliaries
    if index != symbol_count:
        raise ValueError('Truncated auxiliary symbols')
    targets = [s for s in symbols.values() if s[0] == target_symbol]
    if len(targets) != 1:
        raise ValueError('Missing/ambiguous target symbol')
    _, value, section, _, storage = targets[0]
    if value or not 1 <= section <= count or storage != 2:
        raise ValueError('Target does not own its code section')
    if any(s[2] == section and s[3] == 0x20 and s[0] != target_symbol for s in symbols.values()):
        raise ValueError('Multiple functions in section')
    sh = 20 + (section - 1) * 40
    size, raw, relocations_at = unpack('<III', data, sh + 16)
    relocations_count, = unpack('<H', data, sh + 32)
    attributes, = unpack('<I', data, sh + 36)
    if not attributes & 0x20 or not 1 <= size <= 1024 * 1024:
        raise ValueError('Invalid target code section')
    code = bytearray(span(data, raw, size))
    destinations = {name: int(value, 16) for name, value in bindings.items()}
    destinations[target_symbol] = address
    used = set()
    relocations = []
    for i in range(relocations_count):
        offset, symbol, kind = unpack('<IIH', data, relocations_at + i * 10)
        if symbol not in symbols or offset + 4 > size or kind not in (6, 20):
            raise ValueError('Invalid/unsupported relocation')
        locations = set(range(offset, offset + 4))
        if used & locations:
            raise ValueError('Overlapping relocations')
        used |= locations
        name = symbols[symbol][0]
        if name not in destinations or not 0 <= destinations[name] <= 0xffffffff:
            raise ValueError('Unresolved/out-of-range destination: ' + name)
        addend, = unpack('<I', code, offset)
        value = destinations[name] + addend
        if kind == 20:
            value -= address + offset + 4
        struct.pack_into('<I', code, offset, value & 0xffffffff)
        relocations.append({'Offset': offset, 'Type': kind, 'Symbol': name})
    return bytes(code), relocations


def contract(config, address):
    tc = config['toolchain']
    override = config.get('functionOverrides', {}).get(address, {})
    return (override.get('flags', tc['flags']), override.get('language', 'cpp'),
            override.get('targetSymbol', tc['targetSymbol']))


def check_contract(proof, config, address):
    flags, language, symbol = contract(config, address)
    if (proof['flags'], proof.get('language', 'cpp'), proof['targetSymbol']) != (flags, language, symbol):
        raise ValueError('Effective compiler contract differs: ' + address)
