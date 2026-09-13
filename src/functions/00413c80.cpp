// Adapted from pc_decomp_backup/src/functions/FUN_00413C80.cpp
// Historical source SHA256: 129f37892d98cca373870534da7485fe4472fa87334fd5e052162eb088534195
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
extern "C" int __cdecl FUN_004206b0(int);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00413BE0(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a27f8; }
extern "C" { extern int DAT_004a0218; }
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x1c] = (void*)0x54;
    param1[0x15] = (void*)0x54;
    param1[0x14] = (void*)0x2e;
    param1[0x26] = 0; param1[0x20] = 0; param1[0x22] = 0; param1[0x31] = 0;
    DAT_004a27f8 = 1;
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    FUN_0042E480((int)param1[0x1e], (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    FUN_0042E480((int)param1[0x1e], (int)param1[0x1f], ((unsigned int)param1[0x1b] & 0x80000000) ^ 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    int iVar1 = FUN_004206b0(0x14);
    if (iVar1 == 0) DAT_004a0218 = 0x69;
    FUN_00420960(param1);
    FUN_00413BE0(param1);
}
}
