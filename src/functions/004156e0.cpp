// Adapted from pc_decomp_backup/src/functions/FUN_004156E0.cpp
// Historical source SHA256: 5b875b6061c0e8472929b889dcdf091d29e17876aa46939be2f803e05d65ae97
extern "C" {
extern "C" { extern int FUN_004A2870; }
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a2828; }
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_00413F10(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    int iVar1;
    if (FUN_004A2870 != 0) {
        iVar1 = FUN_00421560_DrawCharacter(FUN_004A2990, p);
        if (iVar1 != 0) return;
    }
    DAT_004a2828 = 0;
    p[0x1c] = (void*)0x54;
    FUN_00413F10(p);
}
}
