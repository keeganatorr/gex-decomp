// Adapted from pc_decomp_backup/src/functions/FUN_00430C50.cpp
// Historical source SHA256: caada54602dece30ae551bb0d8bac1f60deaa715c54ba395aac79850215d1628
extern "C" {
extern "C" {
    void __cdecl FUN_00417B70(void);
    int __cdecl FUN_00430B40(void);
    void __cdecl FUN_00405390(const char*);
    extern int FUN_004A27FC;
    extern int DAT_00455C54;
    extern int DAT_00463D78;
    extern int DAT_0049FB98;
    extern int DAT_00463F08;
    extern int DAT_00463F00;
    extern int DAT_00463F0C;
    extern int DAT_00463F04;
    extern int DAT_004A023C;
    extern const char* DAT_0045B140;
}

extern "C" void __cdecl GEX_Target(void** param_1, int* param_2)
{
    if (*param_2 == 0 || param_1[0x28] != 0 || param_1[0x26] != (void*)0x40) {
        if (*param_2 != 0 && param_1[0x28] == 0 &&
            (((unsigned int)param_1[0x1b] >> 8 & 0xf) == 4 &&
             param_1[0x5e] == (void*)FUN_004A27FC)) {
            FUN_00417B70();
        }
    } else {
        unsigned int uVar3 = (unsigned int)param_1[0x5c] & 0xffff;
        unsigned int uVar1 = ((unsigned int)param_1[0x5e] & 0xf00) >> 8;
        if (uVar3 == 5) {
            int iVar2 = FUN_00430B40();
            if (iVar2 != 0) FUN_00417B70();
            DAT_00463F08 = 0;
            DAT_00463F00 = 0;
            DAT_00463F0C = 0;
            DAT_00463F04 = 0;
            return;
        }
        if (uVar1 == 2 && DAT_004A023C == 0 &&
            (((unsigned int)param_1[0x5d] & 0xffff) == uVar3 || uVar3 == 1)) {
            if (DAT_00455C54 > 1) FUN_00405390(DAT_0045B140);
            FUN_00417B70();
            return;
        }
        if (uVar1 == 5 && (int)param_1[0x2e] < 1) {
            DAT_0049FB98 = DAT_00463D78;
            return;
        }
    }
}
}
