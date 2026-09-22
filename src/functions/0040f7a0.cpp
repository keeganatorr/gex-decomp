extern "C" {
unsigned int __cdecl INPUT_GetActiveKeys_00404ba0(int);
extern unsigned int MainGame_NextKeyInput;
extern unsigned int MainGame_KeyInput;

int __cdecl GEX_Target(int param_1, unsigned int param_2, unsigned int *CurrentInputPTR)
{
    unsigned int KeyInput = INPUT_GetActiveKeys_00404ba0(0);
    MainGame_NextKeyInput = 0;
    if (KeyInput & 0x1000u)
        MainGame_NextKeyInput = 0x40000000u;
    if (KeyInput & 0x4000u)
        MainGame_NextKeyInput |= 0x80000000u;
    if (KeyInput & 0x8000u)
        MainGame_NextKeyInput |= 0x10000000u;
    if (KeyInput & 0x2000u)
        MainGame_NextKeyInput |= 0x20000000u;
    if (KeyInput & 0x80u)
        MainGame_NextKeyInput |= 0x08000000u;
    if (KeyInput & 0x40u)
        MainGame_NextKeyInput |= 0x04000000u;
    if (KeyInput & 0x10u)
        MainGame_NextKeyInput |= 0x00100000u;
    if (KeyInput & 0x20u)
        MainGame_NextKeyInput |= 0x02000000u;
    if (KeyInput & 0x800u)
        MainGame_NextKeyInput |= 0x01000000u;
    if (KeyInput & 0x100u)
        MainGame_NextKeyInput |= 0x00800000u;
    if (KeyInput & 8u)
        MainGame_NextKeyInput |= 0x00400000u;
    if (KeyInput & 4u)
        MainGame_NextKeyInput |= 0x00200000u;
    if (KeyInput & 2u)
        MainGame_NextKeyInput |= 0x00080000u;
    if (KeyInput & 1u)
        MainGame_NextKeyInput |= 0x00040000u;
    MainGame_KeyInput |= MainGame_NextKeyInput;
    if (param_1 > 1) {
        *CurrentInputPTR = 0;
        return 1;
    }
    *CurrentInputPTR = MainGame_NextKeyInput;
    return 1;
}
}
