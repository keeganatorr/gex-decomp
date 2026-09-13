// CRT short argument reader: advances the va-list slot by four bytes and
// writes only AX on return. A short return type avoids inventing a meaningful
// upper half of EAX from Ghidra's CONCAT22 register-bookkeeping expression.
extern "C" unsigned short __cdecl GEX_Target(unsigned short **cursor)
{
    unsigned short *slot = *cursor;
    *cursor = slot + 2;
    return *slot;
}
