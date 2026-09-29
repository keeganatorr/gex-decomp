typedef struct GXObject {
    unsigned char pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char pad80[0xc8 - 0x80];
    int gob_xScale;             /* 0xc8 */
    int gob_yScale;             /* 0xcc */
    unsigned char padd0[0xdc - 0xd0];
    int gob_glue;               /* 0xdc */
    unsigned int gob_flags2;    /* 0xe0 */
} GXObject;

typedef struct HeightMap {
    int unk0;
    int base;                   /* 0x04 */
    int count;                  /* 0x08 */
    unsigned char heights[1];   /* 0x0c */
} HeightMap;

typedef struct Frame {
    int left;                   /* 0x00 */
    int top;                    /* 0x04 */
    int right;                  /* 0x08 */
    int bottom;                 /* 0x0c */
    int unk10[4];
    HeightMap *heights;         /* 0x20 */
} Frame;

typedef struct TileAttribute {
    unsigned int flags;
    int rest[7];
} TileAttribute;

extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern TileAttribute DAT_0045B9A0[];
int __cdecl GetGlueDist_0040f1d0(void *level, GXObject *gob);
void __cdecl FUN_00420fa0_xpos_movement(GXObject *gob);
Frame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *gob);
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *level, int x, int y);
unsigned short *__cdecl GOB_GetBlockAddress_00419fe0(void *level, int x, int y);
int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);

void __cdecl FUN_00437f40(GXObject *gob, int dx)
{
    Frame *frame;
    int top;
    int first;
    HeightMap *hm;
    unsigned int headBlock;
    unsigned int head;
    int contour;
    unsigned int block;
    int glue;
    int last;
    unsigned int type;
    unsigned int px;
    int side;
    unsigned int wall;
    unsigned int flip;

    gob->gob_xpos += dx;
    if (!gob->gob_glue && dx) {
        glue = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, gob);
        if (glue > -0x100000 && glue < 0x100000) {
            gob->gob_glue = 0;
            gob->gob_ypos += glue;
        } else {
            gob->gob_glue = glue;
            gob->gob_flags2 |= 0x1000;
        }
    }
    if (gob->gob_flags2 & 0x4000)
        FUN_00420fa0_xpos_movement(gob);
    if (!(gob->gob_flags & 0x10000))
        return;
    if (gob->gob_flags & 0x1f000000)
        return;
    if (!dx)
        return;
    flip = gob->gob_flags & 0x80000000;
    frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
    if (frame->left & 2) {
        hm = frame->heights;
        first = flip ? hm->count - 1 : 0;
        last = flip ? 0 : hm->count - 1;
        if (dx < 0)
            last = first;
        top = ((hm->heights[last] - 1) << 16) + hm->base;
    } else if (gob->gob_flags & 0x40000000)
        top = -frame->bottom;
    else
        top = frame->top;
    if (dx >= 0)
        side = flip ? -frame->left : frame->right;
    else
        side = flip ? -frame->right : frame->left;
    if (gob->gob_flags2 & 0x400000) {
        top = (gob->gob_yScale >> 8) * (top >> 8);
        side = (gob->gob_xScale >> 8) * (side >> 8);
    }
    wall = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos + top)].flags;
    head = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos - 0x10000)].flags;
    block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos + top)[1];
    headBlock = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos - 0x10000)[1];
    px = gob->gob_xpos + side & 0x1fffff;
    if (block & 0xfff) {
        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, px);
        if ((int)(gob->gob_ypos + top & 0x1fffff) < contour)
            wall &= ~0x800000;
    }
    if (headBlock & 0xfff) {
        contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, headBlock, px);
        if ((int)(gob->gob_ypos - 0x10000 & 0x1fffff) < contour)
            head &= ~0x800000;
    }
    if ((head | wall) & 0x800000) {
        type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos)].flags & 0xf000000;
        glue = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, gob);
        if (type == 0x4000000) {
            if (glue > 0)
                return;
            if (!(gob->gob_flags2 & 0x2000))
                gob->gob_ypos += glue;
            gob->gob_flags = gob->gob_flags & 0xeaffffff | 0xa000000;
            return;
        }
        if (type == 0x8000000) {
            if (glue > 0)
                return;
            if (!(gob->gob_flags2 & 0x2000))
                gob->gob_ypos += glue;
            gob->gob_flags = gob->gob_flags & 0xe9ffffff | 0x9000000;
            return;
        }
        head &= 0xf000000;
        if (head != 0x8000000 && dx < 0 || head != 0x4000000 && dx >= 0) {
            gob->gob_flags = gob->gob_flags & 0xe0ffffff | (dx < 0 ? 0x1000000 : 0x2000000);
            if (!(gob->gob_flags2 & 0x2000))
                gob->gob_xpos += (dx < 0 ? 0x200000 : 0) - (gob->gob_xpos + side & 0x1fffff);
        }
        return;
    }
    type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos + 0x100000)].flags & 0xf000000;
    if (type == 0x4000000) {
        gob->gob_flags = gob->gob_flags & 0xedffffff | 0xd000000;
        return;
    }
    if (type == 0x8000000) {
        gob->gob_flags = gob->gob_flags & 0xeeffffff | 0xe000000;
        return;
    }
    block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos + side, gob->gob_ypos)[1];
    if (block & 0xfff) {
        if (M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, gob->gob_xpos + side & 0x1fffff))
            return;
        type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos)].flags & 0xf000000;
        if (type == 0x4000000 || type == 0x8000000)
            return;
        gob->gob_flags = gob->gob_flags & 0xe4ffffff | (dx < 0 ? 0x1000000 : 0x2000000) | 0x4000000;
    } else {
        type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos)].flags & 0xf000000;
        if (type == 0x4000000 || type == 0x8000000)
            return;
        gob->gob_flags = gob->gob_flags & 0xe4ffffff | (dx < 0 ? 0x1000000 : 0x2000000) | 0x4000000;
    }
}
}
