typedef unsigned char byte;
// SCRIPT_ShiftRight: SAR proves the work-register operation is signed.
// This legacy expression is defined in C++ for counts below 32. The verified
// x86 SAR instruction masks CL for all byte values; do not assume that on another target.
extern "C" {
extern int DAT_0049fb90;
unsigned char *__cdecl GEX_Target(unsigned char *cursor)
{
    DAT_0049fb90 >>= *cursor++;
    return cursor;
}
}
