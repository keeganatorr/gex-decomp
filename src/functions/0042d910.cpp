// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;         /* 0x78 */
    unsigned char _pad7c[0x68];
    int gob_leftEdge;     /* 0xe4 */
    int gob_rightEdge;    /* 0xe8 */
    unsigned char _padEC[0x98];
    int gob_checkXpos;    /* 0x184 */
    int gob_checkYpos;    /* 0x188 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern int DAT_004a01e0;
extern int DAT_004a01e8;
int __cdecl FUN_0042d5c0_JumpingAboveScreen(GXObject *gob, unsigned short *block);
int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);
extern GXObject *gPlayerObject_004a27fc;
void __cdecl FUN_0042cc70_Object_unk(int reason, GXObject *object);
int __cdecl GEX_Target(GXObject *gob, unsigned short *block)
{
    unsigned int id;
    int offset;
    int height;
    if (gob != gPlayerObject_004a27fc)
        return FUN_0042d5c0_JumpingAboveScreen(gob, block);
    id = block[1];
    offset = gob->gob_checkXpos & 0x1fffff;
    if (!(id & 0xfff)) {
        DAT_004a01e0++;
        if (DAT_004a01e8 < 0)
            DAT_004a01e8 = gob->gob_checkYpos & 0xffe00000;
        gob->gob_xpos -= offset;
        gob->gob_leftEdge = gob->gob_checkXpos & 0xffe00000;
        if (gob->gob_rightEdge)
            FUN_0042cc70_Object_unk(0, gob);
        return 1;
    }
    height = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, id, offset);
    if (height && (gob->gob_checkYpos & 0x1fffff) >= height - 0x10000) {
        DAT_004a01e0++;
        if (DAT_004a01e8 < 0)
            DAT_004a01e8 = (gob->gob_checkYpos & 0xffe00000) + height - 0x10000;
        gob->gob_xpos -= offset;
        gob->gob_leftEdge = gob->gob_checkXpos & 0xffe00000;
        if (gob->gob_rightEdge)
            FUN_0042cc70_Object_unk(0, gob);
        return 1;
    }
    return 0;
}
}
