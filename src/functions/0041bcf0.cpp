extern "C" {
    void __cdecl GOB_Remove_00419a80(int *);
    int __cdecl sprintf(char *, const char *, ...);
    int __cdecl TXT_PixelLength_0043fae0(char *);
    void __cdecl GOB_PhysicsStepY_0040f2a0(int *);
    void __cdecl TXT_DrawPrintP_0043fa70(int, int, char *, int);
    extern int *DAT_00459414_Gex_Object_For_DrawText;
    extern char s__ld_0045948c[];
    extern char _s__ldUP_00459490[];
    extern int CAMERA_XPos_004a2a38;
    extern int CAMERA_YPos_004a2a1c;
}

extern "C" void __cdecl ob215Draw_0041bcf0(int *param_1)
{
    int draw;
    int value;
    char text[12];

    /* The draw-index table (0x459418) is the pinned global at 0x459414 plus 4. */
    draw = ((int *)((char *)&DAT_00459414_Gex_Object_For_DrawText + 4))[param_1[0x28]];
    if (draw == 0) {
        GOB_Remove_00419a80(param_1);
        return;
    }

    value = param_1[0x26];
    if (value < 0) {
        value = -value;
        sprintf(text, _s__ldUP_00459490, value);
    } else {
        sprintf(text, s__ld_0045948c, value);
    }

    if (param_1[0x27] == 0) {
        param_1[0x27] = TXT_PixelLength_0043fae0(text) >> 2;
    }

    GOB_PhysicsStepY_0040f2a0(param_1);
    DAT_00459414_Gex_Object_For_DrawText = param_1;
    TXT_DrawPrintP_0043fa70(param_1[0x1e] - param_1[0x27] - CAMERA_XPos_004a2a38,
                            param_1[0x1f] - CAMERA_YPos_004a2a1c,
                            text,
                            draw);
    DAT_00459414_Gex_Object_For_DrawText = 0;

    value = param_1[0x29] - 1;
    param_1[0x29] = value;
    if (value <= 0) {
        param_1[0x29] = 2;
        param_1[0x28]++;
    }
}
