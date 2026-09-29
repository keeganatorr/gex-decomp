extern "C" {
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;
extern void *DAT_004A2888;
extern void *DAT_004A2990;

void __cdecl FUN_00423120_Lash_unk(int *);
void __cdecl InitPlayerSwallow_00427ce0(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl FUN_00427760(int *);
void __cdecl FUN_00424AA0(int *);
void __cdecl FUN_00424090(int *);
void __cdecl FUN_00422790_pStateUnk_Lash(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_00423130_pStateUnk_Eating(int *);

void __cdecl PlayerTongueLash_00427a50(int *p)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00423120_Lash_unk(p);
        if (DAT_004A2888 != 0) {
            InitPlayerSwallow_00427ce0(p);
            return;
        }
        if (DAT_004A0294 != 0) {
            FUN_00424B80(p);
            return;
        }
        FUN_00427760(p);
        return;
    }

    if (++p[0x26] >= 1) {
        p[0x26] = 0;
        if (++p[0x15] > 14) {
            FUN_00423120_Lash_unk(p);
            if (DAT_004A2888 != 0) {
                InitPlayerSwallow_00427ce0(p);
                return;
            }
            if (p[0x29] != 0) {
                FUN_00424AA0(p);
                return;
            }
            FUN_00424090(p);
            return;
        }
        FUN_00422790_pStateUnk_Lash(p);
    }

    FUN_004213f0_GexMovementLeftandRight(p);
    FUN_004213c0(DAT_004A2990, p);
    if (FUN_00421560_DrawCharacter(DAT_004A2990, p) == 0) {
        if (DAT_004A2888 != 0) {
            InitPlayerSwallow_00427ce0(p);
            FUN_00423130_pStateUnk_Eating(p);
            return;
        }
        FUN_004250B0(p);
    }
    FUN_00423130_pStateUnk_Eating(p);
}
}
