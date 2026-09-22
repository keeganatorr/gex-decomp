static inline void adjustCollisionX(int *x, int left, int right)
{
    int fromLeft = left - *x + 0x180000;
    int fromRight = *x - right + 0x180000;
    if (fromLeft > 0 && fromRight > 0)
        return;
    if (fromLeft > 0) {
        *x += fromLeft + 0x10000;
        return;
    }
    if (fromRight > 0)
        *x -= fromRight + 0x10000;
}

extern "C" {
extern unsigned int DAT_00457210[];
extern int DAT_00458c78_ButtonUnk10;
extern char DAT_004A0280;
extern char DAT_004A0281;
extern char DAT_004A0282;
extern int *gPlayerObject_004a27fc;
extern int *gPlayerPlatform_004a2864;
void __cdecl FUN_00421cd0_xpos_ypos_related(int *);
void __cdecl InitPlayerPlatAirToSideCrawl_00414290(int *);

void __cdecl GEX_Target(int *object, int *collision, int direction)
{
    if ((DAT_00457210[gPlayerObject_004a27fc[28]] & 2) == 0 ||
        DAT_00458c78_ButtonUnk10 != 0)
        return;

    switch (object[28]) {
    case 0x3d:
        return;
    case 0x44:
    case 0x45:
        return;
    case 0x50:
    case 0x51:
    case 0x52:
        return;
    default:
        break;
    }

    if (direction == 2) {
        if (!DAT_004A0282)
            return;
        gPlayerPlatform_004a2864 = object;
        FUN_00421cd0_xpos_ypos_related(gPlayerObject_004a27fc);
        gPlayerObject_004a27fc[49] =
            (gPlayerObject_004a27fc[27] & 0x80000000u) ? 0xc00000 : 0x400000;
        gPlayerObject_004a27fc[31] = collision[11];
        adjustCollisionX(&gPlayerObject_004a27fc[30], collision[8], collision[9]);
        InitPlayerPlatAirToSideCrawl_00414290(gPlayerObject_004a27fc);
        return;
    }

    int toRight = direction == 1;
    if ((toRight && DAT_004A0281) || (!toRight && DAT_004A0280)) {
        gPlayerPlatform_004a2864 = object;
        FUN_00421cd0_xpos_ypos_related(gPlayerObject_004a27fc);
        if (toRight) {
            gPlayerObject_004a27fc[27] |= (int)0x80000000u;
            gPlayerObject_004a27fc[30] = collision[8];
        } else {
            gPlayerObject_004a27fc[27] &= 0x7fffffff;
            gPlayerObject_004a27fc[30] = collision[9];
        }
        InitPlayerPlatAirToSideCrawl_00414290(gPlayerObject_004a27fc);
    }
}
}
