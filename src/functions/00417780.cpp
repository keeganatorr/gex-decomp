extern "C" {
extern int DAT_004A2888;
extern int PTR_004a2838;
extern int DAT_004A2864;
extern int PTR_004a2874;
extern int PTR_004a2814;
extern int DAT_004a2818_Lash_unk;
extern int DAT_004a2828;
extern int FUN_004A2870;
extern int DAT_00462e50;
extern int DAT_00458c78_ButtonUnk10;
extern int DAT_004A288C;
extern int FUN_004A27E8;
extern int DAT_004a2850;
extern int DAT_004a2858_PlayerStuff;
extern int DAT_004a2878_CollisionType;
extern int DAT_004a2840;
extern int DAT_004a27ec_PauseOnCollision2;
extern int DAT_00462e78;
extern int DAT_00462e38;
extern int gNumPlayerBubbles_004a2854;
extern int DAT_004a285c;
extern int DAT_004a0218_pState;
extern int DAT_0045A6D0;
extern int DAT_0045a6d4;
extern int DAT_004A2AC0;
extern int DAT_004A2A0C;
extern int PTR_004a2a10;
extern int DAT_004a0260;
extern int *DAT_004A27FC;
extern int GEX_pGlob_004a2ad4;
extern int *PTR_00462e84;
extern int *PTR_00462e88;
extern int *PTR_004630d8;
extern int *PTR_004630dc;
extern char s_ERROR__player_already_introed__00458c58[];
extern char s_duplicate_GX_at___ld___ld__00458c3c[];

void __cdecl FUN_00405350(const char *, ...);
void __cdecl FUN_00419840(int *);
void __cdecl FUN_00419B80(int *, int);
int * __cdecl FUN_004195D0(int, int, int, int);

void __cdecl GEX_Target(int *gOb)
{
    DAT_004A2888 = 0;
    PTR_004a2838 = 0;
    DAT_004A2864 = 0;
    PTR_004a2874 = 0;
    PTR_004a2814 = 0;
    DAT_004a2818_Lash_unk = 0;
    DAT_004a2828 = 0;
    FUN_004A2870 = 0;
    DAT_00462e50 = 0;
    DAT_00458c78_ButtonUnk10 = 0;
    DAT_004A288C = 0;
    FUN_004A27E8 = 0;
    DAT_004a2850 = 0;
    DAT_004a2858_PlayerStuff = 0;
    DAT_004a2878_CollisionType = 0;
    DAT_004a2840 = 0;
    DAT_004a27ec_PauseOnCollision2 = 0;
    DAT_00462e78 = 0;
    DAT_00462e38 = 0;
    gNumPlayerBubbles_004a2854 = 0;
    DAT_004a285c = 0;
    DAT_004a0218_pState = -1;
    DAT_0045A6D0 = 0x50000;
    DAT_0045a6d4 = 0x80000;

    if (DAT_004A2AC0 == 0 && DAT_004A2A0C == 0 && PTR_004a2a10 != 0)
        DAT_004a0260 = 1;

    if (DAT_004A27FC != 0) {
        FUN_00405350(s_ERROR__player_already_introed__00458c58);
        FUN_00405350(s_duplicate_GX_at___ld___ld__00458c3c, gOb[30], gOb[31]);
        FUN_00419840(gOb);
        return;
    }

    DAT_004A27FC = gOb;
    FUN_00419B80(gOb, 4);
    PTR_00462e84 = FUN_004195D0(0x12e, 0, 0, GEX_pGlob_004a2ad4);
    PTR_00462e88 = FUN_004195D0(0x12e, 0, 0, GEX_pGlob_004a2ad4);
    PTR_004630d8 = FUN_004195D0(0x12f, 0, 0, GEX_pGlob_004a2ad4);
    PTR_004630dc = FUN_004195D0(0x12f, 0, 0, GEX_pGlob_004a2ad4);
    PTR_00462e84[20] = 0x5c;
    PTR_00462e88[20] = 0x5c;
    PTR_004630d8[20] = 0x5d;
    PTR_004630dc[20] = 0x5d;
}
}
