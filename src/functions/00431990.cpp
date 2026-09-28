typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_50;                /* 0x50 */
    unsigned char _pad54[0x18];
    unsigned int gob_flags;    /* 0x6c */
    int gob_type;              /* 0x70 */
    unsigned char _pad74[0x4];
    int gob_xpos;              /* 0x78 */
    int gob_ypos;              /* 0x7c */
    int gob_xvel;              /* 0x80 */
    int gob_xmax;              /* 0x84 */
    unsigned char _pad88[0x4];
    int gob_yvel;              /* 0x8c */
    int gob_ymax;              /* 0x90 */
    int gob_94;                /* 0x94 */
    int gob_98;                /* 0x98 */
    unsigned char _pad9c[0xc];
    int gob_a8;                /* 0xa8 */
    unsigned char _padac[0x4];
    int gob_b0;                /* 0xb0 */
    unsigned char _padb4[0x10];
    int gob_angle;             /* 0xc4 */
    int gob_scaleX;            /* 0xc8 */
    int gob_scaleY;            /* 0xcc */
} GXObject;
extern "C" {
extern int gTrigTable_0045a5c8[];
extern void *GEX_pGlob_004a2ad4;
int __cdecl abs(int);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *glob);
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
int __cdecl UTL_ReallyRandom_00428c80(int range);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *gob, GXObject *other);
void __cdecl GEX_Target(GXObject *gob, int big)
{
    int i;
    int dir;
    int speed;
    GXObject *spark;
    int a;
    int r;

    dir = (((gob->gob_flags & 0x80000000 ? 4 : 0) + 2 << 5) + (gob->gob_angle >> 16 & ~0x1f)) & 0xe0;
    speed = (abs(gob->gob_yvel) + abs(gob->gob_xvel)) >> 8;
    for (i = 6; i; i--) {
        spark = GOB_AddObject_004195d0(0x5c, gob->gob_xpos, gob->gob_ypos, GEX_pGlob_004a2ad4);
        if (spark) {
            a = ((UTL_ReallyRandom32_00428c60() & 0x3f) + dir - 0x20) & 0xff;
            r = (UTL_ReallyRandom_00428c80(4) << 16 >> 8) + speed;
            spark->gob_flags |= 0xc000;
            spark->gob_xmax = 0x7fff0000;
            spark->gob_xvel = (((a) < 0 ? -((-(a)) > 256 ? (((-(a)) % 256) > 128 ? -((((-(a)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(a)) % 256) - 128)] : gTrigTable_0045a5c8[((-(a)) % 256) - 128]) : ((((-(a)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-(a)) % 256))] : gTrigTable_0045a5c8[((-(a)) % 256)])) : ((-(a)) > 128 ? -(((-(a)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(a)) - 128)] : gTrigTable_0045a5c8[(-(a)) - 128]) : ((-(a)) > 64 ? gTrigTable_0045a5c8[128 - (-(a))] : gTrigTable_0045a5c8[-(a)]))) : ((a) > 256 ? (((a) % 256) > 128 ? -((((a) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((a) % 256) - 128)] : gTrigTable_0045a5c8[((a) % 256) - 128]) : ((((a) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((a) % 256))] : gTrigTable_0045a5c8[((a) % 256)])) : ((a) > 128 ? -(((a) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((a) - 128)] : gTrigTable_0045a5c8[(a) - 128]) : ((a) > 64 ? gTrigTable_0045a5c8[128 - (a)] : gTrigTable_0045a5c8[a])))) >> 8) * r >> 2;
            spark->gob_ymax = 0x7fff0000;
            spark->gob_yvel = -((((a + 64) < 0 ? -((-(a + 64)) > 256 ? (((-(a + 64)) % 256) > 128 ? -((((-(a + 64)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(a + 64)) % 256) - 128)] : gTrigTable_0045a5c8[((-(a + 64)) % 256) - 128]) : ((((-(a + 64)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-(a + 64)) % 256))] : gTrigTable_0045a5c8[((-(a + 64)) % 256)])) : ((-(a + 64)) > 128 ? -(((-(a + 64)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(a + 64)) - 128)] : gTrigTable_0045a5c8[(-(a + 64)) - 128]) : ((-(a + 64)) > 64 ? gTrigTable_0045a5c8[128 - (-(a + 64))] : gTrigTable_0045a5c8[-(a + 64)]))) : ((a + 64) > 256 ? (((a + 64) % 256) > 128 ? -((((a + 64) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((a + 64) % 256) - 128)] : gTrigTable_0045a5c8[((a + 64) % 256) - 128]) : ((((a + 64) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((a + 64) % 256))] : gTrigTable_0045a5c8[((a + 64) % 256)])) : ((a + 64) > 128 ? -(((a + 64) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((a + 64) - 128)] : gTrigTable_0045a5c8[(a + 64) - 128]) : ((a + 64) > 64 ? gTrigTable_0045a5c8[128 - (a + 64)] : gTrigTable_0045a5c8[a + 64])))) >> 8) * r) >> 2;
            spark->gob_94 = 0x4000;
            spark->gob_50 = big ? 0x20 : 0x1b;
            spark->gob_98 = 6;
            spark->gob_type = 0x36;
            spark->gob_scaleX = 0x20000;
            spark->gob_a8 = -0x4000;
            spark->gob_scaleY = 0x20000;
            spark->gob_b0 = -0x4000;
            GOB_PutObjectInfrontOfObject_00419be0(spark, gob);
        }
    }
}
}
