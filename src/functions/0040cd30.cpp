typedef struct VoiceAnim {
    int group;
    int limit;
    int value;
    int step;
} VoiceAnim;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x78 - 0x58];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x9c - 0x80];
    char *gob_text;             /* 0x9c */
    unsigned char _pada0[0xa8 - 0xa0];
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    int gob_work6;              /* 0xb0 */
    unsigned char _padb4[0xe0 - 0xb4];
    unsigned int gob_flags2;    /* 0xe0 */
} GXObject;
extern "C" {
extern int DAT_00456168;
extern int DAT_00462c68;
extern int DAT_00462c6c;
extern void *GEX_pGlob_004a2ad4;
void __cdecl VFX_Reset_0041f840(void);
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int situation);
void __cdecl VFX_Play_0041fa80(int situation);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl PrintWithFont_0040bc70(int x, int y, int a, int b, int c, int d, char *text, int e);
void __cdecl GEX_Target(GXObject *gob)
{
    VoiceAnim *anims;
    int situation;
    int x;
    int y;
    void *loadData;
    int group;
    int frame;
    anims = (VoiceAnim *)((char *)&DAT_00456168 - 8);
    gob->gob_flags2 |= 0x1000000;
    if (DAT_00462c68 >= 0xd2) {
        if (gob->gob_work5 != 3)
            situation = 0x14;
        else {
            switch (gob->gob_work4) {
            case 0xc:
            case 0x70:
                situation = anims[gob->gob_work6].value & 0x10000 ? 4 : 5;
                break;
            case 0xe:
                situation = 3;
                break;
            case 0x10:
                situation = 2;
                break;
            case 0x12:
                situation = 6;
                break;
            }
        }
        if (situation != DAT_00462c6c) {
            VFX_Reset_0041f840();
            DAT_00462c6c = situation;
        }
        VSIT_PlayVoiceSituation_0041f8c0(situation);
        VFX_Play_0041fa80(situation);
        DAT_00462c68 = 0;
    } else
        DAT_00462c68++;
    group = gob->gob_currentFrameGroup;
    frame = gob->gob_currentFrameIndex;
    x = gob->gob_xpos;
    y = gob->gob_ypos;
    loadData = gob->gob_objectLoadData;
    gob->gob_objectLoadData = GEX_pGlob_004a2ad4;
    gob->gob_currentFrameGroup = anims[gob->gob_work6].group;
    gob->gob_currentFrameIndex = anims[gob->gob_work6].value >> 16;
    gob->gob_xpos = 0xff0000;
    gob->gob_ypos = 0xc80000;
    GOB_DisplayObject_00444590(gob);
    gob->gob_objectLoadData = loadData;
    gob->gob_currentFrameGroup = group;
    gob->gob_currentFrameIndex = frame;
    gob->gob_xpos = x;
    gob->gob_ypos = y;
    anims[gob->gob_work6].value += anims[gob->gob_work6].step;
    if (anims[gob->gob_work6].limit < anims[gob->gob_work6].value >> 16)
        anims[gob->gob_work6].value = 0;
    PrintWithFont_0040bc70(gob->gob_xpos, gob->gob_ypos, 0x5a, 0, 0xd4, -1, gob->gob_text, 0);
}
}
