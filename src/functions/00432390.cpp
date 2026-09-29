typedef struct Frame {
    char pad0[0x10];
    int *boxes;
} Frame;
typedef struct GXObject GXObject;
struct GXObject {
    char pad0[0x50];
    int group;
    int index;
    char pad58[0x14];
    unsigned int flags;
    int state;
    char pad74[4];
    int xpos;
    int ypos;
    char pad80[4];
    int f84;
    char pad88[4];
    int yVel;
    int maxyVel;
    char pad94[4];
    int work0;
    char pad9c[0x28];
    int angle;
    char padc8[0x18];
    unsigned int flags2;
    char pade4[0x8c];
    unsigned int *attack;
    unsigned int *defend;
    GXObject *other;
};

extern "C" {
extern void *GEX_pGlob_004a2ad4;
int __cdecl CLD_CheckAboveContour_0041e9d0(GXObject *, int *);
void __cdecl SND_PlaySound_0041a340(GXObject *, int);
void __cdecl AddVisualScoreFromTable_0041be80(GXObject *, int, int);
void __cdecl FUN_004322b0(GXObject *, int);
Frame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *);
int __cdecl UTL_ReallyRandom_00428c80(int);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
GXObject *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *, GXObject *);
void __cdecl FUN_00431990(GXObject *, int);
void __cdecl GOB_RemoveObject_00419520(GXObject *);

void __cdecl ob93Clid_00432390(GXObject *g, int *hit)
{
    int *box;
    int y0;
    int x0;
    int n;
    unsigned int fx;
    unsigned int fy;
    unsigned int a;
    int dir;
    GXObject *o;
    GXObject *p;
    Frame *fr;
    int w;
    int h;
    int t;
    if (!*hit || CLD_CheckAboveContour_0041e9d0(g, hit))
        return;
    a = *g->defend & 0xffff;
    if (a == 2 || a == 0) {
        dir = (((g->flags & 0x80000000 ? 4 : 0) + 2 << 5) + (g->angle >> 21 << 5)) & 0xe0;
        o = g->other;
        o->flags2 |= 0x8000;
        if (o->flags & 0x400000) {
            if (!(o->flags2 & 0x10000)) {
                SND_PlaySound_0041a340(g, 0x7f);
                AddVisualScoreFromTable_0041be80(o, 0, 0);
                FUN_004322b0(o, dir);
            }
            if ((o->flags & 0x400000) && !(o->flags2 & 0x10000) && (fr = GOB_GetCurrentFrameWithDefault_0041a380(o)) != 0) {
                fx = o->flags & 0x80000000;
                fy = o->flags & 0x40000000;
                box = fr->boxes;
                while (box && box[0] != (int)0x80000000) {
                    x0 = fx ? -box[2] : box[0];
                    w = fx ? -box[0] : box[2];
                    y0 = fy ? -box[3] : box[1];
                    h = fy ? -box[1] : box[3];
                    w = (w - x0 + 1) >> 16;
                    h = (h - y0 + 1) >> 16;
                    n = (h + 8) * (w + 8) / 64;
                    n = n < 3 ? n : 3;
                    for (; n > 0; n--) {
                        p = GOB_AddObject_004195d0(0x5c, (UTL_ReallyRandom_00428c80(w) << 16) + o->xpos + x0,
                                                   ((UTL_ReallyRandom_00428c80(h) + 5) << 16) + o->ypos + y0, GEX_pGlob_004a2ad4);
                        if (p) {
                            p->flags |= 0x8000;
                            p->f84 = o->f84;
                            p->maxyVel = 0x7fffffff;
                            p->yVel = -0x3000;
                            p->group = 0x1c;
                            p->index = UTL_ReallyRandom32_00428c60() & 7;
                            p->work0 = 3;
                            p->state = 0x30;
                            GOB_PutObjectInfrontOfObject_00419be0(p, o);
                        }
                    }
                    box += 4;
                }
            }
        }
    }
    FUN_00431990(g, 0);
    GOB_RemoveObject_00419520(g);
}
}
