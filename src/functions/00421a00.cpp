// Reconstructed from the pinned PE at 00421a00, with the read-only Ghidra
// decompilation used to name the ten-word angle-edge result.
extern "C" {
extern int DAT_004A01E0;
extern int DAT_004A01EC;
extern int DAT_004A2890;
extern int DAT_00463AB8;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0282;
extern void *DAT_004A2990;

int __cdecl FUN_0041CB80(void *, int *);
unsigned int __cdecl FUN_00420c40_CheckWallCollision(void *, unsigned int, unsigned int);
int __cdecl FUN_00423d80(void *, void *, int, int);
void __cdecl InitPlayerAirToSideCrawl_00414130(unsigned int *);

int __cdecl FUN_00421a00_AirToSideCrawl(unsigned int *player)
{
    int edge[10];
    unsigned int x = player[0x1e];
    unsigned int y = player[0x1f];

    if (DAT_004A01E0 == DAT_004A01EC && DAT_004A2890 == 0) {
        if (!((DAT_00463AB8 > 0 && DAT_004A0281 != 0) ||
              (DAT_00463AB8 < 0 && DAT_004A0280 != 0))) return 0;
        if (!FUN_0041CB80(player, edge)) return 0;

        int side = DAT_00463AB8 < 0 ? edge[6] : edge[7];
        if (FUN_00420c40_CheckWallCollision(DAT_004A2990, side, y - 0x380000) != 0xc0000000U ||
            FUN_00420c40_CheckWallCollision(DAT_004A2990, side, y - 0x80000) != 0xc0000000U)
            return 0;

        int sampleX = side + (DAT_00463AB8 < 0 ? 0x20000 : -0x20000);
        int low = FUN_00423d80(DAT_004A2990, player, sampleX, y - 0x80000);
        if (low > -0x12c0000 && low <= 0 && low >= -0x300000) return 0;
        int high = FUN_00423d80(DAT_004A2990, player, sampleX, y - 0x380000);
        if (high > -0x12c0000 && high >= 0 && high <= 0x300000) return 0;

        player[0x1e] = side;
        player[0x61] = side;
        InitPlayerAirToSideCrawl_00414130(player);
        return 1;
    }

    if (DAT_004A0282 == 0 || (int)player[0x23] > 0 || !FUN_0041CB80(player, edge)) return 0;
    unsigned int ceilingY = edge[8] + player[0x23] - 0x40000;
    if (FUN_00420c40_CheckWallCollision(DAT_004A2990, x, ceilingY) != 0xc0000000U) return 0;
    player[0x31] = (player[0x1b] & 0x80000000U) ? 0xc00000U : 0x400000U;
    player[0x62] = ceilingY;

    int leftBlocked = FUN_00420c40_CheckWallCollision(DAT_004A2990, x - 0x180000, ceilingY) != 0xc0000000U;
    int rightBlocked = FUN_00420c40_CheckWallCollision(DAT_004A2990, x + 0x180000, ceilingY) != 0xc0000000U;
    if (leftBlocked && !rightBlocked)
        player[0x1e] = x + 0x210000 - ((x + 0x80000) & 0x1f0000);
    else if (!leftBlocked && rightBlocked)
        player[0x1e] = x - 0x10000 - ((x - 0x80000) & 0x1f0000);
    InitPlayerAirToSideCrawl_00414130(player);
    return 1;
}
}
