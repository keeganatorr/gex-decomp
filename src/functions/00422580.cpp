typedef struct TongueVel { int xVel; int yVel; } TongueVel;
typedef struct TongueAim { int xVel; int yVel; int angle; } TongueAim;
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0x80 - 0x74];
    int gob_xVel;               /* 0x80 */
    int gob_xMax;               /* 0x84 */
    unsigned char _pad88[0x8c - 0x88];
    int gob_yVel;               /* 0x8c */
    int gob_yMax;               /* 0x90 */
    int gob_yAccel;             /* 0x94 */
    unsigned char _pad98[0xc4 - 0x98];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern TongueVel DAT_0045aa10[];
extern TongueAim DAT_0045a890[];
extern TongueAim DAT_0045a950[];
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *gob, int priority);
void __cdecl GOB_PutObjectBehindObject_00419bc0(GXObject *front, GXObject *behind);
extern GXObject *PTR_004a2838;
void __cdecl FUN_00422500_pStateUnk_Lash_Inner(GXObject *tongue);
void __cdecl FUN_00422580_pStateUnk_Lash_Inner(GXObject *gex, GXObject *tongue)
{
    int dir;
    int angle;
    GOB_SetObjectDisplayPriority_00419b80(tongue, gex->gob_flags & 0xf);
    GOB_PutObjectBehindObject_00419bc0(tongue, gex);
    tongue->gob_xMax = 0x7fffffff;
    tongue->gob_yMax = 0x7fffffff;
    switch (gex->gob_state) {
    default:
        tongue->gob_angle = gex->gob_flags & 0x80000000 ? 0x800000 : 0;
        tongue->gob_xVel = gex->gob_flags & 0x80000000 ? 0x10000 : -0x10000;
        tongue->gob_yVel = 0;
        FUN_00422500_pStateUnk_Lash_Inner(tongue);
        tongue->gob_xVel += gex->gob_xVel;
        if (PTR_004a2838 == tongue)
            tongue->gob_yAccel = 0x14000;
        return;
    case 0x14:
    case 0x27:
        tongue->gob_angle = 0x400000;
        tongue->gob_xVel = 0;
        tongue->gob_yVel = -0x10000;
        FUN_00422500_pStateUnk_Lash_Inner(tongue);
        return;
    case 0x2f:
        angle = gex->gob_angle;
        tongue->gob_angle = (angle + 0x400000) & 0xff0000;
        tongue->gob_xVel = DAT_0045aa10[angle >> 22].xVel;
        tongue->gob_yVel = DAT_0045aa10[angle >> 22].yVel;
        FUN_00422500_pStateUnk_Lash_Inner(tongue);
        return;
    case 0x3a:
        dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
        tongue->gob_xVel = DAT_0045a890[dir].xVel;
        tongue->gob_yVel = DAT_0045a890[dir].yVel;
        tongue->gob_angle = DAT_0045a890[dir].angle;
        FUN_00422500_pStateUnk_Lash_Inner(tongue);
        return;
    case 0x3b:
        dir = (gex->gob_flags & 0x80000000 ? 8 : 0) | gex->gob_angle >> 21;
        tongue->gob_xVel = DAT_0045a950[dir].xVel;
        tongue->gob_yVel = DAT_0045a950[dir].yVel;
        tongue->gob_angle = DAT_0045a950[dir].angle;
        FUN_00422500_pStateUnk_Lash_Inner(tongue);
        return;
    }
}
}
