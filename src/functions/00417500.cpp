typedef struct GXObject {
    char pad0[0x50];
    int group;
    int index;
    void *initFunc;
    void *doitFunc;
    void *drawFunc;
    char pad64[8];
    unsigned int flags;
    int state;
    char pad74[4];
    int xpos;
    int ypos;
    int f80;
    char pad84[8];
    int f8c;
    char pad90[0x2c];
    int tpage;
    char padc0[8];
    int f_c8;
    int f_cc;
    char padd0[0x10];
    unsigned int flags2;
} GXObject;

extern "C" {
extern int DAT_004a0218_pState;
extern unsigned int DAT_00457210[];
extern int gNoProcess_00455c4c;
extern int DAT_004a2878_CollisionType;
extern int DAT_004a2840;
extern int DAT_004a0238_HealthLost;
extern void *gPlayerBubbleGlob_004a23f0;
extern int DAT_00463590;
extern int DAT_00462e40;
extern int gNumPlayerBubbles_004a2854;
extern int DAT_00458b88;
extern int gPlayerBubblePIXC_00458b8c;
extern int DAT_00458b80;
extern int DAT_00458b78;
extern int DAT_00458b84;
extern int DAT_00458b7c;
void __cdecl SND_PlayObSound_0041a250(GXObject *, int, int, int);
void __cdecl FUN_0042e850(GXObject *);
void __cdecl FUN_00416320_CollisionsProcessing(GXObject *);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
int __cdecl UTL_ReallyRandom_00428c80(int);
int __cdecl GOB_GetHotSpot_00419c00(GXObject *, int, int, int *, int *);
GXObject *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
void __cdecl FUN_00420D30(void);
void __cdecl FUN_00420D40(void);
void __cdecl SND_PlaySound_0041a340(GXObject *, int);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *, GXObject *);

void __cdecl GEX_Target(GXObject *p)
{
    int hy;
    int hx;
    int x;
    int y;
    int c8;
    unsigned int bits;
    int i;
    GXObject *o;
    int r;
    if (DAT_004a0218_pState >= 0) {
        SND_PlayObSound_0041a250(p, DAT_004a0218_pState, 0x80, 0x60);
        DAT_004a0218_pState = -1;
    }
    if (DAT_00457210[p->state] & 4)
        return;
    if (p->flags2 & 0x40) {
        x = p->xpos;
        y = p->ypos;
        c8 = p->f_c8;
        hy = p->f_cc;
        FUN_0042e850(p);
        FUN_00416320_CollisionsProcessing(p);
        p->xpos = x;
        p->ypos = y;
        p->f_c8 = c8;
        p->f_cc = hy;
    } else {
        FUN_00416320_CollisionsProcessing(p);
    }
    if (gNoProcess_00455c4c == 1 && DAT_004a2878_CollisionType && !--DAT_004a2878_CollisionType) {
        gNoProcess_00455c4c -= DAT_004a2840;
        DAT_004a2840 = 0;
    }
    if ((DAT_004a2878_CollisionType && !DAT_004a0238_HealthLost) || DAT_004a2878_CollisionType)
        return;
    if (!gPlayerBubbleGlob_004a23f0)
        return;
    if (!(p->flags2 & 0x100))
        return;
    bits = DAT_00457210[p->state];
    if (p->index == DAT_00463590 && p->group == DAT_00462e40)
        return;
    if ((bits & 0x200) && (UTL_ReallyRandom32_00428c60() & 3))
        return;
    DAT_00463590 = p->index;
    DAT_00462e40 = p->group;
    for (i = 0; i < 2; i++) {
        if (!GOB_GetHotSpot_00419c00(p, 2, i, &hx, &hy))
            return;
        if (gNumPlayerBubbles_004a2854 < 10) {
            o = GOB_AddObject_004195d0(0x5c, p->xpos + hx, p->ypos + hy, gPlayerBubbleGlob_004a23f0);
            if (o) {
                o->initFunc = FUN_00420D30;
                o->drawFunc = FUN_00420D40;
                o->index = DAT_00458b88;
                o->tpage = gPlayerBubblePIXC_00458b8c;
                o->flags |= 0x800000;
                r = UTL_ReallyRandom_00428c80((bits & 0x100 ? DAT_00458b80 : DAT_00458b78) + (bits & 0x100 ? DAT_00458b84 : DAT_00458b7c)) << 16;
                if (bits & 0x400) {
                    o->f8c = -r;
                } else {
                    if (o->xpos <= p->xpos)
                        r = -r;
                    o->f80 = r;
                }
                SND_PlaySound_0041a340(p, 0xdc);
                GOB_PutObjectInfrontOfObject_00419be0(o, p);
                gNumPlayerBubbles_004a2854++;
            }
        }
    }
}
}
