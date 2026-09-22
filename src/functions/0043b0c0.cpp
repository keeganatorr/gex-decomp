extern "C" int __cdecl rand(void);
extern "C" int DAT_0045ffdc;
extern "C" int CAMERA_XPos_004a2a38;
extern "C" int CAMERA_YPos_004a2a1c;
extern "C" int DAT_004647b8[64];
extern "C" int DAT_004648b8[64];
extern "C" int DAT_004649b8[64];
extern "C" int DAT_00464ab8[64];
extern "C" int DAT_00464bb8[64];
extern "C" int DAT_00464cb8[64];

extern "C" void __cdecl GEX_Target(void)
{
    int count = rand() % 100;

    if (count - DAT_0045ffdc > 0)
        count = 0;
    else
        count = ((DAT_0045ffdc - count) >> 3) + 1;

    for (int i = 0; i < 64; ++i) {
        if (DAT_00464cb8[i] != 0) {
            DAT_004649b8[i] = DAT_00464ab8[i] + DAT_004649b8[i];
            DAT_00464bb8[i] = DAT_004648b8[i] + DAT_00464bb8[i];

            if (DAT_004649b8[i] < CAMERA_XPos_004a2a38 - 0xa0000 ||
                DAT_00464bb8[i] > CAMERA_YPos_004a2a1c + 0xfa0000)
                DAT_00464cb8[i] = 0;
        }
        else if (count != 0) {
            --count;
            int velocity = rand() % 0x80000;
            int side = rand() % 0x230;

            DAT_00464cb8[i] = 1;

            if (side >= 0x140)
                DAT_004649b8[i] = CAMERA_XPos_004a2a38 + 0x1400000;
            else
                DAT_004649b8[i] = side * 0x10000 + CAMERA_XPos_004a2a38;

            int negativeVelocity = -0x100000 - velocity;
            int positiveVelocity = velocity + 0x100000;

            if (side >= 0x140)
                DAT_00464bb8[i] = (side - 0x140) * 0x10000 + CAMERA_YPos_004a2a1c;
            else
                DAT_00464bb8[i] = CAMERA_YPos_004a2a1c;

            DAT_004648b8[i] = positiveVelocity;
            DAT_00464ab8[i] = negativeVelocity;
            DAT_004647b8[i] = velocity >> 17;
        }
    }
}
