extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
void __cdecl SND_PlaySound_00401b50(int, int, int, int, int, int);

void __cdecl SND_PlayObSound_0041a250(void **gOb, int param2, int param3, int param4) {
    int iVar1;
    int iVar2;
    int iVar3;

    iVar2 = (int)gOb[0x1e] - CAMERA_XPos_004a2a38;
    iVar3 = (int)gOb[0x1f] - CAMERA_YPos_004a2a1c;

    if (iVar2 > -0x600000 && iVar2 < 0x1a00000 &&
        iVar3 > -0x400000 && iVar3 < 0x1500000) {
        iVar2 = (iVar2 - 0xa00000) >> 16;

        if (iVar2 <= -0xa0) {
            param3 = iVar2 + 0xa0 + param3;
            if (param3 > 0x500) {
                param3 = 0x80;
            }
        } else if (iVar2 >= 0xa0) {
            param3 = param3 + (0xa0 - iVar2);
            if (param3 < 0) {
                param3 = 0;
            }
        }

        iVar1 = 0;
        if (iVar2 <= -0x80) {
            iVar1 = iVar2 + 0x80;
        } else if (iVar2 >= 0x80) {
            iVar1 = iVar2 - 0x80;
        }

        if (param3 != 0) {
            SND_PlaySound_00401b50(param2, iVar1, 0, param3, param4, 0);
        }
    }
}
}
