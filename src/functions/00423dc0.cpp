extern "C" {
extern int level_004a2964;
extern int DAT_004A0240;
extern int DAT_00456018_gex_Init_unk;
extern int DAT_004A0260;
extern void *PTR_004a2a10;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0282;
extern unsigned char DAT_004A0283;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern void *M1_CurrentLevel_004a2990;
extern unsigned char DAT_0045B9A0[];
extern int DAT_004a2980;
extern unsigned char DAT_0045AA70[];
extern int DAT_004a0264_PowerUp_SuperSpeed;
void __cdecl InitPlayerDucking_00427a10(int *);
void __cdecl InitPlayerOldMan_00423d20(int *);
void __cdecl InitPlayerWalk_00424940(int *);
void __cdecl InitPlayerTailSlash_00427760(int *);
void __cdecl InitPlayerStandJumpStart_00424b80(int *);
void __cdecl InitPlayerTongueLash_00427b80(int *);
int __cdecl FUN_00421560_DrawCharacter(void *, int *);
void __cdecl InitPlayerFall_004250b0(int *);
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *, int, int);
void __cdecl InitPlayerSlide45_00424290(int *);
void __cdecl InitPlayerLookup_004146d0(int *);
void __cdecl FUN_004213f0_GexMovementLeftandRight(int *);
void __cdecl FUN_004213c0(void *, int *);
int __cdecl FUN_00423d80(void *, int *, int, int);
void __cdecl VFX_Play_0041fa80(int);
int __cdecl UTL_ReallyRandom_00428c80(int);
void __cdecl IDL_SetIdle_0041fdb0(int);
int __cdecl IDL_Resolve_0041fd00(void);

void __cdecl GEX_Target(int *p)
{
    int r1;
    int r2;
    int c;
    if (level_004a2964 != 0x44 && !DAT_004A0240 && !DAT_00456018_gex_Init_unk) {
        DAT_004A0240 = 1;
        if (DAT_004A0283) {
            InitPlayerDucking_00427a10(p);
            return;
        }
        if (DAT_004A0260 && PTR_004a2a10)
            InitPlayerOldMan_00423d20(p);
        if (!DAT_004A0280 && !DAT_004A0281) {
            if (DAT_004A0295) {
                InitPlayerTailSlash_00427760(p);
                return;
            }
            if (DAT_004A0294) {
                InitPlayerStandJumpStart_00424b80(p);
                return;
            }
            if (!DAT_004A0293) {
                if (!FUN_00421560_DrawCharacter(M1_CurrentLevel_004a2990, p)) {
                    InitPlayerFall_004250b0(p);
                    return;
                }
                if ((!p[0x44] && (*(int *)(DAT_0045B9A0 + M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, p[0x1e], p[0x1f]) * 32) & 0xc000006))
                    || (p[0x44] && (((int *)p[0x44])[0x2d] & 0x600))) {
                    InitPlayerSlide45_00424290(p);
                    return;
                }
                if (DAT_004A0282) {
                    InitPlayerLookup_004146d0(p);
                    return;
                }
                FUN_004213f0_GexMovementLeftandRight(p);
                FUN_004213c0(M1_CurrentLevel_004a2990, p);
                r1 = FUN_00423d80(M1_CurrentLevel_004a2990, p, p[0x1e] + 0x60000, p[0x1f]);
                r2 = FUN_00423d80(M1_CurrentLevel_004a2990, p, p[0x1e] - 0x60000, p[0x1f]);
                if (!p[0x44] && ((((r1 > 0x110000 || r1 < (int)0xd8f00000) && (p[0x1b] & 0x80000000)))
                                 || ((r2 > 0x110000 || r2 < (int)0xd8f00000) && !(p[0x1b] & 0x80000000)))) {
                    VFX_Play_0041fa80(0x18);
                    p[0x14] = 0x41;
                    if (p[0x15] > 0x1d)
                        p[0x15] = 0;
                }
    
            } else {
                InitPlayerTongueLash_00427b80(p);
                return;
            }
        } else {
            InitPlayerWalk_00424940(p);
            return;
        }
    }
    if (p[0x26]) {
        p[0x26]--;
        return;
    }
    p[0x26] = p[0x14] == 0x41 ? 1 : 3;
    if (p[0x14] == 0x29 && !p[0x44] && level_004a2964 != 0x44) {
        if (++p[0x2a] == 0xa0) {
            IDL_SetIdle_0041fdb0(DAT_004a2980 ? DAT_004a2980 : DAT_0045AA70[UTL_ReallyRandom_00428c80(0xf)]);
        } else if (p[0x2a] > 0xa0 && IDL_Resolve_0041fd00() && level_004a2964 != 0x1b && !DAT_004a0264_PowerUp_SuperSpeed) {
            InitPlayerOldMan_00423d20(p);
            return;
        }
    }
    p[0x15]++;
}
}
