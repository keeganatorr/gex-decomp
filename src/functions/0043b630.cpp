typedef struct GXObject GXObject;
typedef void (__cdecl *GXFunc)(GXObject *);
struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x60 - 0x58];
    GXFunc gob_draw;            /* 0x60 */
    GXFunc gob_clid;            /* 0x64 */
    unsigned char _pad68[0x78 - 0x68];
    int gob_xpos;               /* 0x78 */
    unsigned char _pad7c[0x98 - 0x7c];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    unsigned char _pada8[0xb8 - 0xa8];
    int gob_health;             /* 0xb8 */
    unsigned char _padbc[0xe0 - 0xbc];
    unsigned int gob_flags2;    /* 0xe0 */
};
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern GXObject *PTR_00464e10;
extern GXObject *PTR_00464e14;
extern GXObject *PTR_00464e08;
extern GXObject *DAT_00464de8_Unk[6];
extern int DAT_00464db8;
extern int DAT_00464e18;
extern int DAT_00464e1c;
extern int DAT_00464dc0;
extern int DAT_00460030;
extern int DAT_00460028;
extern int DAT_00464e04;
extern int DAT_00464dcc;
extern int DAT_0046002c;
extern int DAT_00464dd8;
extern int DAT_00464ddc;
extern int DAT_00464dd4;
extern int DAT_00464de0;
extern int DAT_00464e00;
void __cdecl DefDoIt_004339c0(GXObject *gob);
void __cdecl FUN_0043b550_GameFuncUnk(GXObject *gob);
void __cdecl FUN_0043b570_CallsGameFunctions2(GXObject *gob);
void __cdecl GOB_PutObjectBehindObject_00419bc0(GXObject *front, GXObject *behind);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *behind, GXObject *front);
void __cdecl GEX_Target(GXObject *gob)
{
    int i;
    if (PTR_00464e10)
        PTR_00464e10->gob_xpos = CAMERA_XPos_004a2a38 + 0xa00000;
    if (!--DAT_00464db8) {
        gob->gob_draw = 0;
        gob->gob_clid = 0;
        DAT_00464db8 = 1;
        return;
    }
    if (gob->gob_work0 == 0x40) {
        DefDoIt_004339c0(PTR_00464e14);
        if (PTR_00464e14->gob_draw == FUN_0043b550_GameFuncUnk)
            return;
        switch (PTR_00464e14->gob_work1) {
        case 1:
            DAT_00464e18 = 1;
            PTR_00464e14->gob_work3 = 0xc9;
            break;
        case 2:
            for (i = 0; i < 6; i++) {
                DAT_00464de8_Unk[i]->gob_work1 = i * 43;
                DAT_00464de8_Unk[i]->gob_work2 = i * 43;
                DAT_00464de8_Unk[i]->gob_currentFrameIndex = 1;
                if (i >= 4) {
                    if (DAT_00464de8_Unk[i] && PTR_00464e14)
                        GOB_PutObjectBehindObject_00419bc0(DAT_00464de8_Unk[i], PTR_00464e14);
                } else {
                    if (DAT_00464de8_Unk[i] && PTR_00464e08)
                        GOB_PutObjectInfrontOfObject_00419be0(DAT_00464de8_Unk[i], PTR_00464e08);
                }
                DAT_00464de8_Unk[i]->gob_health = 100;
            }
            DAT_00464e1c = 0xdc0000;
            DAT_00464dc0 = 1;
            DAT_00460030 = 0x10;
            DAT_00460028 = 0x180000;
            DAT_00464e04 = 0;
            DAT_00464dcc = 0;
            DAT_0046002c = 0;
            break;
        case 3:
            for (i = 0; i < 6; i++)
                DAT_00464de8_Unk[i]->gob_health = 100;
            DAT_00464dd8 = 0xa000;
            DAT_00464ddc = 1;
            DAT_00464dd4 = 0;
            DAT_00464dcc = 0;
            DAT_00464e04 = 0;
            break;
        case 4:
            PTR_00464e14->gob_flags2 |= 0x20000;
            PTR_00464e14->gob_draw = FUN_0043b550_GameFuncUnk;
            PTR_00464e14->gob_work1 = 0;
            PTR_00464e14->gob_work2 = 0;
            DAT_00464de0 = 1;
            FUN_0043b570_CallsGameFunctions2(gob);
            DAT_00464db8 = 0x1e;
            break;
        case 5:
            DAT_00464e00 = PTR_00464e14->gob_work2;
            break;
        }
        if (PTR_00464e14->gob_work1)
            PTR_00464e14->gob_work1 = 0;
    } else
        DefDoIt_004339c0(gob);
}
}
