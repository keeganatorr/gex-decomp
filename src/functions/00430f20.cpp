typedef struct GXObject GXObject;
struct GXObject {
    char pad0[0xc];
    void *loadData;
    char pad10[0x40];
    int group;
    int index;
    char pad58[8];
    void *drawFunc;
    char pad64[8];
    unsigned int flags;
    int state;
    char pad74[4];
    int xpos;
    int ypos;
    int xVel;
    char pad84[4];
    int xAccl;
    int yVel;
    int maxyVel;
    int yAccl;
    int work0;
    char pad9c[0xc];
    int work4;
    int work5;
    char padb0[0x14];
    int angle;
    char padc8[0x18];
    unsigned int flags2;
};

extern "C" {
int __cdecl rand(void);
extern void *GEX_pGlob_004a2ad4;
int __cdecl GOB_GetHotSpot_00419c00(GXObject *, int, int, int *, int *);
GXObject *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *, GXObject *);
void __cdecl GOB_RemoveMapObject_00419840(GXObject *);
void __cdecl DefDoIt_004339c0(GXObject *);
void __cdecl FUN_004322a0(GXObject *);

void __cdecl ob232DoIt_00430f20(GXObject *g)
{
    int hy;
    int hx;
    int r;
    int i;
    int k;
    GXObject *o;
    if (g->work0 == 0x200) {
        k = rand() % 4;
        g->flags2 |= 0x40;
        g->xVel += g->xAccl;
        g->yVel += g->yAccl;
        g->xpos += g->xVel;
        g->ypos += g->yVel;
        g->angle = (g->work5 + g->angle) & 0xff0000;
        if (GOB_GetHotSpot_00419c00(g, 0, k, &hx, &hy)) {
            hx += g->xpos;
            hy += g->ypos;
            o = GOB_AddObject_004195d0(0x5c, hx, hy, GEX_pGlob_004a2ad4);
            if (o) {
                o->flags |= 0x8000;
                o->maxyVel = 0x7fff0000;
                o->yVel = 0;
                o->yAccl = 0xa000;
                o->group = 0x1b;
                o->work0 = 3;
                o->state = 0x30;
                o->flags2 |= 0x40;
                GOB_PutObjectInfrontOfObject_00419be0(o, g);
            }
        }
        if (g->ypos > 0x2a00000 || g->xpos > 0x5800000 || g->xpos < 0xe00000)
            GOB_RemoveMapObject_00419840(g);
    } else {
        g->flags2 |= 0x40;
        DefDoIt_004339c0(g);
        if (g->work4) {
            g->work4 = 0;
            for (i = 0; i < 6; i++) {
                if (GOB_GetHotSpot_00419c00(g, 0, i, &hx, &hy)) {
                    hx += g->xpos;
                    hy += g->ypos;
                    o = GOB_AddObject_004195d0(0xe8, hx, hy, g->loadData);
                    if (o) {
                        r = rand();
                        o->group = 3;
                        o->index = i + 1;
                        o->work0 = 0x200;
                        if (r % 2)
                            o->work5 = (r % 16 + 8) << 16;
                        else
                            o->work5 = (8 - r % 16) << 16;
                        o->yAccl = 0x10000;
                        o->yVel = (r % ((hy - g->ypos + 0x140000) >> 17) << 16) + (((hy - g->ypos + 0x140000) >> 17) << 16);
                        o->xAccl = 0;
                        o->xVel = (r % ((hx - g->xpos) >> 18) << 16) + (((hx - g->xpos) >> 18) << 16);
                        o->drawFunc = FUN_004322a0;
                        o->flags2 |= 0x40;
                        GOB_PutObjectInfrontOfObject_00419be0(o, g);
                    }
                }
            }
        }
    }
}
}
