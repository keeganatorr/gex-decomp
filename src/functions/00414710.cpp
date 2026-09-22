extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern void *DAT_004A2888;
extern void *DAT_004A2990;

void __cdecl FUN_00423120_Lash_unk(int *);
void __cdecl InitPlayerSwallow_00427ce0(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl FUN_00427760(int *);
int __cdecl FUN_0041CB80(int *, unsigned int *);
int __cdecl FUN_00420820(unsigned int, unsigned int);
void __cdecl FUN_00422790_pStateUnk_Lash(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
void __cdecl FUN_00423130_pStateUnk_Eating(int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
void __cdecl FUN_004250B0(int *);
void __cdecl FUN_004146D0(int *);
}

extern "C" void __cdecl GEX_Target(int *player)
{
    unsigned int edges[10];

    if ((DAT_004A0294 || DAT_004A0295) && !DAT_004A0293) {
        FUN_00423120_Lash_unk(player);
        if (DAT_004A2888) {
            InitPlayerSwallow_00427ce0(player);
            return;
        }
        if (DAT_004A0294) {
            FUN_00424B80(player);
            return;
        }
        FUN_00427760(player);
        return;
    }

    if (FUN_0041CB80(player, edges)) {
        if (FUN_00420820((unsigned int)player[0x1e] - 0xc0000U, edges[8]))
            goto finish;
        if (FUN_00420820((unsigned int)player[0x1e] + 0xc0000U, edges[8]))
            goto finish;
    }

    if (++player[0x26] >= 1) {
        player[0x26] = 0;
        if (++player[0x15] <= 10) {
            FUN_00422790_pStateUnk_Lash(player);
        } else {
            goto finish;
        }
    }

    FUN_004213f0_GexMovementLeftandRight(player);
    FUN_004213c0(DAT_004A2990, player);
    FUN_00423130_pStateUnk_Eating(player);
    if (!FUN_00421560_DrawCharacter(DAT_004A2990, player)) {
        FUN_00423120_Lash_unk(player);
        if (DAT_004A2888)
            InitPlayerSwallow_00427ce0(player);
        FUN_004250B0(player);
    }
    return;

finish:
    FUN_00423120_Lash_unk(player);
    if (DAT_004A2888) {
        InitPlayerSwallow_00427ce0(player);
        return;
    }
    FUN_004146D0(player);
}
