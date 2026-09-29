// Adapted from pc_decomp_backup/src/functions/FUN_0040585E.cpp
// Historical source SHA256: d35dbc9c587e200c9b05b00dbff1c3d25804312ed2836794e06e2a6765dd04a9
extern "C" {
extern int DAT_00487FC4;
extern int DAT_00487FC8;
extern int DAT_00487FCC;

extern "C" int __cdecl FUN_0040585e_Drawing(int hWnd, int msg, int wParam, int lParam)
{
    int LVar1;
    int hdc;
    int iVar2;
    int hdc_00;
    int h_00;
    int hdc_01;
    int h_02;
    int h_01;
    int hdc_02;
    int h_04;
    int h_03;
    int hdc_03;
    int h_06;
    int h_05;
    int hdc_04;
    int h_07;
    int color;
    int iVar5;

    if (msg >= 0x14) {
        if (msg == 0x14) {
            return 0;
        }
        if (msg == 0x30f) {
            return 0;
        }
        if (msg != 0x311) {
            LVar1 = 0;
            return LVar1;
        }
        if (wParam == lParam) {
            return 0;
        }
        return 0;
    }

    if (msg == 6) {
        return 0;
    }

    if (msg != 0) {
        LVar1 = 0;
        return LVar1;
    }

    hdc = 1;
    iVar2 = 0;
    if (iVar2 != 0) {
        iVar2 = 1;
        hdc_00 = 0;
        h_00 = 0;
        hdc_01 = 0;
        h_02 = 0;
        h_01 = 0;
        hdc_02 = 0;
        h_04 = 0;
        h_03 = 0;
        hdc_03 = 0;
        h_06 = 0;
        h_05 = 0;
        hdc_04 = 0;
        h_07 = 0;
        color = 0;
        iVar5 = 0;
    }
    return 0;
}
}
