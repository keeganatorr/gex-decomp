typedef struct GXObject {
    unsigned char _pad0[0x6c];
    int gob_flags;     /* 0x6c */
    int gob_type;      /* 0x70 */
    unsigned char _pad74[0x50];
    int gob_angle;     /* 0xc4 */
    unsigned char _padC8[0x48];
    int gob_110;       /* 0x110 */
} GXObject;
extern "C" {
extern int DAT_004a0264_PowerUp_SuperSpeed;
extern unsigned int DAT_00457210[];
extern int DAT_00456b08[];
extern int DAT_00456c70[];
extern int DAT_00456dd8[];
extern int INT_ARRAY_00456f40[];
extern int DAT_00457e98[];
extern int DAT_00455b94;
extern int DAT_00455b98;
extern int DAT_004a2984_CamX3;
extern int DAT_004a2938_CamY3;
extern int DAT_00462d34;
extern int DAT_00462e08;
extern unsigned int DAT_00462d30;
extern int DAT_00457e80;
extern int DAT_00462d84;
extern volatile int DAT_00462d78;
extern int DAT_00455b9c;
extern int DAT_00455ba0;
extern int DAT_00455ba4;
extern int DAT_00455ba8;
extern int DAT_00455bac;
extern int DAT_00455bb0;
extern int DAT_00455bb4;
extern int DAT_00455bb8;
extern int DAT_00455bbc;
extern int DAT_00455bc0;
extern int DAT_00455bc4;
extern int DAT_00455bc8;
extern int DAT_00455bcc;
extern int DAT_00455bd0;
extern int DAT_00455bd4;
extern int DAT_00455bd8;
extern int DAT_00455bdc;
extern int DAT_00455be0;
extern int DAT_004a2930;
extern int DAT_00457ed8;
void __cdecl FUN_00410d10_CollisionInner(int value);

void __cdecl FUN_00410dc0_CollisionInner(GXObject *gob)
{
    unsigned int index;

    DAT_00455b94 = DAT_00456b08[gob->gob_type]
        + (DAT_004a0264_PowerUp_SuperSpeed && (DAT_00457210[gob->gob_type] & 1) ? DAT_00456c70[gob->gob_type] : 0);
    DAT_00455b98 = DAT_00456c70[gob->gob_type]
        + (DAT_004a0264_PowerUp_SuperSpeed && (DAT_00457210[gob->gob_type] & 1) ? DAT_00456b08[gob->gob_type] : 0);
    DAT_004a2984_CamX3 = DAT_00456dd8[gob->gob_type];
    DAT_004a2938_CamY3 = INT_ARRAY_00456f40[gob->gob_type];
    DAT_00462d34 = gob->gob_type;
    DAT_00462e08 = gob->gob_110;
    DAT_00462d30 = DAT_00457210[gob->gob_type] >> 28;
    switch (DAT_00462d30) {
    case 0:
        if (DAT_00462d34 == 9)
            DAT_00457e80 = 0;
        else if (!DAT_00457e80)
            DAT_00457e80 = 1;
        DAT_00462d84 = 0;
        DAT_00462d78 = -1;
        DAT_00455b9c = 0xe00000;
        DAT_00455ba0 = 0xe80000;
        DAT_00455ba4 = 0x580000;
        DAT_00455ba8 = 0x600000;
        if (DAT_00457e80 == 1) {
            DAT_00455bac = 0xb40000;
            DAT_00455bb0 = 0xb40000;
        } else {
            DAT_00455bac = 0x780000;
            DAT_00455bb0 = 0xb40000;
        }
        DAT_00455bbc = DAT_00455bac;
        DAT_00455bc0 = DAT_00455bb0;
        DAT_004a2930 = DAT_00455bc0;
        break;
    case 1:
        DAT_00462d84 = 0;
        DAT_00462d78 = -1;
        DAT_00455b9c = 0xe00000;
        DAT_00455ba0 = 0xe80000;
        DAT_00455ba4 = 0x580000;
        DAT_00455ba8 = 0x600000;
        DAT_00455bac = 0x780000;
        DAT_00455bb0 = 0xb40000;
        DAT_00455bbc = 0x780000;
        DAT_00455bc0 = 0xb40000;
        DAT_004a2930 = 0xb40000;
        break;
    case 2:
        DAT_00457e80 = 0;
        index = (gob->gob_flags & 0x80000000 ? 8 : 0) | gob->gob_angle >> 21;
        DAT_00462d84--;
        if (index != DAT_00462d78) {
            if (DAT_00462d84 <= 0)
                DAT_00462d78 = index;
            else
                index = DAT_00462d78;
        } else
            DAT_00462d84 = 0;
        FUN_00410d10_CollisionInner(DAT_00457e98[index]);
        DAT_004a2930 = 0;
        break;
    case 3:
        DAT_00457e80 = 0;
        DAT_00462d84 = 0;
        DAT_00455b9c = 0x960000;
        DAT_00455ba0 = 0xaa0000;
        DAT_00455ba4 = 0x960000;
        DAT_00455ba8 = 0xaa0000;
        DAT_00455bac = 0x960000;
        DAT_00455bb0 = 0xaa0000;
        DAT_00455bb4 = 0x960000;
        DAT_00455bb8 = 0xaa0000;
        DAT_00455bbc = 0x960000;
        DAT_00455bc0 = 0xaa0000;
        DAT_00462d78 = -1;
        DAT_004a2930 = 0;
        break;
    case 4:
        DAT_00457e80 = 0;
        DAT_00462d84 = 0;
        DAT_00462d78 = -1;
        DAT_00455b9c = 0xe00000;
        DAT_00455ba0 = 0xe80000;
        DAT_00455ba4 = 0x580000;
        DAT_00455ba8 = 0x600000;
        DAT_00455bac = 0x780000;
        DAT_00455bb0 = 0xb40000;
        DAT_00455bbc = 0x780000;
        DAT_00455bc0 = 0xb40000;
        DAT_004a2930 = 0xb40000;
        break;
    case 5:
        DAT_00457e80 = 0;
        DAT_004a2930 = 0;
        break;
    }
    if (DAT_00457ed8) {
        DAT_00455bc4 = DAT_00455b9c;
        DAT_00455bc8 = DAT_00455ba0;
        DAT_00455bcc = DAT_00455ba4;
        DAT_00455bd0 = DAT_00455ba8;
        DAT_00455bd4 = DAT_00455bac;
        DAT_00455bd8 = DAT_00455bb0;
        DAT_00455bdc = DAT_00455bac;
        DAT_00455be0 = DAT_00455bb0;
    }
}
}
