// Adapted from pc_decomp_backup/src/functions/FUN_004263B0.cpp
// Historical source SHA256: 53c350e51231b6758aa436cabf5fdd9479ef5945193077acb7304491c5c92a4d
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00423C80(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
extern "C" void __cdecl FUN_00426330(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a27f8; }
extern "C" { extern unsigned char DAT_004a0280; }
extern "C" { extern unsigned char DAT_004a0282; }

extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x1c] = (void*)0x55;
    param1[0x14] = (void*)0x28;
    param1[0x23] = (void*)0;
    param1[0x15] = (void*)5;
    param1[0x21] = (void*)0x90000;
    param1[0x26] = (void*)3;
    FUN_00423C80(param1);
    if (DAT_004a0280 == 0 && DAT_004a0282 == 0) {
        param1[0x20] = (void*)0;
        param1[0x22] = (void*)0;
    }
    DAT_004a27f8 = 1;
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    FUN_0042E480((int)((char*)param1[0x1e] + 0x500), (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    FUN_0042E480((int)((char*)param1[0x1e] - 0x500), (int)param1[0x1f], (unsigned int)param1[0x1b] & 0x80000000, (int)param1[0x31], (unsigned int)param1[0x1b] & 0xf);
    FUN_00426330(param1);
}
}
