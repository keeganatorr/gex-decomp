// Adapted from pc_decomp_backup/src/functions/FUN_0043D570.cpp
// Historical source SHA256: 229a9799de5f020c77b1e4e1867dc7c0297c0b61a4db27a986a559c0652ab9b9
extern "C" {
extern "C" void __cdecl FUN_00419840(void**);
extern "C" unsigned int __cdecl FUN_0040F1D0(void*, void**);
extern "C" void __cdecl FUN_004335F0(void**, int);

extern "C" { extern int FUN_004A27D4; }
extern "C" { extern void* FUN_00456ADC; }
extern "C" { extern void* DAT_004a280c_xPos; }
extern "C" { extern void* DAT_004a2810_yPos; }
extern "C" { extern void* DAT_004a282c_startxPos; }
extern "C" { extern void* DAT_004a2830_startypos; }
extern "C" { extern int FUN_00456AE0; }
extern "C" { extern void* FUN_004A2990; }
extern "C" { extern void* FUN_00456AEC; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;

    if (FUN_004A27D4 != 0) {
        if (param_1[0x2d] == FUN_00456ADC) {
            DAT_004a280c_xPos = param_1[0x1e];
            DAT_004a2810_yPos = param_1[0x1f];
            DAT_004a282c_startxPos = param_1[0x1e];
            param_1[0x1f] = (void*)((int)param_1[0x1f] + 0x200000);
            DAT_004a2830_startypos = param_1[0x1f];
            FUN_00456AE0 = 0;
            uVar1 = FUN_0040F1D0(FUN_004A2990, param_1);
            if ((int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 0x5a0000) {
                DAT_004a2830_startypos = (void*)((int)DAT_004a2830_startypos + uVar1);
            }
        }
        FUN_00419840(param_1);
        return;
    }
    if (param_1[0x2d] == FUN_00456AEC) {
        FUN_00456AEC = (void*)0xfffffffe;
        param_1[0x2a] = (void*)0x1;
    }
    FUN_004335F0(param_1, 0);
}
}
