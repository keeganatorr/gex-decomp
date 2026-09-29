// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x7c];
    int gob_ypos;         /* 0x7c */
    unsigned char _pad80[0x6c];
    int gob_topEdge;      /* 0xec */
    int gob_bottomEdge;   /* 0xf0 */
    unsigned char _padF4[0x90];
    int gob_checkXpos;    /* 0x184 */
    int gob_checkYpos;    /* 0x188 */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);
void __cdecl FUN_0042cc70_Object_unk(int reason, GXObject *object);
int __cdecl FUN_0042d6e0_ObjCallUnk(GXObject *gob, unsigned short *block)
{
    unsigned int id;
    unsigned int xoffset;
    int yoffset;
    int height;
    id = block[1];
    xoffset = gob->gob_checkXpos & 0x1fffff;
    yoffset = gob->gob_checkYpos & 0x1fffff;
    if (!(id & 0xfff)) {
        gob->gob_ypos -= yoffset + 1;
        gob->gob_topEdge = (gob->gob_checkYpos & 0xffe00000) - 1;
        if (gob->gob_bottomEdge)
            FUN_0042cc70_Object_unk(0, gob);
        return 1;
    }
    height = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, id, xoffset);
    if (height && height - 0x10000 <= yoffset) {
        gob->gob_ypos += height - yoffset;
        gob->gob_topEdge = (gob->gob_checkYpos & 0xffe00000) + height;
        if (gob->gob_bottomEdge)
            FUN_0042cc70_Object_unk(0, gob);
        return 1;
    }
    return 0;
}
}
