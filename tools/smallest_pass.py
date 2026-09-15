"""One operator-requested pass, not an autonomous model campaign.

Backend owns all verification and evidence. This client checkpoints source intent,
uses scripts/verify's durable IDs, and stops rather than repeating an uncertain
mutation. No Ghidra writes, compiler/config changes, assembly, or guessed layouts.
Fresh decompiler output is a PROPOSAL, not source or semantic ground truth.
"""
import argparse
import collections
import fcntl
import hashlib
import json
import os
import pathlib
import re
import socket
import subprocess
import time

ROOT = pathlib.Path(__file__).resolve().parents[1]
WORK = ROOT / '.work/smallest-pass'
ALIASES = {
    'byte': 'unsigned char', 'sbyte': 'signed char', 'ushort': 'unsigned short',
    'uint': 'unsigned int', 'ulong': 'unsigned long', 'undefined': 'unsigned char',
    'undefined1': 'unsigned char', 'undefined2': 'unsigned short', 'undefined4': 'unsigned int',
    'undefined8': 'unsigned __int64', 'longlong': '__int64', 'ulonglong': 'unsigned __int64',
    'int8_t': 'signed char', 'int16_t': 'short', 'int32_t': 'int', 'int64_t': '__int64',
    'uint8_t': 'unsigned char', 'uint16_t': 'unsigned short', 'uint32_t': 'unsigned int',
    'uint64_t': 'unsigned __int64', 'uintptr_t': 'unsigned int',
    'LPSTR': 'char *', 'LPCSTR': 'const char *', 'DWORD': 'unsigned long',
    'WORD': 'unsigned short', 'BYTE': 'unsigned char', 'UINT': 'unsigned int',
    'BOOL': 'int', 'LONG': 'long', 'HRESULT': 'long', 'LPVOID': 'void *',
    'LPCVOID': 'const void *', 'LPDWORD': 'unsigned long *',
}

def digest(data):
    return hashlib.sha256(data).hexdigest()


