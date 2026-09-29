typedef struct GXObject {
    unsigned char pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char pad80[0xcc - 0x80];
    int gob_yScale;             /* 0xcc */
    unsigned char padd0[0xe0 - 0xd0];
    unsigned int gob_flags2;    /* 0xe0 */
} GXObject;

typedef struct Frame {
    int unk0;
    int top;                    /* 0x04 */
    int unk8;
    int bottom;                 /* 0x0c */
} Frame;

typedef struct TileAttribute {
    unsigned int flags;
    int rest[7];
} TileAttribute;

extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern TileAttribute DAT_0045B9A0[];
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int group, int index, int *x, int *y);
Frame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *gob);
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *level, int x, int y);
unsigned short *__cdecl GOB_GetBlockAddress_00419fe0(void *level, int x, int y);
int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);
int __cdecl FUN_0041a090(GXObject *);

void __cdecl FUN_00438470_MoveGuillotine(GXObject *gob, int dy)
{
    Frame *frame;
    int flip;
    int top;
    int bottom;
    unsigned int right;
    unsigned int left;
    unsigned int upRight;
    unsigned int upLeft;
    unsigned int type;
    unsigned int blockRight;
    unsigned int blockLeft;
    unsigned int px;
    int contour;
    int hx;
    int hy;

    gob->gob_ypos += dy;
    gob->gob_flags2 &= ~0x800000;
    if ((gob->gob_flags2 & 0x80) && GOB_GetHotSpot_00419c00(gob, 0, 0, &hx, &hy)) {
        gob->gob_xpos += hx;
        gob->gob_ypos += hy;
    }
    if ((gob->gob_flags & 0x20000) && !(gob->gob_flags2 & 0x400)) {
        frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
        flip = gob->gob_flags & 0x40000000;
        if (flip)
            top = -frame->bottom;
        else
            top = frame->top;
        if (flip)
            bottom = -frame->top;
        else
            bottom = frame->bottom;
        right = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos)].flags;
        left = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos)].flags;
        if (!(right & 0x800000) && !(left & 0x800000))
            gob->gob_flags2 |= 0x800000;
        if (FUN_0041a090(gob)) {
            if ((gob->gob_flags & 0x20000) && !(gob->gob_flags & 0x1f000000)) {
                type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos)].flags & 0xf000000;
                if (type == 0x4000000)
                    gob->gob_flags = gob->gob_flags & 0xeaffffff | 0xa000000;
                else if (type == 0x8000000)
                    gob->gob_flags = gob->gob_flags & 0xe9ffffff | 0x9000000;
                else
                    gob->gob_flags = gob->gob_flags & 0xe4ffffff | 0x4000000;
            }
        } else if (dy < 0) {
            frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
            if (gob->gob_flags & 0x40000000)
                top = -frame->bottom;
            else
                top = frame->top;
            if (gob->gob_flags2 & 0x400000)
                top = (gob->gob_yScale >> 8) * (top >> 8);
            upRight = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos + top)].flags;
            right = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos + top)].flags;
            upLeft = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos)].flags;
            left = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos)].flags;
            blockRight = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos + top)[1];
            blockLeft = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos + top)[1];
            px = gob->gob_xpos + 0x100000 & 0x1fffff;
            if (blockRight & 0xfff) {
                contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, blockRight, px);
                if ((int)(gob->gob_ypos + top & 0x1fffff) < contour)
                    upRight &= ~0x800000;
            }
            if (blockLeft & 0xfff) {
                contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, blockLeft, px);
                if ((int)(gob->gob_ypos + top & 0x1fffff) < contour)
                    right &= ~0x800000;
            }
            if (!(upRight & 0x800000) && !(right & 0x800000) && ((upLeft & 0x800000) || (left & 0x800000)))
                gob->gob_flags = gob->gob_flags & 0xe3ffffff | 0x3000000;
            type = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos, gob->gob_ypos + top)].flags;
            if ((type & 0x800000) && (type & 0xf000000) != 0x8000000 && (type & 0xf000000) != 0x4000000) {
                gob->gob_flags |= 0x1f000000;
                if (!(gob->gob_flags2 & 0x2000))
                    gob->gob_ypos = gob->gob_ypos - (gob->gob_ypos + top & 0x1fffff) + 0x220000;
            }
        } else if (dy > 0) {
            frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
            flip = gob->gob_flags & 0x40000000;
            if (flip)
                top = -frame->bottom;
            else
                top = frame->top;
            if (flip)
                bottom = -frame->top;
            else
                bottom = frame->bottom;
            blockRight = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos + bottom + 0x40000)].flags;
            upRight = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos + bottom + 0x40000)].flags;
            right = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos + 0x100000, gob->gob_ypos + top)].flags;
            upLeft = DAT_0045B9A0[M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, gob->gob_xpos - 0x100000, gob->gob_ypos + top)].flags;
            if (!(blockRight & 0x800000) && !(upRight & 0x800000) && ((right & 0x800000) || (upLeft & 0x800000)))
                gob->gob_flags = gob->gob_flags & 0xe3ffffff | 0x3000000;
        }
    }
    if (gob->gob_flags2 & 0x80) {
        gob->gob_xpos -= hx;
        gob->gob_ypos -= hy;
    }
}
}
