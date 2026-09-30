typedef struct BgImage {
    int w;
    int h;
    int ax;
    int ay;
    int unk10;
    short present;              /* 0x14 */
} BgImage;
typedef struct BgPart {
    unsigned int offset;
    unsigned int flags;
    BgImage *image;
    int a;
    int b;
} BgPart;
typedef struct BgFrame {
    unsigned char _pad0[0x18];
    BgPart **parts;             /* 0x18 */
} BgFrame;
typedef struct BgLoad {
    BgFrame ***groups;
} BgLoad;
typedef struct BgObject {
    unsigned int flags;
    BgLoad *load;
    int group;
    int frame;
} BgObject;
extern "C" {
int __cdecl GEX_WidescreenWidth(void);
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
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int decl_pad_19;
extern int decl_pad_20;
extern int decl_pad_21;
extern int decl_pad_22;
extern int decl_pad_23;
extern int decl_pad_24;
extern short DAT_004a0270_Background_Unk2;
extern short DAT_004a0272_LEVEL_MAP;
void __cdecl FUN_0043dc70_Graphics(BgImage *image, int x, int y, int a, int b, unsigned int flags, short c, short d);
void __cdecl FUN_00440cb0_DrawBackgroundInnerInner(BgObject *obj, int x, int y)
{
    BgFrame *frame;
    BgPart **p;
    BgPart *part;
    BgImage *image;
    unsigned int flags;
    unsigned int pflags;
    unsigned int oflags;
    int w;
    int px;
    int py;
    int h;
    int ox;
    int oy;
    if ((obj->group | obj->frame) & 0x80000000)
        return;
    frame = obj->load->groups[obj->group][obj->frame];
    if (!frame) {
        frame = obj->load->groups[obj->group][0];
        obj->frame = 0;
    }
    p = frame->parts;
    x &= 0xffff0000;
    y &= 0xffff0000;
    while ((part = *p++) != 0) {
        image = part->image;
        pflags = part->flags;
        oflags = obj->flags;
        w = image->w;
        h = image->h;
        if (!image->present)
            continue;
        oy = part->offset << 16;
        ox = part->offset & 0xffff0000;
        if (pflags & 0x80000000)
            px = w - image->ax;
        else
            px = image->ax;
        if (oflags & 0x80000000)
            px = x - px - ox;
        else
            px += ox + x;
        flags = oflags ^ pflags;
        if (flags & 0x80000000) {
            if (px < 0 || px - w >= (GEX_WidescreenWidth() << 16))
                continue;
        } else {
            if (w + px < 0 || px >= (GEX_WidescreenWidth() << 16))
                continue;
        }
        if (pflags & 0x40000000)
            py = h - image->ay;
        else
            py = image->ay;
        if (oflags & 0x40000000)
            py = y - py - oy;
        else
            py += oy + y;
        if (flags & 0x40000000) {
            if (py < 0 || py - h >= 0xf00000)
                continue;
        } else {
            if (h + py < 0 || py >= 0xf00000)
                continue;
        }
        FUN_0043dc70_Graphics(image, px >> 16, py >> 16, part->a, part->b, flags, DAT_004a0270_Background_Unk2, DAT_004a0272_LEVEL_MAP);
    }
}
}
