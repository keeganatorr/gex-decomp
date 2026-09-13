// Adapted from pc_decomp_backup/src/functions/FUN_0042ACB0.cpp
// Historical source SHA256: 0acbd29afad539caae7f690bd810e15c3c6a0fc9c45e1a74c71cab7ad37a812f
extern "C" {
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int pGVar1;

    FUN_00444590((void**)param_1);
    if (param_1[0x15] != -1) {
        pGVar1 = param_1[0x29] + param_1[0x2a];
        param_1[0x2a] = pGVar1;
        param_1[0x15] = param_1[0x15] + (pGVar1 >> 16);
        if ((pGVar1 & 0xffff0000) > 0x10000) {
            param_1[0x2a] = 0;
        }
    }
}
}