def atomic_bytes(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.tmp')
    with temp.open('wb') as out:
        out.write(data)
        out.flush()
        os.fsync(out.fileno())
    os.replace(temp, path)
    fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def save(path, value):
    atomic_bytes(path, (json.dumps(value, indent=2) + '\n').encode())


def load(path):
    return json.loads(path.read_text())


def strip_comments(source):
    # Preserve quoted strings: a URL or printf string is not a comment.
    pattern = r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*'
    return re.sub(pattern, lambda m: ' ' if m[0].startswith(('/*', '//')) else m[0], source, flags=re.S)


def normalized(source):
    # Token identity, not whitespace erasure: string contents and adjacent
    # identifiers/operators must not accidentally compare equal.
    tokens = r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|\w+|>>=|<<=|\.\.\.|\+\+|--|->|::|<<|>>|<=|>=|==|!=|&&|\|\||[+*/%&|^=-]=|[^\s]'
    return tuple(re.findall(tokens, strip_comments(source)))


def is_placeholder(source):
    return bool(re.search(r'GEX_Target\([^{}]*\)\s*\{\s*(?:return(?:\s+(?:0|1))?\s*;)?\s*\}', strip_comments(source)))


class Rpc:
    def __init__(self):
        endpoint = os.environ.get('PC_DECOMP_SOCKET', '/run/user/1000/pc-decomp/gex.sock')
        self.socket = socket.socket(socket.AF_UNIX)
        self.socket.settimeout(120)
        self.socket.connect(endpoint)
        self.stream = self.socket.makefile('rb')
        self.serial = 0
        self.call('nexus.hello', {'serviceId': 'pc-decomp', 'protocolVersion': 1})
        self.call('decomp.negotiate', {'client': 'pc-decomp-cli', 'protocolMin': 1, 'protocolMax': 1})
        self.snapshot = self.call('decomp.snapshot', {'projectId': ''})
        self.scope = dict(projectId=self.snapshot['project']['id'], generation=self.snapshot['generation'])

    def close(self):
        self.stream.close()
        self.socket.close()

    def call(self, method, params):
        self.serial += 1
        ident = str(self.serial)
        self.socket.sendall((json.dumps(dict(jsonrpc='2.0', id=ident, method=method, params=params))+'\n').encode())
        while True:
            line = self.stream.readline(1024*1024+1)
            if not line or len(line) > 1024*1024:
                raise RuntimeError('Closed or oversized RPC response')
            value = json.loads(line)
            if value.get('id') != ident:
                continue
            if 'error' in value:
                raise RuntimeError(str(value['error']))
            return value['result']

    def detail(self, row):
        return self.call('decomp.detail', dict(self.scope, resource='functions', id=row['id']))['record']

    def inventory(self):
        rows, revision = [], ''
        while True:
            page = self.call('decomp.atlas', dict(self.scope, offset=len(rows), limit=512, revision=revision))
            if revision and revision != page['revision']:
                raise RuntimeError('Mixed inventory revisions')
            revision = page['revision']
            rows.extend(page['rows'])
            if len(rows) == page['total']:
                break
            if not page['rows'] or len(rows) > page['total']:
                raise RuntimeError('Invalid inventory pagination')
        if len({r['id'] for r in rows}) != len(rows):
            raise RuntimeError('Duplicate inventory identity')
        return rows


def syntax(path, ast=False):
    args = ['clang++', '-target', 'i686-pc-windows-msvc', '-std=c++98', '-fms-extensions',
            '-fsyntax-only', '-ferror-limit=8', '-Wno-everything']
    if ast:
        args.extend(['-Xclang', '-ast-dump=json'])
    args.append(str(path))
    result = subprocess.run(args, capture_output=True, text=True, timeout=30)
    errors = [s.split('error:', 1)[1].strip() for s in result.stderr.splitlines() if 'error:' in s]
    return result.returncode, errors, json.loads(result.stdout) if ast and not result.returncode else None


def declarations(ast):
    for node in ast.get('inner', []):
        if node.get('kind') == 'LinkageSpecDecl':
            yield from declarations(node)
        else:
            yield node


def primitive_type(value):
    for name, replacement in ALIASES.items():
        value = re.sub(r'\b'+name+r'\b', replacement, value)
    words = set(re.findall(r'[A-Za-z_]\w*', value))
    return words <= {'void', 'char', 'short', 'int', 'long', 'signed', 'unsigned',
                     '__int64', 'const', 'volatile', 'float', 'double', 'bool', '__cdecl'}


def build_catalog(manifest):
    path = WORK/'declaration-catalog-v2.json'
    if path.exists():
        return load(path)
    bindings = load(WORK/'project-snapshot.json')['symbolBindings']
    catalog = collections.defaultdict(list)
    # Reuse only primitive declarations, never infer a layout from a type name.
    # All candidates contain copied declarations; no header dependency is hidden.
    for address in manifest['originalSources']:
        source_path = WORK/'original-sources'/f'{address}.cpp'
        code, errors, ast = syntax(source_path, ast=True)
        if code:
            continue
        source = source_path.read_bytes()
        for node in declarations(ast):
            kind, name = node.get('kind'), node.get('name', '')
            if kind not in ('FunctionDecl', 'VarDecl') or '_'+name not in bindings:
                continue
            typ = node.get('type', {}).get('desugaredQualType', node.get('type', {}).get('qualType', ''))
            if not typ or not primitive_type(typ):
                continue
            if any(c.get('kind')=='CompoundStmt' for c in node.get('inner', [])):
                continue
            span = node['range']
            begin, end = span['begin'].get('offset'), span['end'].get('offset')
            if begin is None or end is None:
                continue
            declaration = source[begin:end+span['end']['tokLen']].decode().strip().rstrip(';')+';'
            if kind == 'VarDecl' and node.get('storageClass') != 'extern':
                continue
            canonical = typ
            for alias, replacement in ALIASES.items():
                canonical = re.sub(r'\b'+alias+r'\b', replacement, canonical)
                declaration = re.sub(r'\b'+alias+r'\b', replacement, declaration)
            catalog[name].append(dict(name=name, kind=kind, type=re.sub(r'\s+', '', canonical),
                declaration=declaration, binding=bindings['_'+name], origin=address))
    # Give decompiler function names access to already bound, declared callees.
    import_file = ROOT/'imports'/('ghidra-'+manifest['analysisEpoch']+'.json')
    imported = load(import_file)
    for f in imported['functions']:
        if f['name'] in catalog:
            continue
        entries = [items[0] for items in catalog.values() if items and items[0]['kind']=='FunctionDecl' and items[0]['binding']==f['entry']]
        types = {e['type'] for e in entries}
        if len(types) == 1:
            catalog[f['name']] = entries
    result = {name: items[0] for name, items in catalog.items() if len({i['type'] for i in items}) == 1}
    globals_path = WORK/'ghidra-globals.json'
    if globals_path.exists():
        globals_snapshot = load(globals_path)
        if globals_snapshot['count'] != globals_snapshot['total']:
            raise RuntimeError('Incomplete globals snapshot')
        by_address = collections.defaultdict(list)
        for symbol, address in bindings.items():
            if re.fullmatch(r'_[A-Za-z_]\w*', symbol):
                by_address[address.lower()].append(symbol[1:])
        for line in globals_snapshot['globals']:
            match = re.fullmatch(r'(.+) @ ([0-9a-f]{8}) \[Label\] \((.+)\) xrefs=\d+', line)
            if not match:
                continue
            name, address, typ = match.groups()
            name = re.sub(r'[^A-Za-z0-9_]', '_', name)
            if name in result or address not in by_address:
                continue
            entries = [result[n] for n in by_address[address] if n in result and result[n]['kind']=='VarDecl']
            if entries and len({e['type'] for e in entries}) == 1:
                result[name] = entries[0]
                continue
            if typ == 'string':
                typ = 'char[]'
            typ = typ.replace('*32', '*')
            for alias, replacement in ALIASES.items():
                typ = re.sub(r'\b'+alias+r'\b', replacement, typ)
            opaque_pointer = re.fullmatch(r'GXObject\s*(?:\*\s*)+', typ)
            if not primitive_type(typ) and not opaque_pointer:
                continue
            symbol = name if name in by_address[address] else sorted(by_address[address])[0]
            array = re.fullmatch(r'(.+?)(\[[0-9]*\])', typ)
            declaration = ('extern '+array[1]+' '+symbol+array[2]+';' if array else 'extern '+typ+' '+symbol+';')
            result[name] = dict(name=symbol, kind='VarDecl', type=typ, declaration=declaration,
                                binding=address, origin='Ghidra globals snapshot; inherited type, not verified source type')
    save(path, result)
    return result


def with_aliases(source):
    if re.search(r'\bGXObject\b', source) and not re.search(r'\bstruct\s+GXObject\b|\btypedef\b[^;]*\bGXObject\s*;', source):
        source = 'struct GXObject;\n'+source
    return ''.join(f'typedef {value} {name};\n' for name, value in ALIASES.items()
                   if re.search(r'\b'+name+r'\b', source) and
                   not re.search(r'\btypedef\b[^;]*\b'+name+r'\s*;', source)) + source


def repair_declarations(source, path, catalog):
    used = []
    for _ in range(8):
        source = with_aliases(source)
        atomic_bytes(path, source.encode())
        code, errors, _ = syntax(path)
        if not code:
            return source, used, []
        if not errors:
            errors = [f'Syntax inspector failed with exit {code}']
        changed = False
        for error in errors:
            match = re.search(r"use of undeclared identifier '([^']+)'", error)
            if not match or match[1] not in catalog or match[1] in used:
                continue
            entry = catalog[match[1]]
            source = re.sub(r'\b'+re.escape(match[1])+r'\b', entry['name'], source)
            source = 'extern "C" { '+entry['declaration']+' }\n'+source
            used.append(match[1])
            changed = True
        if not changed:
            return source, used, errors
    atomic_bytes(path, source.encode())
    return source, used, syntax(path)[1]


def function_range(source_path):
    code, errors, ast = syntax(source_path, ast=True)
    if code:
        raise ValueError('Existing syntax cannot be safely spliced: ' + '; '.join(errors))
    nodes = [n for n in declarations(ast) if n.get('kind') == 'FunctionDecl' and
             n.get('name') == 'GEX_Target' and any(c.get('kind') == 'CompoundStmt' for c in n.get('inner', []))]
    if len(nodes) != 1:
        raise ValueError('No unique GEX_Target definition')
    span = nodes[0]['range']
    return span['begin']['offset'], span['end']['offset'] + span['end']['tokLen']


def preflight(detail):
    if detail.get('ghidraPatchedBody') or detail.get('ghidraBytesEqualOriginal') is False:
        return 'Edited Ghidra body differs from pinned original; separate original-byte analysis requires approval.'
    if not detail.get('extentVerified'):
        return 'Unproven/noncontiguous instruction extent: ' + (detail.get('analysisWarning') or 'Ghidra and independent original listing do not establish a contiguous body.')
    instructions = re.findall(r'^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2}\s+)+\s*([^\n]+)', detail.get('originalAssembly', ''), re.M | re.I)
    if not instructions:
        return 'No independently decoded original instruction listing.'
    last = instructions[-1][1].strip().split()[0].lower()
    if last in ('call', 'calll'):
        return f'Declared body ends in a call at {detail["bodyEnd"]}; establish the callee noreturn contract before treating it as a complete standalone body. This may be valid termination, not a truncated function.'
    if last not in ('ret', 'retl', 'retw', 'jmp', 'jmpl', 'ljmp', 'int3', 'ud2'):
        return f'Declared body ends at {detail["bodyEnd"]} with {last}, leaving fall-through outside its extent; needs boundary/control-flow review, not a fabricated short implementation.'
    if detail.get('size') == 6 and last in ('jmp', 'jmpl') and '*' in instructions[-1][1]:
        return 'Six-byte indirect import thunk: linker-generated glue; standalone C++ function matching cannot reconstruct the import thunk/link stage.'
    return ''


def fresh_proposal(detail, previous, previous_path, bindings):
    raw = strip_comments(detail.get('ghidraPseudocode') or '').strip()
    if not raw or '{' not in raw:
        raise ValueError('No usable decompiler body')
    header = raw.split('{', 1)[0]
    names = re.findall(r'\b([A-Za-z_]\w*)\s*\(', header)
    if len(names) != 1:
        raise ValueError('Decompiler signature is not a simple standalone function')
    raw = re.sub(r'\b' + re.escape(names[0]) + r'\b', 'GEX_Target', raw)
    if re.search(r'__stdcall|__fastcall|__thiscall', header):
        raise ValueError('Entry uses non-cdecl ABI; the configured target symbol is _GEX_Target')
    if re.search(r'\b(unaff_\w*|extraout_\w*|in_[A-Z][A-Z0-9_]*|stack0x\w*)\b', raw):
        raise ValueError('Decompiler exposes unrecovered register/stack inputs: ' + ', '.join(sorted(set(re.findall(r'\b(?:unaff_\w*|extraout_\w*|in_[A-Z][A-Z0-9_]*|stack0x\w*)\b', raw)))[:8]))
    if '#' in raw or '??=' in raw or re.search(r'\b(__asm|_asm|asm|_emit|__DATE__|__TIME__|__TIMESTAMP__)\b', raw):
        raise ValueError('Decompiler text is outside the self-contained compiler-input allowlist')
    if previous:
        start, end = function_range(previous_path)
        # Only reuse an inherited spelling when the configured symbol map proves
        # both spellings designate the same address. No guessed field offsets.
        by_address = collections.defaultdict(set)
        for name in set(re.findall(r'\b[A-Za-z_]\w*\b', previous)):
            if '_'+name in bindings:
                by_address[bindings['_'+name].lower()].add(name)
        for name in set(re.findall(r'\b[A-Za-z_]\w*\b', raw)):
            binding = bindings.get('_'+name)
            if binding and name not in previous and len(by_address[binding.lower()]) == 1:
                replacement = next(iter(by_address[binding.lower()]))
                raw = re.sub(r'\b'+re.escape(name)+r'\b', replacement, raw)
        encoded = previous.encode()
        source = (encoded[:start] + raw.encode() + encoded[end:]).decode()
    else:
        source = 'extern "C" {\n' + raw + '\n}\n'
    aliases = ''.join(f'typedef {value} {name};\n' for name, value in ALIASES.items()
                      if re.search(r'\b'+name+r'\b', source) and
                      not re.search(r'\btypedef\b[^;]*\b'+name+r'\s*;', source))
    source = aliases + source
    if detail['size'] > 8 and is_placeholder(source):
        raise ValueError('Decompiler returned a placeholder-sized body for a nontrivial extent')
    return source


def difference(detail):
    proof = detail.get('match') or {}
    attempt = proof.get('verificationId')
    if not attempt:
        history = detail.get('attemptHistory') or []
        if history:
            last = history[-1]
            return {'attemptId': last['id'], 'reason': last.get('failureReason') or last.get('compileResult')}
        return {'reason': 'No retained byte comparison'}
    directory = ROOT / '.work/attempts' / attempt
    original, candidate = directory/'original.bin', directory/'resolved.bin'
    if not original.exists() or not candidate.exists():
        return {'attemptId': attempt, 'reason': 'Comparison artifacts unavailable'}
    a, b = original.read_bytes(), candidate.read_bytes()
    differences = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
    first = differences[0] if differences else min(len(a), len(b)) if len(a) != len(b) else None
    return dict(attemptId=attempt, originalSize=len(a), candidateSize=len(b),
                differingPositions=len(differences), firstDifference=first,
                originalWindow=a[first:first+16].hex() if first is not None else '',
                candidateWindow=b[first:first+16].hex() if first is not None else '',
                reason='Exact relocated bytes differ' if first is not None else 'Exact relocated bytes equal')


def capture(rpc):
    manifest_path = WORK/'manifest.json'
    if manifest_path.exists():
        return load(manifest_path)
    config = (ROOT/'project.json').read_bytes()
    inventory = rpc.inventory()
    rows = sorted((r for r in inventory if r['status'] != 'ExactMatch' and r.get('reconstructionEligible', True)), key=lambda r: (r['size'], r['address']))
    sources = {}
    for path in sorted((ROOT/'src/functions').glob('*.cpp')):
        data = path.read_bytes()
        sources[path.stem] = digest(data)
        atomic_bytes(WORK/'original-sources'/path.name, data)
    manifest = dict(schemaVersion=1, createdAt=time.time(), configHash=digest(config),
                    analysisEpoch=rpc.snapshot['health']['ghidra']['analysisEpoch'],
                    initialProgress=rpc.snapshot['progress'], originalSources=sources,
                    inventory=inventory, rows=rows)
    save(WORK/'project-snapshot.json', json.loads(config))
    save(manifest_path, manifest)
    return manifest


def install(address, data, state, state_path):
    path = ROOT/'src/functions'/f'{address}.cpp'
    current = digest(path.read_bytes()) if path.exists() else None
    if current != state['installedHash']:
        raise RuntimeError(f'{address}: external source edit; refusing overwrite')
    state['nextHash'] = digest(data) if data is not None else None
    state['installPending'] = True
    save(state_path, state)
    if data is None:
        if path.exists():
            path.unlink()
            fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
            try:
                os.fsync(fd)
            finally:
                os.close(fd)
    else:
        atomic_bytes(path, data)
    state['installedHash'] = state.pop('nextHash')
    state['installPending'] = False
    save(state_path, state)


def recover_install(address, state, state_path):
    if not state.get('installPending'):
        return
    path = ROOT/'src/functions'/f'{address}.cpp'
    current = digest(path.read_bytes()) if path.exists() else None
    if current == state['nextHash']:
        state['installedHash'] = state.pop('nextHash')
        state['installPending'] = False
        save(state_path, state)
    elif current != state['installedHash']:
        raise RuntimeError(f'{address}: external source mutation during interrupted install')


def verify(address, phase, manifest, state, state_path):
    config_hash = digest((ROOT/'project.json').read_bytes())
    if config_hash != manifest['configHash']:
        raise RuntimeError('Configuration changed during pass')
    key = digest((state['installedHash']+'|'+config_hash+'|'+manifest['analysisEpoch']).encode())[:24]
    command = f'smallest-{address}-{key}-{phase}'
    state['pendingCommand'] = command
    save(state_path, state)
    log = WORK/'responses'/f'{command}.txt'
    log.parent.mkdir(exist_ok=True)
    # Reusing an ID queries only. A timeout/failure stops the pass, never invents
    # another ID to get past an uncertain operation.
    with log.open('w') as out:
        result = subprocess.run([ROOT/'scripts/verify', address, command], stdout=out, stderr=subprocess.STDOUT)
    if result.returncode not in (0, 2):
        raise RuntimeError(f'{address}: verify exit {result.returncode}; resolve {command}; see {log}')
    text = log.read_text()
    reply = json.loads(text[text.index('\n{')+1:])
    attempt = reply['task']['result']
    record = dict(commandId=command, attemptId=attempt['id'],
        sourceHash=attempt['sourceRevision'], result=attempt['compileResult'], score=attempt['bestScore'],
        exact=attempt['match']['verifiedExact'], failure=attempt['failureReason'], phase=phase)
    recorded = next((a for a in state.setdefault('attempts', []) if a['attemptId'] == attempt['id']), None)
    if recorded is not None and recorded != record:
        raise RuntimeError('Previously recorded attempt changed')
    if recorded is None:
        state['attempts'].append(record)
    state['pendingCommand'] = None
    save(state_path, state)
    return record


def process(row, manifest, rpc):
    # Ownership can change after a frozen pass manifest was captured. Never
    # silently overwrite/restore source for a newly excluded dependency.
    if rpc.detail(row).get('reconstructionEligible') is False:
        raise RuntimeError('Confirmed library/import ownership; reconstruction excluded. Existing checkpoint retained.')
    address = row['address']
    state_path = WORK/'results'/f'{address}.json'
    if state_path.exists():
        state = load(state_path)
    else:
        state = dict(address=address, name=row['name'], size=row['size'], initialStatus=row['status'],
                     installedHash=manifest['originalSources'].get(address), phase='new', attempts=[])
        save(state_path, state)
    recover_install(address, state, state_path)
    source_path = ROOT/'src/functions'/f'{address}.cpp'
    current = digest(source_path.read_bytes()) if source_path.exists() else None
    if current != state['installedHash']:
        raise RuntimeError(f'{address}: external source edit/removal')
    if state['phase'] == 'done':
        return state
    previous_path = WORK/'original-sources'/f'{address}.cpp'
    previous = previous_path.read_text() if previous_path.exists() else ''
    detail_path = WORK/'details-before'/f'{address}.json'
    if not detail_path.exists():
        try:
            save(detail_path, rpc.detail(row))
        except RuntimeError as error:
            if 'Reply exceeds 900 KiB' not in str(error):
                raise
            state.update(phase='done', outcome='analysis-blocked',
                         blocker='Backend detail exceeds its 900 KiB transport budget for this enclosing span; needs bounded artifact/extent access. No source or exact proof inferred.')
            save(state_path, state)
            return state
    detail = load(detail_path)
    state['previousComparison'] = difference(detail)
    if state['phase'] == 'new':
        blocker = preflight(detail)
        if blocker:
            state.update(phase='done', outcome='analysis-blocked', blocker=blocker)
            save(state_path, state)
            return state
        candidate = WORK/'candidates'/f'{address}.cpp'
        override = WORK/'reviewed'/f'{address}.cpp'
        try:
            proposal = override.read_text() if override.exists() else fresh_proposal(
                detail, previous, previous_path, load(WORK/'project-snapshot.json')['symbolBindings'])
        except ValueError as error:
            state.update(phase='done', outcome='reconstruction-blocked', blocker=str(error))
            save(state_path, state)
            return state
        atomic_bytes(candidate, proposal.encode())
        state['proposalKind'] = 'agent-reviewed' if override.exists() else 'fresh-decompiler-with-existing-declarations'
        if previous and normalized(proposal) == normalized(previous):
            state.update(phase='done', outcome='unchanged-retained',
                         blocker='Fresh proposal is identical to existing candidate; retained its recorded mismatch rather than manufacture a new attempt.')
            save(state_path, state)
            return state
        proposal, reused, errors = repair_declarations(proposal, candidate, build_catalog(manifest))
        state['reusedDeclarations'] = reused
        state['candidateHash'] = digest(proposal.encode())
        if errors:
            state.update(phase='done', outcome='reconstruction-blocked',
                         blocker='Fresh proposal requires explicit types/declarations or syntax reconstruction: ' + '; '.join(errors))
            save(state_path, state)
            return state
        state['phase'] = 'prepared'
        save(state_path, state)
    candidate = WORK/'candidates'/f'{address}.cpp'
    data = candidate.read_bytes()
    if digest(data) != state['candidateHash']:
        raise RuntimeError(f'{address}: staged proposal changed after checkpoint')
    if state['phase'] == 'prepared':
        install(address, data, state, state_path)
        state['phase'] = 'installed'
        save(state_path, state)
    if state['phase'] == 'installed':
        trial = verify(address, 'trial', manifest, state, state_path)
        state['trial'] = trial
        state['phase'] = 'compared'
        save(state_path, state)
    trial = state['trial']
    if state['phase'] == 'compared':
        old_history = detail.get('attemptHistory') or []
        old_score = old_history[-1]['bestScore'] if old_history else -1
        compiled = trial['result'] in ('ExactMatch', 'Compiled; bytes differ')
        # Score is only a byte-layout heuristic for choosing a retained candidate,
        # never a claim of semantic improvement. Original source remains archived.
        tiny = is_placeholder(data.decode())
        keep = trial['exact'] or (compiled and not tiny and (not previous or trial['score'] > old_score))
        if keep:
            state.update(phase='done', outcome='exact' if trial['exact'] else 'candidate-retained',
                         blocker='' if trial['exact'] else 'Compiler-generated relocated bytes still differ; candidate retained for review, not a semantic proof.')
        else:
            state['phase'] = 'restoring'
        save(state_path, state)
    if state['phase'] == 'restoring':
        original = previous_path.read_bytes() if previous_path.exists() else None
        install(address, original, state, state_path)
        state['phase'] = 'restored'
        save(state_path, state)
    if state['phase'] == 'restored':
        if previous:
            verify(address, 'restore', manifest, state, state_path)
        state.update(phase='done', outcome='previous-retained' if previous else 'compiler-blocked',
                     blocker=trial['failure'] or 'Fresh candidate did not improve positional byte comparison; previous source restored unchanged.')
        save(state_path, state)
    if state['phase'] == 'done':
        after = rpc.detail(row)
        save(WORK/'details-after'/f'{address}.json', after)
        state['currentComparison'] = difference(after)
        save(state_path, state)
    return state


def report(manifest):
    rows = [load(WORK/'results'/f'{r["address"]}.json') for r in manifest['rows']
            if (WORK/'results'/f'{r["address"]}.json').exists()]
    done = [r for r in rows if r['phase'] == 'done']
    summary = dict(total=len(manifest['rows']), completed=len(done),
                   outcomes=dict(collections.Counter(r['outcome'] for r in done)),
                   newExactBytes=sum(r['size'] for r in done if r['outcome']=='exact'),
                   newTrialAttempts=sum(any(a['phase']=='trial' for a in r['attempts']) for r in rows),
                   restoreAttempts=sum(any(a['phase']=='restore' for a in r['attempts']) for r in rows))
    save(WORK/'report.json', dict(summary=summary, rows=rows))
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=['snapshot', 'run', 'report', 'reprepare'])
    parser.add_argument('--addresses', help='Explicit comma-separated unattempted syntax-blocked entries to reconsider after declaration support improves')
    parser.add_argument('--limit', type=int, help='Stop safely after this many total completed entries')
    args = parser.parse_args()
    WORK.mkdir(parents=True, exist_ok=True)
    with (WORK/'runner.lock').open('w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        if args.action == 'report':
            print(json.dumps(report(load(WORK/'manifest.json')), indent=2))
            return
        rpc = Rpc()
        try:
            manifest = capture(rpc)
            if digest((ROOT/'project.json').read_bytes()) != manifest['configHash']:
                raise RuntimeError('Configuration changed since snapshot; do not run this checkpoint against another build environment')
            if rpc.snapshot['health']['ghidra']['analysisEpoch'] != manifest['analysisEpoch']:
                raise RuntimeError('Analysis epoch changed since snapshot')
            if args.action == 'reprepare':
                if not args.addresses:
                    raise RuntimeError('Explicit addresses required; never reset the whole pass')
                for address in args.addresses.split(','):
                    if not re.fullmatch('[0-9a-f]{8}', address):
                        raise RuntimeError('Invalid address')
                    path = WORK/'results'/f'{address}.json'
                    state = load(path)
                    if state['phase'] != 'done' or state['outcome'] != 'reconstruction-blocked' or state['attempts']:
                        raise RuntimeError('Reprepare is only for unattempted reconstruction blockers')
                    state.setdefault('preparationHistory', []).append({k: state.get(k) for k in
                        ('outcome', 'blocker', 'candidateHash', 'reusedDeclarations')})
                    state['phase'] = 'new'
                    save(path, state)
                return
            if args.action == 'snapshot':
                print(json.dumps(dict(remaining=len(manifest['rows']), initialProgress=manifest['initialProgress']), indent=2))
                return
            for index, row in enumerate(manifest['rows'], 1):
                if args.limit is not None and index > args.limit:
                    break
                if (WORK/'pause').exists():
                    print('Paused between functions.', flush=True)
                    break
                if digest((ROOT/'project.json').read_bytes()) != manifest['configHash']:
                    raise RuntimeError('Configuration changed during pass')
                state = process(row, manifest, rpc)
                print(f'{index}/{len(manifest["rows"])} {row["address"]} {row["size"]} bytes: {state["outcome"]}', flush=True)
                if index % 25 == 0:
                    print(json.dumps(report(manifest)), flush=True)
            print(json.dumps(report(manifest), indent=2), flush=True)
        finally:
            rpc.close()
