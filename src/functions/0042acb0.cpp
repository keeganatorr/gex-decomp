extern "C" {
extern "C" void __cdecl FUN_00444590(void**);
}
extern "C" void __cdecl GEX_Target(int* param_1)
{
    FUN_00444590((void**)param_1);
    if (param_1[0x15] != -1) {
        int pGVar1 = param_1[0x29] + param_1[0x2a];
        param_1[0x2a] = pGVar1;
        param_1[0x15] = param_1[0x15] + (pGVar1 >> 16);
        if ((pGVar1 & ~0xffff) > 0x10000) {
            param_1[0x2a] = 0;
        }
    }
}
