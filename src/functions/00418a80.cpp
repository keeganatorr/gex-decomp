typedef unsigned char byte;
// SCRIPT_ShiftRight: SAR proves the work-register operation is signed.
// x86 masks the byte-sized count to five bits; the cursor advances one byte.
extern "C" {
extern int DAT_0049fb90;
unsigned char *__cdecl GEX_Target(unsigned char *cursor)
{
    DAT_0049fb90 >>= *cursor++ & 31;
    return cursor;
}
}
