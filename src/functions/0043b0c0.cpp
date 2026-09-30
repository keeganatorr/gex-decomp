extern "C" {
int __cdecl GEX_WidescreenWidth(void);
extern int DAT_0045ffdc;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_004647b8[];
extern int DAT_004648b8[];
extern int DAT_004649b8[];
extern int DAT_00464ab8[];
extern int DAT_00464bb8[];
extern int DAT_00464cb8[];
int __cdecl rand(void);
void __cdecl FUN_0043b0c0_GRAPHICSDRAWING(void)
{
    int width = GEX_WidescreenWidth();
    int i;
    int count;
    int r;
    int speed;
    int pos;
    r = rand() % 100;
    if (r - DAT_0045ffdc > 0)
        count = 0;
    else
        count = (DAT_0045ffdc - r >> 3) + 1;
    for (i = 0; i < 64; i++) {
        if (DAT_00464cb8[i]) {
            DAT_004649b8[i] += DAT_00464ab8[i];
            DAT_00464bb8[i] += DAT_004648b8[i];
            if (DAT_004649b8[i] < CAMERA_XPos_004a2a38 - 0xa0000 || DAT_00464bb8[i] > CAMERA_YPos_004a2a1c + 0xfa0000)
                DAT_00464cb8[i] = 0;
        } else if (count) {
            count--;
            speed = rand() % 0x80000;
            pos = rand() % (width + 240);
            DAT_00464cb8[i] = 1;
            if (pos >= width)
                DAT_004649b8[i] = CAMERA_XPos_004a2a38 + (width << 16);
            else
                DAT_004649b8[i] = (pos << 16) + CAMERA_XPos_004a2a38;
            if (pos >= width)
                DAT_00464bb8[i] = (pos - width << 16) + CAMERA_YPos_004a2a1c;
            else
                DAT_00464bb8[i] = CAMERA_YPos_004a2a1c;
            DAT_00464ab8[i] = -0x100000 - speed;
            DAT_004648b8[i] = speed + 0x100000;
            DAT_004647b8[i] = speed >> 17;
        }
    }
}
}
