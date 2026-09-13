// Adapted from pc_decomp_backup/src/functions/FUN_00425DA0.cpp
// Historical source SHA256: 3d7e9d553a3a391ec6a9152b3be91056589fef56534a296fb0062d1e160721f7
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00423C80(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
extern "C" void __cdecl FUN_0041FA80(int);
extern "C" void __cdecl FUN_00425CF0(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a27f8; }
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x15] = 0; param1[0x23] = 0; param1[0x26] = 0;
    param1[0x1c] = (void*)0x55;
    param1[0x14] = (void*)0x2f;
    param1[0x21] = (void*)0x90000;
    FUN_00423C80(param1);
    param1[0x20] = 0; param1[0x22] = 0;
    DAT_004a27f8 = 1;
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    FUN_0042E480((int)param1[0x1e] + 0x500, (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    FUN_0042E480((int)param1[0x1e] - 0x500, (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    FUN_0041FA80(0xf);
    FUN_00425CF0(param1);
}
}
