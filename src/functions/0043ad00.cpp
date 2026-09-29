extern "C" {
extern int DAT_00464798;
extern int DAT_004647a0[];
extern int DAT_00464790;
extern int DAT_004a2b00;
extern int DAT_0045ffd4;
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
int __cdecl FUN_00449E10(void);

void __cdecl FUN_0043ad00_OBJECTFUNCTION(void *object)
{
    ++DAT_00464798;
    if (DAT_004647a0[0] == DAT_00464798 ||
        DAT_004647a0[1] == DAT_00464798 ||
        DAT_004647a0[2] == DAT_00464798 ||
        DAT_004647a0[3] == DAT_00464798) {
        SND_PlaySoundNoPosition_0041a360(0xb5, 0xff);
    }

    if (DAT_004a2b00 == 0) {
        if (FUN_00449E10() % 900 <= *(int *)((char *)object + 0x98) && DAT_0045ffd4 == 0) {
            SND_PlaySoundNoPosition_0041a360(0xb4, 0xff);
            DAT_004647a0[DAT_00464790++] = DAT_00464798 + 30;
            if (DAT_00464790 > 3)
                DAT_00464790 = 0;
            GFX_Fade_0043f490(1, 255, 0, 255, 0, 255, 0);
            DAT_0045ffd4 = 1;
        } else if (DAT_0045ffd4 != 0) {
            GFX_Fade_0043f490(4, 0, 255, 0, 255, 0, 255);
            DAT_0045ffd4 = 0;
        }
    }
}
}
