// Adapted from pc_decomp_backup/src/functions/FUN_00426620.cpp
// Historical source SHA256: 511adda138adef40f5052274fae094cb2b5de5d140d2c92169aa443becc2f860
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004264C0(void**);
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" { extern unsigned char DAT_004A0283; }

extern "C" { extern int DAT_00463AAC; }
extern "C" { extern int DAT_00463AA8; }

extern "C" void __cdecl InitPlayerFaceTurn_00426620(void** param_1)
{
    FUN_00420BC0(param_1);
    DAT_00463AAC = (int)param_1[0x31];
    param_1[0x1c] = (void*)0x32; 
    param_1[0x26] = 0;
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0
        && DAT_004A0282 == 0 && DAT_004A0283 == 0) {
        DAT_00463AA8 = ((int)param_1[0x31] + 0x200000) & 0xff0000;
    }
    FUN_004264C0(param_1);
}
}
