typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x50];
    int f50;
    int f54;
    unsigned char _pad58[0x18];
    int f70;
    int f74;
    int xpos;      /* 0x78 */
    int ypos;      /* 0x7c */
    unsigned char _pad80[0x8];
    int f88;
    unsigned char _pad8c[0x4];
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    unsigned char _pada4[0x4];
    int fa8;
    GXObject *fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    unsigned char _padc0[0x4];
    int fc4;
    int fc8;
    int fcc;
    unsigned char _padd0[0xc];
    int fdc;
    unsigned int fe0;
    unsigned char _pade4[0x20];
    int f104;
};
typedef struct LevelEntry {
    unsigned short info;
    unsigned char rest[6];
} LevelEntry;
typedef struct Offset {
    int dx;
    int dy;
} Offset;
extern "C" {
extern int DAT_0045ae58[];
extern int DAT_00463b64;
extern Offset DAT_0045ae18[];
extern int DAT_00463b48;
extern unsigned char DAT_004a2680[];
extern unsigned char DAT_004a24b0[];
extern unsigned char BYTE_ARRAY_004a25d0[];
extern unsigned char DAT_0045adff[];
extern LevelEntry DAT_004577B0[];
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *gob);
int __cdecl FUN_0042a560_RemoteUnk(GXObject *gob, int id);
int __cdecl FUN_00429190(int x0, int y0, int x1, int y1);
void __cdecl GOB_DisplayCelToQuad_00443ae0(GXObject *gob, int cel, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int id, int step);
void __cdecl FUN_00429200_PasswordRelated(char *buf);
int __cdecl TXT_PixelLength_0043fae0(char *text);
void __cdecl FUN_00444800_Tiles(int a, int x, int y, int w, int h, int b, int color);
void __cdecl TXT_DrawPrintFP_0043faa0(int x, int y, char *text);

