typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_objectLoadData;   /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x5c - 0x58];
    int gob_5c;                 /* 0x5c */
    int gob_draw;               /* 0x60 */
    int gob_64;                 /* 0x64 */
    unsigned char _pad68[0x78 - 0x68];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char _pad9c[0xd0 - 0x9c];
    int gob_scale;              /* 0xd0 */
} GXObject;
extern "C" {
extern GXObject *PTR_00464e14;
extern GXObject *PTR_00464e08;
extern int PTR_00464e10;
extern int DAT_00464dc0;
extern int DAT_00464e04;
extern int DAT_00464dcc;
extern int DAT_00464e24;
extern int DAT_00464ddc;
extern int DAT_00464dc8;
extern int DAT_00464e20;
extern int DAT_00464e1c;
extern int DAT_00464dd4;
extern int DAT_00464dd8;
extern int DAT_00464dbc;
extern int DAT_00464dc4;
extern int DAT_0046002c;
extern int DAT_00460030;
extern int DAT_00464e0c;
extern int DAT_00464e00;
extern int DAT_00464e18;
extern int DAT_00464de0;
extern int DAT_00460028;
extern int DAT_00464db8;
GXObject *__cdecl GOB_AddObject_004195d0(int type, int x, int y, void *loadData);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *behind, GXObject *front);
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *gob, int priority);
void __cdecl DefInit_004335f0(GXObject *gob, int flag);
void __cdecl GEX_Target(GXObject *gob, int flag)
{
    if (gob->gob_work0 == 0x40) {
        if (flag)
            PTR_00464e14 = 0;
        else {
            gob->gob_scale = 0x30000000;
            gob->gob_currentFrameGroup = 0;
            gob->gob_currentFrameIndex = 0;
            PTR_00464e14 = GOB_AddObject_004195d0(0x102, gob->gob_xpos, gob->gob_ypos, gob->gob_objectLoadData);
            if (PTR_00464e14) {
                PTR_00464e14->gob_currentFrameGroup = 0;
                PTR_00464e14->gob_currentFrameIndex = 0;
                PTR_00464e14->gob_5c = 0;
                gob->gob_draw = 0;
                gob->gob_64 = 0;
                PTR_00464e14->gob_scale = 0x30000000;
            }
            if (PTR_00464e08 && PTR_00464e14)
                GOB_PutObjectInfrontOfObject_00419be0(PTR_00464e08, PTR_00464e14);
            DAT_00464dc0 = 0;
            DAT_00464e04 = 0;
            DAT_00464dcc = 0;
            DAT_00464e24 = 0;
            DAT_00464ddc = 0;
            DAT_00464dc8 = 0;
            DAT_00464e20 = 0;
            DAT_00464e1c = 0;
            DAT_00464dd4 = 0;
            DAT_00464dd8 = 0;
            DAT_00464dbc = 0;
            DAT_00464dc4 = 0;
            DAT_0046002c = 0;
            DAT_00460030 = 0;
            DAT_00464e0c = 0;
            DAT_00464e00 = 0;
            DAT_00464e18 = 0;
            DAT_00464de0 = 0;
            DAT_00460028 = 0x180000;
            DAT_00464db8 = 0;
            GOB_SetObjectDisplayPriority_00419b80(gob, 0);
            PTR_00464e10 = 0;
        }
    }
    if (!flag)
        DefInit_004335f0(gob, 0);
}
}
