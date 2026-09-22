extern "C" {
extern int DAT_00464de0;
extern int DAT_00464e00;
extern int DAT_00464e0c;
extern int DAT_004a2a04;
extern int DAT_00455b8c_CamX2;
extern int DAT_00464e18;
extern int DAT_00464dd0;
extern int CAMERA_XPos_004a2a38;
extern int DAT_00460034;
extern unsigned char *PTR_00464e08;
extern int DAT_004a293c_CameraX_After2;
int __cdecl abs(int);

void __cdecl GEX_Target(void)
{
    if (DAT_00464de0 != 0) {
        if (DAT_00464e0c > 0)
            DAT_00464e0c -= 0x8000;
        else
            DAT_00464e0c += 0x8000;

        if (DAT_00464e0c >= 0 && DAT_00464e0c < 0x8000) {
            DAT_004a2a04 = 0;
            DAT_00464e0c = 1;
            DAT_00455b8c_CamX2 = 1;
            DAT_00464de0 = 0;
            DAT_00464e18 = 0;
        }
    } else if (DAT_00464e18 != 0) {
        DAT_00464e0c += DAT_00464dd0;
        const int upper = DAT_00464e00;
        DAT_004a2a04 = 1;
        if (upper < DAT_00464e0c)
            DAT_00464e0c = upper;
        else {
            const int lower = -DAT_00464e00;
            if (DAT_00464e0c < lower)
                DAT_00464e0c = lower;
        }

        if (CAMERA_XPos_004a2a38 < 0x1400000)
            DAT_00464dd0 = 0x8000;
        else if (CAMERA_XPos_004a2a38 > 0x6400000)
            DAT_00464dd0 = -0x8000;
    }

    if (--DAT_00460034 < 0) {
        if (DAT_00464e0c != 0)
            *(int *)(PTR_00464e08 + 0x54) += DAT_00464e0c > 0 ? 1 : -1;

        if (*(int *)(PTR_00464e08 + 0x54) == -1)
            *(int *)(PTR_00464e08 + 0x54) = 9;
        else if (*(int *)(PTR_00464e08 + 0x54) == 10)
            *(int *)(PTR_00464e08 + 0x54) = 0;

        if (DAT_00464e0c != 0)
            DAT_00460034 = (0x30000 / abs(DAT_00464e0c)) * 2;
        else
            DAT_00460034 = 30;

        if (DAT_00460034 > 30)
            DAT_00460034 = 30;
    }

    DAT_00455b8c_CamX2 = DAT_00464e0c;
    DAT_004a293c_CameraX_After2 += DAT_00464e0c;
}
}
