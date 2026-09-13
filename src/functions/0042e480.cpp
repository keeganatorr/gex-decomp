// Adapted from pc_decomp_backup/src/functions/FUN_0042E480.cpp
// Historical source SHA256: 6ba2a771c032c37534e27b45e2af3f68a8f2e92efeb5514fc61dc79d96c67a5c
extern "C" {
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419B80(void**, unsigned int);
extern "C" { extern int DAT_004A2AD4; }
extern "C" { extern void** DAT_004A27FC; }
extern "C" void __cdecl GEX_Target(int param1, int param2, unsigned int param3, int param4, unsigned int param5) {
    void** ppGVar1 = (void**)FUN_004195D0(0x5c, param1, param2, DAT_004A2AD4);
    if (ppGVar1 != 0) {
        ppGVar1[0x1b] = (void*)((unsigned int)ppGVar1[0x1b] | param3 | 0xc000);
        ppGVar1[0x21] = (void*)0x7fff0000;
        ppGVar1[0x20] = (void*)((-(unsigned int)((param3 & 0x80000000) == 0) & 0x20000) - 0x10000);
        ppGVar1[0x22] = 0;
        ppGVar1[0x24] = (void*)0x7fff0000;
        ppGVar1[0x23] = (void*)0xffff8000;
        ppGVar1[0x25] = 0;
        ppGVar1[0x31] = (void*)param4;
        ppGVar1[0x14] = (void*)0x18;
        ppGVar1[0x26] = (void*)3;
        ppGVar1[0x1c] = (void*)0x30;
        FUN_00419B80(ppGVar1, param5);
        if (((unsigned int)DAT_004A27FC[0x38] & 0x40) != 0) {
            ppGVar1[0x38] = (void*)((unsigned int)ppGVar1[0x38] | 0x40);
        }
    }
}
}
