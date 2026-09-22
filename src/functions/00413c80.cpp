extern "C" {
void __cdecl FUN_00420BC0(void**);
int __cdecl FUN_00421560_DrawCharacter(int, void**);
void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
int __cdecl FUN_004206b0(int);
void __cdecl FUN_00420960(void**);
void __cdecl FUN_00413BE0(void**);
extern int FUN_004A2990;
extern int DAT_004a27f8;
extern int DAT_004a0218;

void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x1c] = (void*)3;
    param1[0x15] = (void*)3;
    param1[0x14] = (void*)0x2e;
    param1[0x26] = 0;
    param1[0x20] = 0;
    param1[0x22] = 0;
    param1[0x31] = 0;
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
