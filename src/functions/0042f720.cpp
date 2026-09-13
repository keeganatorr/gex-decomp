// Adapted from pc_decomp_backup/src/functions/FUN_0042F720.cpp
// Historical source SHA256: 55486fda188fab8398e88fa7787b9ff44843c396cf0cb9fef84e80b6bc68fdfd
extern "C" {
extern "C" { extern void* PTR_00463D7C; }
extern "C" { extern unsigned char DAT_0049FB98; }
extern "C" { extern int DAT_0049FCC0[8]; }
extern "C" { extern int DAT_0049FCE0[8]; }
extern "C" int __cdecl FUN_00419C00(void*, int, int, int*, int*);
extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_0042F6E0(void);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int xPos;
    int yPos;
    int iVar1;
    void* ppGVar2;
    int* puVar3;
    int* ppGVar4;
    int j;

    iVar1 = FUN_00419C00(param_1, 0, 0, &xPos, &yPos);
    if (iVar1 != 0) {
        xPos = *(int*)((char*)param_1 + 0x78) + xPos - 0x1c;
        yPos = *(int*)((char*)param_1 + 0x7c) + yPos - 0x1c;
        ppGVar2 = FUN_004195D0(0xe5, xPos, yPos, *(int*)((char*)param_1 + 0xc));
        if (ppGVar2 != 0) {
            PTR_00463D7C = ppGVar2;
            *(int*)((char*)ppGVar2 + 0x50) = 0xe;
            *(int*)((char*)ppGVar2 + 0x54) = 0;
            *(int*)((char*)ppGVar2 + 0x5c) = (int)FUN_0042F6E0;
            if (DAT_0049FB98 == 6) {
                puVar3 = DAT_0049FCC0;
            } else {
                puVar3 = DAT_0049FCE0;
            }
            ppGVar4 = (int*)((char*)ppGVar2 + 0x10);
            for (j = 0; j < 8; j++) {
                ppGVar4[j] = puVar3[j];
            }
            *(int*)((char*)ppGVar2 + 0x6c) = *(int*)((char*)param_1 + 0x6c);
            *(int*)((char*)ppGVar2 + 0xd0) = 0x30000000;
            *(int*)((char*)ppGVar2 + 0xe0) |= 0x40;
        }
    }
}
}
