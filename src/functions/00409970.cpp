extern "C" {
extern int DAT_004a288c;
extern int DAT_004a2994;
extern int DAT_004a2950;
void __cdecl FUN_0043f070(void);
void __cdecl FUN_0043eed0(void);
void __cdecl FUN_0043f080(int);
void __cdecl GEX_Target(void)
{
    if (!DAT_004a288c) {
        if (DAT_004a2994 != 1)
            FUN_0043f080(DAT_004a2950);
        else {
            FUN_0043eed0();
            FUN_0043f080(DAT_004a2950);
        }
    } else
        FUN_0043f070();
}
}
