// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;  /* 0xc */
    unsigned char _pad10[0x68];
    int gob_xpos;              /* 0x78 */
    int gob_ypos;              /* 0x7c */
    unsigned char _pad80[0x10];
    int gob_maxyVel;           /* 0x90 */
    int gob_yAccl;             /* 0x94 */
    int gob_work0;             /* 0x98 */
    unsigned char _pad9c[0x10];
    int gob_work5;             /* 0xac */
    int gob_work6;             /* 0xb0 */
    unsigned int gob_work7;    /* 0xb4 */
} GXObject;
extern "C" {
extern int DAT_0045b7a8;
extern int DAT_0045b7ac;
extern void *GEX_pGlob_004a2ad4;
extern int DAT_0045b7d0;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int gHitpoints2_00456afc;
extern int gHitpoints_004a281c;
unsigned int __cdecl UTL_ReallyRandom32_00428c60(void);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int situation);
void __cdecl GEX_Target(GXObject *gob)
{
    if (gob->gob_work7 & 3) {
        gob->gob_yAccl = DAT_0045b7a8;
        gob->gob_maxyVel = DAT_0045b7ac;
    }
    gob->gob_objectLoadData = GEX_pGlob_004a2ad4;
    if (DAT_0045b7d0) {
        gob->gob_work5 = gob->gob_xpos - CAMERA_XPos_004a2a38;
        gob->gob_work6 = gob->gob_ypos - CAMERA_YPos_004a2a1c;
    }
    switch (gob->gob_work0) {
    case 1:
        if (UTL_ReallyRandom32_00428c60() & 1)
            VSIT_PlayVoiceSituation_0041f8c0(0x4b);
        else
            VSIT_PlayVoiceSituation_0041f8c0(0x5c);
        break;
    case 2:
        if (UTL_ReallyRandom32_00428c60() & 1)
            VSIT_PlayVoiceSituation_0041f8c0(0x5d);
        else
            VSIT_PlayVoiceSituation_0041f8c0(0x4c);
        break;
    case 4:
        VSIT_PlayVoiceSituation_0041f8c0(0x4e);
        break;
    case 6:
        VSIT_PlayVoiceSituation_0041f8c0(0x52);
        break;
    case 10:
        break;
    }
    if (gHitpoints_004a281c < gHitpoints2_00456afc)
        VSIT_PlayVoiceSituation_0041f8c0(0x45);
}
}
