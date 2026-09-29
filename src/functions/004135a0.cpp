// Adapted from pc_decomp_backup/src/functions/FUN_004135A0.cpp
// Historical source SHA256: 4da23164b6655b6b9b5a6d077b07580f5253e967182efc486153399d89fdea80
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_004218A0(void**);
extern "C" int __cdecl FUN_004206B0(int);
extern "C" void __cdecl FUN_004134B0(void**);
extern "C" { extern int DAT_004A0218; }

extern "C" void __cdecl InitPlayerSideSlap_004135a0(void** param_1)
{
    int iVar2;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x4b;
    param_1[0x26] = (void*)0;
    iVar2 = FUN_004218A0(param_1);
    param_1[0x27] = (void*)iVar2;
    param_1[0x14] = (void*)0x4b;
    param_1[0x15] = (void*)0;
    iVar2 = FUN_004206B0(0x47);
    if (iVar2 == 0) {
        DAT_004A0218 = 0x66;
    }
    FUN_004134B0(param_1);
}
}
