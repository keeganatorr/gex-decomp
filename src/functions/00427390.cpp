struct GXObject {
    unsigned char pad00[0x54];
    long gob_currentFrameIndex;
    unsigned char pad58[0x14];
    unsigned long gob_flags;
    unsigned char pad70[0x28];
    long gob_work0;
    long gob_work1;
};

extern "C" {
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0283;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern long DAT_004A2990;
extern long DAT_00463AD0;
extern char s_Error__PlayerTurn_____gob__gob_w_0045AB38[];

void __cdecl FUN_00424B80(GXObject **);
void __cdecl FUN_00427A10(GXObject **);
void __cdecl FUN_00427760(GXObject **);
void __cdecl FUN_00424090(GXObject **);
void __cdecl FUN_00405350(char *, long);
void __cdecl FUN_004213F0_GexMovementLeftandRight(GXObject *);
void __cdecl FUN_004213C0(long, GXObject **);
long __cdecl FUN_00421560_DrawCharacter(long, GXObject **);
void __cdecl FUN_004250B0(GXObject **);
void __cdecl FUN_00427B80(GXObject **);

void __cdecl PlayerTurn_00427390(GXObject *gob)
{
    long iVar2;

    if (DAT_004A0294 != 0) {
        if (gob->gob_work1 >= 3)
            gob->gob_flags ^= 0x80000000UL;
        FUN_00424B80((GXObject **)gob);
        return;
    }

    if (DAT_004A0283 != 0) {
        if (gob->gob_work1 >= 3)
            gob->gob_flags ^= 0x80000000UL;
        FUN_00427A10((GXObject **)gob);
        return;
    }

    if (DAT_004A0295 != 0) {
        if (gob->gob_work1 >= 3)
            gob->gob_flags ^= 0x80000000UL;
        FUN_00427760((GXObject **)gob);
        return;
    }

    if (DAT_004A0293 == 0) {
        gob->gob_work0 += 0x10000;

        if (gob->gob_work0 > 0x10000) {
            gob->gob_work0 -= 0x10000;
            iVar2 = gob->gob_work1 - 1;
            gob->gob_work1 = iVar2;

            if (iVar2 == 0) {
                FUN_00424090((GXObject **)gob);
                return;
            }

            if (iVar2 == 3)
                gob->gob_flags ^= 0x80000000UL;

            if (iVar2 < 0 || iVar2 > 6) {
                while (DAT_00463AD0 == 0)
                    FUN_00405350(s_Error__PlayerTurn_____gob__gob_w_0045AB38, gob->gob_work1);
            } else {
                gob->gob_currentFrameIndex = ((long *)(s_Error__PlayerTurn_____gob__gob_w_0045AB38 - 0xB8))[iVar2];
            }
        }

        FUN_004213F0_GexMovementLeftandRight(gob);
        FUN_004213C0(DAT_004A2990, (GXObject **)gob);

        if (FUN_00421560_DrawCharacter(DAT_004A2990, (GXObject **)gob) == 0) {
            if (gob->gob_work1 > 3)
                gob->gob_flags ^= 0x80000000UL;
            FUN_004250B0((GXObject **)gob);
            return;
        }

        if (gob->gob_work1 <= 4 && (DAT_004A0280 != 0 || DAT_004A0281 != 0)) {
            if (gob->gob_work1 > 3)
                gob->gob_flags ^= 0x80000000UL;
            FUN_00424090((GXObject **)gob);
            return;
        }
    } else {
        if (gob->gob_work1 >= 3)
            gob->gob_flags ^= 0x80000000UL;
        FUN_00427B80((GXObject **)gob);
    }
}
}