void __cdecl FUN_0042a690(GXObject *gob)
{
    int tx;
    int x;
    int dx;
    int ty;
    int a;
    int dy;
    int w;
    int n;
    int id;
    int scale;
    int len;
    char buf[16];

    gob->fe0 |= 0x1000000;
    gob->ypos = gob->f98;
    gob->f50 = 0x12;
    gob->f54 = 0;
    gob->xpos = 0;
    gob->fbc = 0x1281;
    GOB_DisplayObject_00444590(gob);
    gob->fbc = 0;
    if (gob->fb0) {
        gob->fb0--;
        x = FUN_0042a560_RemoteUnk(gob, gob->fa8);
        if (x) {
            tx = gob->fac->xpos;
            ty = gob->fac->ypos;
            a = FUN_00429190(x, 0x360000, tx, ty) >> 21;
            gob->fbc = DAT_0045ae58[DAT_00463b64];
            if (!DAT_0045ae58[++DAT_00463b64])
                DAT_00463b64 = 0;
            gob->f50 = 0x1f;
            gob->f54 = 0;
            dx = DAT_0045ae18[a].dx;
            dy = DAT_0045ae18[a].dy;
            GOB_DisplayCelToQuad_00443ae0(gob, 0, x + dx, 0x360000 + dy, x - dx, 0x360000 - dy, tx - dx, ty - dy, tx + dx, ty + dy);
            gob->xpos = tx;
            gob->f50 = 0x1e;
            gob->f54 = 0;
            gob->ypos = ty;
            gob->fc4 = (UTL_ReallyRandom32_00428c60() & 0xff) << 16;
            GOB_DisplayObjectScaleAndRotate_00441150(gob);
            gob->fc4 = 0;
            gob->fbc = 0;
        }
    }
    w = (4 - gob->fa0) * 5 << 19;
    if (gob->f98 > -0x400000) {
        if (w <= 0x280000) {
            gob->f50 = 0x15;
            gob->f54 = 0;
            gob->xpos = 0x280000;
            gob->ypos = gob->f98 + 0x280000;
            GOB_DisplayObject_00444590(gob);
        } else {
            gob->f50 = 0x14;
            gob->f54 = DAT_00463b48;
            gob->ypos = gob->f98 + 0x280000;
            gob->xpos = w;
            GOB_DisplayObject_00444590(gob);
            DAT_00463b48 = gob->f54 + 1;
        }
    }
    if (gob->fb4) {
        id = FUN_00429cb0_RemoteTVSelect_Unk1(0, gob->f9c + 1);
        n = 0;
        if (gob->fb4 > 0) {
            do {
                w += 0x280000;
                if (gob->fb8 != id) {
                    if (gob->f98 > -0x400000 && w >= 0x1180000) {
                        scale = gob->fc8;
                        gob->ypos = gob->f98 + 0x280000;
                        gob->fc8 = -gob->fc8;
                        gob->f50 = 0x15;
                        gob->f54 = 0;
                        gob->xpos = 0x1180000;
                        GOB_DisplayObjectScaleAndRotate_00441150(gob);
                        gob->fc8 = scale;
                        break;
                    }
                    if (--DAT_004a2680[id] > 0x40) {
                        DAT_004a2680[id] = 2;
                        DAT_004a24b0[id]++;
                    }
                    gob->f50 = DAT_0045adff[(DAT_004577B0[id].info & 0xf) * 3 + BYTE_ARRAY_004a25d0[id]];
                    gob->f54 = DAT_004a24b0[id];
                    gob->xpos = w;
                    if (gob->fac && gob->fa8 == id)
                        gob->ypos = 0x360000;
                    else
                        gob->ypos = gob->f98 + 0x1e0000;
                    GOB_DisplayObject_00444590(gob);
                    DAT_004a24b0[id] = (unsigned char)gob->f54;
                }
                id = FUN_00429cb0_RemoteTVSelect_Unk1(id, 1);
                n++;
            } while (gob->fb4 > n);
        }
        if (gob->fb8 >= 0) {
            gob->f50 = DAT_0045adff[(DAT_004577B0[gob->fb8].info & 0xf) * 3 + BYTE_ARRAY_004a25d0[gob->fb8]];
            gob->xpos = gob->f74;
            gob->ypos = gob->fdc;
            gob->fc8 = gob->f104;
            gob->f54 = 0;
            gob->fcc = gob->f104;
            GOB_DisplayObjectScaleAndRotate_00441150(gob);
            gob->fc8 = 0x10000;
            gob->fcc = 0x10000;
        } else {
            gob->f50 = 0x13;
            gob->f54 = 0;
            if (gob->fac)
                gob->ypos = 0x400000;
            else
                gob->ypos = gob->f98 + 0x280000;
            gob->xpos = 0xa00000;
            GOB_DisplayObject_00444590(gob);
        }
    } else if (gob->f98 > -0x400000) {
        gob->f50 = 0x13;
        gob->f54 = 0;
        gob->ypos = gob->f98 + 0x280000;
        gob->xpos = 0xa00000;
        GOB_DisplayObject_00444590(gob);
    }
    if (gob->f70 == 6) {
        gob->fc8 = gob->f90;
        gob->fcc = gob->f90;
        gob->xpos = gob->f88;
        gob->f50 = 0x1d;
        gob->f54 = 0;
        gob->ypos = gob->f94;
        GOB_DisplayObjectScaleAndRotate_00441150(gob);
        if (gob->f90 == 0x10000) {
            FUN_00429200_PasswordRelated(buf);
            len = TXT_PixelLength_0043fae0(buf);
            FUN_00444800_Tiles(0, gob->xpos + (-0x80000 - len) / 2 + 0x60000, gob->ypos - 0x90000, len + 0x80000, 0xd0000, 0, 0x1f81);
            TXT_DrawPrintFP_0043faa0(gob->xpos - len / 2 + 0x60000, gob->ypos - 0x60000, buf);
        }
        gob->fc8 = 0x10000;
        gob->fcc = 0x10000;
    }
}
}
