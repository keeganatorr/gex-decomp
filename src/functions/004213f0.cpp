// Adapted from pc_decomp_backup/src/functions/FUN_004213F0.cpp
// Historical source SHA256: 2c33079a90b681b7b5eaa2a98a4c3587b8cac5359f1e0ece82ba1b2979687af1
extern "C" {
extern "C" { extern int DAT_00457210; }

extern "C" int __cdecl FUN_00420CE0(int*);
extern "C" void __cdecl FUN_00420FA0(int*);
extern "C" void __cdecl FUN_00421120(int*);

extern "C" void __cdecl GEX_Target(int* GEX)
{
    int allowedMovement;
    int iVar1;

    allowedMovement = GEX[0x88 / 4];
    iVar1 = GEX[0x80 / 4] + allowedMovement;
    GEX[0x80 / 4] = iVar1;
    if (iVar1 < 0) {
        if (((allowedMovement == 0) && ((*(unsigned int*)(&DAT_00457210 + GEX[0x70 / 4] * 4) & 0x40) != 0)) && (iVar1 + 0x2000 > 0)) {
            GEX[0x80 / 4] = 0;
        } else {
            if (iVar1 + 0x2000 > 0) {
                GEX[0x80 / 4] = iVar1 + 0x2000;
            }
        }
        allowedMovement = -GEX[0x84 / 4];
        if (allowedMovement <= GEX[0x80 / 4]) goto FUN_00421491;
    } else {
        if (iVar1 < 1) goto FUN_00421491;
        if (((allowedMovement == 0) && ((*(unsigned int*)(&DAT_00457210 + GEX[0x70 / 4] * 4) & 0x40) != 0)) && (iVar1 - 0x2000 < 0)) {
            GEX[0x80 / 4] = 0;
        } else {
            if (iVar1 - 0x2000 < 0) {
                GEX[0x80 / 4] = iVar1 - 0x2000;
            }
        }
        allowedMovement = GEX[0x84 / 4];
        if (GEX[0x80 / 4] <= allowedMovement) goto FUN_00421491;
    }
    GEX[0x80 / 4] = allowedMovement;
FUN_00421491:
    FUN_00420FA0(GEX);
    FUN_00421120(GEX);
    allowedMovement = FUN_00420CE0(GEX);
    if (allowedMovement == 0) {
        GEX[0x6c / 4] = GEX[0x6c / 4] + GEX[0x80 / 4];
        return;
    }
    GEX[0x6c / 4] = GEX[0x6c / 4] + GEX[0x80 / 4] / allowedMovement;
}
}
