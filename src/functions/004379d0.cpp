extern "C" {
extern int *gPlayerObject_004a27fc;
extern int DAT_0045c9d8;
extern int DAT_0045c9d4;
extern int DAT_0045c998;
extern int DAT_0045c99c;
extern int DAT_0045c9a0;
extern unsigned char IMAGE_DOS_HEADER_00400000[];
int __cdecl GOB_GetHotSpot_00419c00(int *, int, int, int *, int *);

void __cdecl FUN_004379d0_KFBossStateInner_MoveGex(int *object)
{
    int hotspotX;
    int hotspotY;
    int dx = gPlayerObject_004a27fc[0x1e] - object[0x1e];
    int dy = gPlayerObject_004a27fc[0x1f] - object[0x1f];

    ++DAT_0045c9d8;
    if (DAT_0045c9d8 % 4) {
        if (GOB_GetHotSpot_00419c00(object, 0, 0, &hotspotX, &hotspotY)) {
            dx -= hotspotX;
            dy -= hotspotY;
        }
        if (dy > -0x200000 && dy < 0x200000) {
            DAT_0045c998 = 1;
        } else if (dy < -0x200000) {
            DAT_0045c998 = 2;
        } else if (dy > 0x200000 &&
                   ((object[0x1b] & 0x80000000u)
                    ? dx < -0x400000 : dx > 0x400000)) {
            DAT_0045c998 = 3;
        } else {
            DAT_0045c998 = 4;
        }
    } else {
        ++DAT_0045c9d4;
        if (DAT_0045c9d4 > 4)
            DAT_0045c9d4 = 1;
        DAT_0045c998 = DAT_0045c9d4;
    }

    DAT_0045c99c = (object[0x1b] & 0x80000000u)
        ? -(((int *)(IMAGE_DOS_HEADER_00400000 + 0x5c9a8))[DAT_0045c998] << 16)
        : (((int *)(IMAGE_DOS_HEADER_00400000 + 0x5c9a8))[DAT_0045c998] << 16);
    DAT_0045c9a0 = ((int *)(IMAGE_DOS_HEADER_00400000 + 0x5c9c0))[DAT_0045c998] << 16;
}
}
