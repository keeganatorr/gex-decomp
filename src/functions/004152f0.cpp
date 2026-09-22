extern "C" {
extern int DAT_004a282c_startxPos;
extern int DAT_004a2830_startypos;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_00455BF4;
extern int DAT_00455BF8;
extern int DAT_00455BF0;
extern int DAT_00455bfc;
extern int DAT_00455c00;
extern int DAT_00455be4;
extern int LEVELID_00456ad8;
extern int DAT_00456ae8;
extern unsigned short DAT_004577B0[];
void __cdecl GOB_ResetState_00420bc0(int *);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
void __cdecl SND_PlayObSound_0041a250(int *, int, int, int);
void __cdecl FUN_00415170_LevelLoading(int *);
}

extern "C" void __cdecl GEX_Target(int *p)
{
    GOB_ResetState_00420bc0(p);
    p[0x27] = p[0x1c];
    p[0x15] = 0;
    p[0x26] = 0;
    p[0x28] = 0;
    p[0x2a] = 0;
    p[0x1c] = 2;
    p[0x14] = 0x30;
    p[0x2b] = 0;

    DAT_00455BF4 = DAT_004a282c_startxPos - CAMERA_XPos_004a2a38;
    DAT_00455bfc = 0;
    DAT_00455BF8 = DAT_004a2830_startypos - CAMERA_YPos_004a2a1c;
    DAT_00455c00 = 0;
    DAT_00455BF0 = 0;
    DAT_00455be4 = 1;

    if (DAT_004577B0[LEVELID_00456ad8 * 4] & 0x80) {
        GFX_Fade_0043f490(10, 0, 0, 0, 0, 0, 0);
    } else if (DAT_00456ae8 != 4) {
        GFX_Fade_0043f490(10, 0x7f, 0x7f, 0x7b, 0x7b, 0xff, 0xff);
    } else {
        GFX_Fade_0043f490(10, 0, 0, 0, 0, 0, 0);
    }

    SND_PlayObSound_0041a250(p, 0x8a, 0x80, 0x60);
    FUN_00415170_LevelLoading(p);
}
