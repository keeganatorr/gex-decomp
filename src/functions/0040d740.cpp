typedef struct Extent { int w; int h; } Extent;
typedef struct Img { unsigned char _pad0[8]; Extent *extent; } Img;
typedef struct Frame { unsigned char _pad0[0x18]; Img **images; } Frame;
typedef struct Group { Frame *frame; } Group;
typedef struct Table { Group *group; } Table;
typedef struct Anim { Table *table; } Anim;
typedef struct GXObject {
    unsigned char _pad0[0x80];
    unsigned int gob_flags80;   /* 0x80 */
    Anim *gob_anim;             /* 0x84 */
    unsigned char _pad88[0x98 - 0x88];
    char *gob_text;             /* 0x98 */
    unsigned int gob_margin;    /* 0x9c */
    unsigned int gob_spacing;   /* 0xa0 */
    unsigned char _pada4[0xac - 0xa4];
    int gob_xScale;             /* 0xac */
    int gob_yScale;             /* 0xb0 */
    int gob_extent;             /* 0xb4 */
} GXObject;
extern "C" {
extern int DAT_00455c04;
extern int DAT_00456228;
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *gob, int priority);
char *__cdecl HelpBoxGetLine_0040d890(char *text, int *flags);
int __cdecl TXT_PixelLength_0043fae0(char *text);
void __cdecl GEX_Target(GXObject *gob)
{
    char *text;
    char *line;
    Extent *extent;
    int width;
    int height;
    int length;
    int flags;
    text = gob->gob_text;
    GOB_SetObjectDisplayPriority_00419b80(gob, 9);
    gob->gob_flags80 |= 1;
    gob->gob_spacing &= 0xfffffff0;
    if (DAT_00455c04 == 4 && gob->gob_anim) {
        extent = gob->gob_anim->table->group->frame->images[0]->extent;
        width = (extent->w >> 16) + 0x20;
        height = (extent->h >> 16) + 0x20;
        if (width < 5 || height < 5) {
            width = 100;
            height = 100;
        }
    } else {
        width = 0;
        height = (gob->gob_margin >> 16) * 2;
        while (*text) {
            line = text;
            text = HelpBoxGetLine_0040d890(text, &flags);
            length = TXT_PixelLength_0043fae0(line) >> 16;
            if (length > width)
                width = length;
            if (!(flags & 1)) {
                *text = '\\';
                text += 2;
            }
            if (line != text)
                height += gob->gob_spacing >> 16;
        }
        width += (gob->gob_margin & 0xffff) * 2;
        height = height - (gob->gob_spacing >> 16) + 7;
    }
    gob->gob_extent = width | height << 16;
    gob->gob_xScale = (width << 16) / DAT_00456228;
    gob->gob_yScale = (height << 16) / DAT_00456228;
}
}
