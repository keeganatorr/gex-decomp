// Field names from Ghidra's GXObject/GXLoadObject layouts (evidence, not proof).
typedef struct GXObFrame GXObFrame;
typedef struct GXLoadObject {
    GXObFrame ***gxlob_anims;       /* 0x0 */
    unsigned char **gxlob_scripts;  /* 0x4 */
    unsigned int gxlob_version;     /* 0x8 */
    int gxlob_numAnims;             /* 0xc */
    int *gxlob_numFrames;           /* 0x10 */
} GXLoadObject;
typedef struct GXObject {
    unsigned char _pad0[8];
    int gob_type;                       /* 0x8 */
    GXLoadObject *gob_objectLoadData;   /* 0xc */
    unsigned char _pad10[0x40];
    int gob_currentFrameGroup;          /* 0x50 */
    int gob_currentFrameIndex;          /* 0x54 */
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
extern char s_ERROR_currentFrameGroup_out_of_r_00458fb0[];
extern char s_ERROR_currentFrameIndex_out_of_r_00458f78[];
void __cdecl assertfail_00405350(const char *format, ...);
GXObFrame *__cdecl GEX_Target(GXObject *gob)
{
    GXObFrame *frame;
    GXLoadObject *lob;
    frame = 0;
    lob = gob->gob_objectLoadData;
    if (lob && gob->gob_currentFrameIndex >= 0 && gob->gob_currentFrameGroup >= 0) {
        if (lob->gxlob_version) {
            if (gob->gob_currentFrameGroup >= lob->gxlob_numAnims) {
                assertfail_00405350(s_ERROR_currentFrameGroup_out_of_r_00458fb0, gob->gob_type);
                return frame;
            }
            if (gob->gob_currentFrameIndex > lob->gxlob_numFrames[gob->gob_currentFrameGroup]) {
                assertfail_00405350(s_ERROR_currentFrameIndex_out_of_r_00458f78, gob->gob_type);
                return frame;
            }
        }
        frame = lob->gxlob_anims[gob->gob_currentFrameGroup][gob->gob_currentFrameIndex];
        if (!frame) {
            gob->gob_currentFrameIndex = 0;
            frame = lob->gxlob_anims[gob->gob_currentFrameGroup][0];
        }
    }
    return frame;
}
}
