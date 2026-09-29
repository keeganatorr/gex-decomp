// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;     /* 0x78 */
    int gob_ypos;     /* 0x7c */
    unsigned char _pad1[0x48];
    int gob_xScale;   /* 0xc8 */
    int gob_yScale;   /* 0xcc */
    unsigned char _pad2[0x10];
    int gob_flags2;   /* 0xe0 */
} GXObject;
extern "C" {
extern void __cdecl FUN_0042e850(GXObject *);
extern void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *);
void __cdecl ob230Draw_00430d70(GXObject *gob)
{
    int xpos = gob->gob_xpos;
    int ypos = gob->gob_ypos;
    int xScale = gob->gob_xScale;
    int yScale = gob->gob_yScale;
    gob->gob_flags2 |= 0x40;
    FUN_0042e850(gob);
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
    gob->gob_xpos = xpos;
    gob->gob_ypos = ypos;
    gob->gob_xScale = xScale;
    gob->gob_yScale = yScale;
}
}
