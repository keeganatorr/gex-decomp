typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    unsigned char _pad54[0x64 - 0x54];
    int gob_collide;            /* 0x64 */
    unsigned char _pad68[0x6c - 0x68];
    unsigned int gob_flags;     /* 0x6c */
    int gob_size;               /* 0x70 */
    unsigned char _pad74[0x78 - 0x74];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    int gob_xVel;               /* 0x80 */
    int gob_xMax;               /* 0x84 */
    unsigned char _pad88[0x8c - 0x88];
    int gob_yVel;               /* 0x8c */
    int gob_yMax;               /* 0x90 */
    unsigned char _pad94[0x98 - 0x94];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _pada4[0xac - 0xa4];
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
} GXObject;
extern "C" {
extern void *GEX_pGlob_004a2ad4;
extern int DAT_00458c7c;
extern int DAT_00459050;
extern int DAT_00459054;
extern int DAT_00459058;
void __cdecl CollectAnItem_0041a630(int item);
void __cdecl SND_PlaySound_0041a340(GXObject *gob, int sound);
extern int DAT_0045905c;
int __cdecl UTL_ReallyRandom_00428c80(int range);
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *behind, GXObject *front);
void __cdecl GOB_Remove_00419a80(GXObject *gob);
void __cdecl RemoteClid_0041aea0(GXObject *gob)
{
    GXObject *spark;
    int i;
    int sign;
    int speed;
    CollectAnItem_0041a630((gob->gob_work2 << 16 | gob->gob_work0) << 8 | gob->gob_work1);
    DAT_00458c7c = 1;
    SND_PlaySound_0041a340(gob, 0xac);
    for (i = 0; i < 20; i++) {
        spark = GOB_AddObject_004195d0(0x5c, gob->gob_xpos + (UTL_ReallyRandom_00428c80(DAT_00459054) << 16), gob->gob_ypos + (UTL_ReallyRandom_00428c80(DAT_00459054) - 16 << 16), GEX_pGlob_004a2ad4);
        if (spark) {
            spark->gob_flags |= 0xc000;
            spark->gob_xMax = 0x7fff0000;
            spark->gob_xVel = (DAT_00459058 + UTL_ReallyRandom_00428c80(DAT_00459058)) * (UTL_ReallyRandom_00428c80(2) ? -1 : 1);
            spark->gob_yMax = 0x7fff0000;
            spark->gob_yVel = (UTL_ReallyRandom_00428c80(2) ? -1 : 1) * (UTL_ReallyRandom_00428c80(DAT_0045905c) + DAT_0045905c);
            spark->gob_currentFrameGroup = 0x20;
            spark->gob_work0 = DAT_00459050;
            spark->gob_size = 0x30;
            GOB_PutObjectInfrontOfObject_00419be0(spark, gob);
        }
    }
    if (gob->gob_work5) {
        gob->gob_work6 = 0x28;
        gob->gob_collide = 0;
    } else
        GOB_Remove_00419a80(gob);
}
}
