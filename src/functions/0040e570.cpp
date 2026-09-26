typedef struct PalData { unsigned char _pad0[0xc]; unsigned short *colors; } PalData;
typedef struct FrameImage { unsigned char _pad0[0x18]; PalData **pal; } FrameImage;
typedef struct FrameGroup { FrameImage *image; } FrameGroup;
typedef struct LoadData { FrameGroup **groups; } LoadData;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    LoadData *gob_objectLoadData;    /* 0x0c */
    unsigned char _pad10[0x50 - 0x10];
    int gob_currentFrameGroup;       /* 0x50 */
    int gob_currentFrameIndex;       /* 0x54 */
    unsigned char _pad58[0x78 - 0x58];
    int gob_x;                       /* 0x78 */
    int gob_y;                       /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    int gob_state;                   /* 0x98 */
    int gob_phase;                   /* 0x9c */
    unsigned char _pada0[0xa4 - 0xa0];
    int gob_yOffset;                 /* 0xa4 */
    unsigned char _pada8[0xc0 - 0xa8];
    unsigned short *gob_palette;     /* 0xc0 */
    unsigned char _padc4[0x118 - 0xc4];
    int gob_palHeader;               /* 0x118 */
    unsigned short gob_pal[16];      /* 0x11c */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int level_004a2964;
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    unsigned short *src;
    unsigned short *dst;
    unsigned short *palette;
    unsigned short *pal;
    unsigned short t;
    int i;
    int y;
    int frame;
    src = gob->gob_objectLoadData->groups[gob->gob_currentFrameGroup]->image->pal[0]->colors;
    pal = gob->gob_pal;
    ((int *)pal)[-1] = 0xffffff00;
    *pal = *src++;
    dst = pal + 1;
    if (gob->gob_state) {
        gob->gob_state = 0;
        for (i = 15; i; i--)
            *dst++ = *src++;
    } else {
        for (i = 2; i; i--) {
            t = dst[10];
            dst[10] = dst[8];
            dst[8] = dst[6];
            dst[6] = dst[4];
            dst[4] = dst[2];
            dst[2] = dst[0];
            dst[0] = t;
            dst++;
        }
    }
    palette = gob->gob_palette;
    y = gob->gob_y;
    gob->gob_palette = pal;
    frame = gob->gob_currentFrameIndex;
    gob->gob_y = y - gob->gob_phase - 0x80000;
    if (level_004a2964 == 0x86)
        gob->gob_y -= 0x100000;
    gob->gob_currentFrameIndex = 0;
    gob->gob_x = 0x9f0000;
    GOB_DisplayObject_00444590(gob);
    gob->gob_y = y;
    gob->gob_currentFrameIndex = frame;
    gob->gob_palette = palette;
    if (gob->gob_yOffset)
        gob->gob_y = gob->gob_yOffset + y;
    gob->gob_phase += 0x70000;
    gob->gob_phase &= 0x3f0000;
}
}
