typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x9c - 0x80];
    int gob_work1;              /* 0x9c */
} GXObject;
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
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_00464788;
extern GXObject *DAT_00464794;
extern int DAT_004a2b00;
extern int DAT_00455be4;
extern int DAT_0045ffd8;
void __cdecl GFX_Fade_0043f490(int mode, int from, int to, int a, int b, int c, int d);
void __cdecl FUN_0043af00_GRAPHICSDRAWING(GXObject *gob)
{
    int level;
    int fade;
    int viewportWidth = GEX_WidescreenWidth() << 16;
    if (gob->gob_work1 && (gob->gob_xpos < CAMERA_XPos_004a2a38 || gob->gob_xpos > CAMERA_XPos_004a2a38 + viewportWidth || gob->gob_ypos < CAMERA_YPos_004a2a1c || gob->gob_ypos > CAMERA_YPos_004a2a1c + 0xf00000))
        DAT_00464788--;
    else if (!gob->gob_work1 && gob->gob_xpos >= CAMERA_XPos_004a2a38 && gob->gob_xpos <= CAMERA_XPos_004a2a38 + viewportWidth && gob->gob_ypos >= CAMERA_YPos_004a2a1c && gob->gob_ypos <= CAMERA_YPos_004a2a1c + 0xf00000)
        DAT_00464788++;
    if (DAT_00464794 == gob && !DAT_004a2b00 && !DAT_00455be4) {
        level = 0xff - (DAT_00464788 << 7 > 0 ? DAT_00464788 << 7 : 0);
        level = level > 0 ? level : 0;
        if (!DAT_0045ffd8) {
            GFX_Fade_0043f490(0x12, 0xff - level, 0xff, 0, 0xff, 0, 0xff);
            DAT_0045ffd8 = 1;
        } else {
            GFX_Fade_0043f490(0x12, 0, 0xff, 0, 0xff, 0, 0xff);
            DAT_0045ffd8 = 0;
        }
    }
    if (gob->gob_xpos >= CAMERA_XPos_004a2a38 && gob->gob_xpos <= CAMERA_XPos_004a2a38 + viewportWidth && gob->gob_ypos >= CAMERA_YPos_004a2a1c && gob->gob_ypos <= CAMERA_YPos_004a2a1c + 0xf00000)
        gob->gob_work1 = 1;
    else
        gob->gob_work1 = 0;
}
}
