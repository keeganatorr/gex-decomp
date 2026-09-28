typedef struct GXObject {
    unsigned char _pad0[0xc];
    void *gob_glob;             /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char _pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    int gob_work3;              /* 0xa4 */
    int gob_work4;              /* 0xa8 */
    int gob_work5;              /* 0xac */
    unsigned char _padb0[0xbc - 0xb0];
    int gob_rect;               /* 0xbc */
    void *gob_plut;             /* 0xc0 */
    int gob_angle;              /* 0xc4 */
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char _padd0[0x204 - 0xd0];
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern void *GEX_pGlob_004a2ad4;
extern unsigned char PTR_DAT_0045b210[];
int __cdecl UTL_ReallyRandom_00428c80(int range);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *gob);
void __cdecl GOB_ResetPos_004317e0(GXObject *gob);
void __cdecl RezOutAll_00437330(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    GXObject temp;
    if (gob->gob_work1 < 0) {
        gob->gob_work1 = UTL_ReallyRandom_00428c80(4);
        gob->gob_work0 = !gob->gob_work0;
    } else
        gob->gob_work1--;
    temp.gob_xpos = gob->gob_work4 + gob->gob_xpos;
    temp.gob_ypos = gob->gob_ypos + gob->gob_work5;
    temp.gob_currentFrameIndex = 0;
    temp.gob_currentFrameGroup = 0x1e;
    temp.gob_glob = GEX_pGlob_004a2ad4;
    temp.gob_xScale = 0x10000;
    temp.gob_flags = 0;
    temp.gob_rect = 0x1f801f00;
    temp.gob_angle = 0;
    temp.gob_yScale = 0x10000;
    if (gob->gob_work0)
        temp.gob_plut = (PTR_DAT_0045b210 + 0xc);
    else
        temp.gob_plut = (PTR_DAT_0045b210 + 0x34);
    GOB_DisplayObject_00444590(&temp);
    if (!(gob->gob_work2 & 3))
        gob->gob_plut = 0;
    else {
        gob->gob_plut = (PTR_DAT_0045b210 + 0x34);
        if (!gob->gob_work0)
            gob->gob_plut = (PTR_DAT_0045b210 + 0xc);
    }
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
    if (--gob->gob_work2 <= 0) {
        GOB_ResetPos_004317e0(gob);
        RezOutAll_00437330(gob);
    }
}
}
