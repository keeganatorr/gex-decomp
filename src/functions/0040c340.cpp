typedef struct GXObject {
    unsigned char _pad0[0x54];
    int f54;
    unsigned char _pad58[0x20];
    int xpos;      /* 0x78 */
    int ypos;      /* 0x7c */
    unsigned char _pad80[0x18];
    int f98;
    char *text;    /* 0x9c */
    unsigned char _pada0[0xc];
    int fac;
    int fb0;
    unsigned int fb4;
    unsigned char _padb8[0x28];
    unsigned int fe0;
} GXObject;
typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct TitleEntry {
    char *name;
    int level;
} TitleEntry;
extern "C" {
extern int LEVELID_004a2a74;
extern LevelEntry DAT_004577B0[];
extern int DAT_00456034;
extern char *PTR_DAT_004560e0[];
extern TitleEntry PTR_s_Title_00456038[];
int __cdecl OBI_CheckRemoveObject_0040fce0(GXObject *gob);
void __cdecl PrintWithFont_0040bc70(int x, int y, int type, int p4, int p5, int wave, char *text, GXObject *gob);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl FUN_0040bc50_PrintStringInner(int scale);

void __cdecl MainMenuButtonDraw_0040c340(GXObject *gob)
{
    int scale;
    int frame;
    int wave;

    gob->fe0 |= 0x1000000;
    if (OBI_CheckRemoveObject_0040fce0(gob))
        return;
    if (gob->fb4 & 1)
        return;
    if ((gob->fb4 & 0x40000000) && (DAT_004577B0[LEVELID_004a2a74].info & 0x200))
        return;
    if ((gob->fb4 & 0x80000000) && !(DAT_004577B0[LEVELID_004a2a74].info & 0x200))
        return;
    frame = gob->f54;
    wave = -1;
    if (!frame)
        wave = DAT_00456034;
    switch (gob->fac) {
    case 1:
        PrintWithFont_0040bc70(gob->xpos, gob->ypos, 0x5b, gob->f98, 0x7b, wave, PTR_DAT_004560e0[gob->fb0], 0);
        break;
    case 2:
        PrintWithFont_0040bc70(gob->xpos, gob->ypos, 0x5b, gob->f98, 0x7b, wave, PTR_s_Title_00456038[gob->fb0].name, 0);
        break;
    case 4:
        gob->f54 = 0;
        GOB_DisplayObject_00444590(gob);
        break;
    case 6:
        PrintWithFont_0040bc70(gob->xpos, gob->ypos, 0x5a, gob->f98, 0x7b, wave, gob->text, 0);
        break;
    default:
        PrintWithFont_0040bc70(gob->xpos, gob->ypos, 0x5b, gob->f98, 0x7b, wave, gob->text, 0);
        break;
    }
    gob->f54 = frame;
    if (!frame) {
        switch (gob->fb4 & 0xc) {
        case 0:
            scale = 0x10000;
            break;
        case 4:
            scale = 0x8000;
            break;
        case 8:
            scale = 0x5555;
            break;
        }
        FUN_0040bc50_PrintStringInner(scale);
    }
}
}
