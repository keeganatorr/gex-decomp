// Adapted from pc_decomp_backup/src/functions/FUN_0042E5E0.cpp
// Historical source SHA256: b06ee840d238761ae3467ea6ad3c4bbaadbd5a4efd63c4ee63ad1215e1cb9ab5
extern "C" {
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419B80(void*, int);
extern "C" { extern int DAT_004a2ad4; }
extern "C" { extern int DAT_0045b08c; }
extern "C" { extern int DAT_0045b090; }
extern "C" void __cdecl GEX_Target(int param1, int param2, int param3) {
    void** ppGVar1 = (void**)FUN_004195D0(0x5c, param2, param3, DAT_004a2ad4);
    if (ppGVar1) {
        ppGVar1[0x14] = (void*)0x19;
        ppGVar1[0x1c] = (void*)((unsigned int)ppGVar1[0x1c] | 0x46);
        ppGVar1[0x2a] = (void*)DAT_0045b08c;
        ppGVar1[0x2c] = (void*)DAT_0045b08c;
        ppGVar1[0x2e] = (void*)DAT_0045b090;
        FUN_00419B80(ppGVar1, 8);
        if ((*(unsigned int*)(param1 + 0xe0) & 0x40) != 0) {
            ppGVar1[0x38] = (void*)((unsigned int)ppGVar1[0x38] | 0x40);
        }
    }
}
}
