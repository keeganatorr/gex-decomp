// Adapted from pc_decomp_backup/src/functions/FUN_0043B3C0.cpp
// Historical source SHA256: 72e7510b69d1fc48a103a84a7079f0e0fe4a65b37a1afcc702befa07ee9883e2
extern "C" {
extern "C" { extern void** PTR_00464e14; }
extern "C" { extern void** PTR_00464e08; }
extern "C" { extern void** PTR_00464e10; }
extern "C" { extern int DAT_00464dc0; }
extern "C" { extern int DAT_00464e04; }
extern "C" { extern int DAT_00464dcc; }
extern "C" { extern int DAT_00464e24; }
extern "C" { extern int DAT_00464ddc; }
extern "C" { extern int DAT_00464dc8; }
extern "C" { extern int DAT_00464e20; }
extern "C" { extern int DAT_00464e1c; }
extern "C" { extern int DAT_00464dd4; }
extern "C" { extern int DAT_00464dd8; }
extern "C" { extern int DAT_00464dbc; }
extern "C" { extern int DAT_00464dc4; }
extern "C" { extern int DAT_0046002c; }
extern "C" { extern int DAT_00460030; }
extern "C" { extern int DAT_00464e0c; }
extern "C" { extern int DAT_00464e00; }
extern "C" { extern int DAT_00464e18; }
extern "C" { extern int DAT_00464de0; }
extern "C" { extern int DAT_00460028; }
extern "C" { extern int DAT_00464db8; }
extern "C" void** FUN_004195D0(int, int, int, int);
extern "C" void FUN_00419BE0(void**, void**);
extern "C" void FUN_00419B80(void**, int);
extern "C" void FUN_004335F0(void**, int);

extern "C" void __cdecl GEX_Target(void** param_1, int param_2)
{
    if (param_1[0x26] == (void*)0x40) {
        if (param_2 == 0) {
            param_1[0x34] = (void*)0x30000000;
            param_1[0x14] = 0;
            param_1[0x15] = 0;
            PTR_00464e14 = FUN_004195D0(
                0x102,
                (int)param_1[0x1e],
                (int)param_1[0x1f],
                (int)param_1[3]);
            if (PTR_00464e14 != 0) {
                PTR_00464e14[0x14] = 0;
                PTR_00464e14[0x15] = 0;
                PTR_00464e14[0x17] = 0;
                param_1[0x18] = 0;
                param_1[0x19] = 0;
                PTR_00464e14[0x34] = (void*)0x30000000;
            }
            if ((PTR_00464e08 != 0) && (PTR_00464e14 != 0)) {
                FUN_00419BE0(PTR_00464e08, PTR_00464e14);
            }
            DAT_00464dc0 = 0;
            DAT_00464e04 = 0;
            DAT_00464dcc = 0;
            DAT_00464e24 = 0;
            DAT_00464ddc = 0;
            DAT_00464dc8 = 0;
            DAT_00464e20 = 0;
            DAT_00464e1c = 0;
            DAT_00464dd4 = 0;
            DAT_00464dd8 = 0;
            DAT_00464dbc = 0;
            DAT_00464dc4 = 0;
            DAT_0046002c = 0;
            DAT_00460030 = 0;
            DAT_00464e0c = 0;
            DAT_00464e00 = 0;
            DAT_00464e18 = 0;
            DAT_00464de0 = 0;
            DAT_00460028 = 0x180000;
            DAT_00464db8 = 0;
            FUN_00419B80(param_1, 0);
            PTR_00464e10 = 0;
        } else {
            PTR_00464e14 = 0;
        }
    }
    if (param_2 == 0) {
        FUN_004335F0(param_1, 0);
    }
}
}
