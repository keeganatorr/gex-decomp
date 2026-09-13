// Adapted from pc_decomp_backup/src/functions/FUN_00425C10.cpp
// Historical source SHA256: 0a798c63b9e69feeaaf77372ba1b26f28f23efe9776d88d228aaf8f0a825b213
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00423C80(void**);
extern "C" void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_00425B60(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a27f8; }
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x23] = 0; param1[0x20] = 0; param1[0x22] = 0;
    param1[0x1c] = (void*)0x55;
    param1[0x21] = (void*)0x90000;
    param1[0x26] = 0;
    FUN_00423C80(param1);
    DAT_004a27f8 = 1;
    if (param1[0x14] == (void*)0x27) {
        FUN_0042E480((int)param1[0x1e] + 0x500, (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
        FUN_0042E480((int)param1[0x1e] - 0x500, (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    }
    param1[0x14] = (void*)0x27;
    param1[0x15] = (void*)6;
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    FUN_00425B60(param1);
}
}
