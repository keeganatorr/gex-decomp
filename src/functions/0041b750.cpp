extern "C" {
extern void __cdecl FUN_00419B80(int, int);
extern int DAT_004593B8;
void __cdecl FUN_0041B750(int value, int ignored)
{
    FUN_00419B80(value, 9);
    DAT_004593B8 = value;
}
}
