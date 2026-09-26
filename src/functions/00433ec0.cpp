typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0xbc - 0x80];
    int gob_rect;               /* 0xbc */
    void *gob_plut;             /* 0xc0 */
} GXObject;
extern "C" {
extern int DAT_0045b5ec;
extern int DAT_0045b5e8;
extern int FUN_00464210;
extern unsigned int FUN_00464214[16];
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    unsigned short colors[31] = {
        0x801f, 0x801d, 0x801b, 0x8019, 0x8017, 0x8015, 0x8013, 0x8011,
        0x800f, 0x800d, 0x800b, 0x8009, 0x8007, 0x8005, 0x8003, 0x8001,
        0x8003, 0x8005, 0x8007, 0x8009, 0x800b, 0x800d, 0x800f, 0x8011,
        0x8013, 0x8015, 0x8017, 0x8019, 0x801b, 0x801d, 0xffff
    };
    void *plut;
    int x;
    int y;
    int rect;
    unsigned int color;
    unsigned int *dest;
    int count;
    x = gob->gob_xpos;
    y = gob->gob_ypos;
    plut = gob->gob_plut;
    rect = gob->gob_rect;
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
    color = colors[DAT_0045b5ec];
    if (color == 0xffff) {
        DAT_0045b5ec = 0;
        color = 0x801f;
    }
    FUN_00464210 = 0xffffff00;
    color |= color << 16;
    dest = FUN_00464214;
    for (count = 16; count; count--)
        *dest++ = color;
    *(unsigned short *)FUN_00464214 = 0;
    gob->gob_plut = FUN_00464214;
    if (--DAT_0045b5e8 <= 0) {
        DAT_0045b5e8 = 3;
        DAT_0045b5ec++;
    }
    gob->gob_rect = 0x1f801f80;
    GOB_DisplayObjectScaleAndRotate_00441150(gob);
    gob->gob_xpos = x;
    gob->gob_ypos = y;
    gob->gob_plut = plut;
    gob->gob_rect = rect;
}
}
