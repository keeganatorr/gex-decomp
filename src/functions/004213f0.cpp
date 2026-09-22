extern "C" {
extern unsigned int DAT_00457210[];
extern void __cdecl FUN_00420FA0(int *);
extern void __cdecl FUN_00421120(int *);
extern int __cdecl FUN_00420CE0(int *);

void __cdecl GEX_Target(int *GEX)
{
    int allowedMovement;
    int iVar1;

    allowedMovement = GEX[0x88 / 4];
    iVar1 = GEX[0x80 / 4] + allowedMovement;
    GEX[0x80 / 4] = iVar1;
    if (iVar1 < 0) {
        if ((allowedMovement == 0) && ((DAT_00457210[GEX[0x70 / 4]] & 0x40) != 0)) {
            GEX[0x80 / 4] = iVar1 + 0x2000;
            if (iVar1 + 0x2000 > 0) {
                GEX[0x80 / 4] = 0;
            }
        }
        allowedMovement = -GEX[0x84 / 4];
        if (GEX[0x80 / 4] >= allowedMovement) goto LAB_00421491;
        else goto LAB_0042148B;
    }
    else {
        if (iVar1 <= 0) goto LAB_00421491;
        if ((allowedMovement == 0) && ((DAT_00457210[GEX[0x70 / 4]] & 0x40) != 0)) {
            GEX[0x80 / 4] = iVar1 - 0x2000;
            if (iVar1 - 0x2000 < 0) {
                GEX[0x80 / 4] = 0;
            }
        }
        allowedMovement = GEX[0x84 / 4];
        if (GEX[0x80 / 4] <= allowedMovement) goto LAB_00421491;
    }
LAB_0042148B:
    GEX[0x80 / 4] = allowedMovement;
LAB_00421491:
    FUN_00420FA0(GEX);
    FUN_00421120(GEX);
    allowedMovement = FUN_00420CE0(GEX);
    if (allowedMovement != 0) {
        GEX[0x78 / 4] += GEX[0x80 / 4] / allowedMovement;
        return;
    }
    GEX[0x78 / 4] += GEX[0x80 / 4];
}
}
