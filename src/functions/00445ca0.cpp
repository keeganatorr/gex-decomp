// Adapted from pc_decomp_backup/src/functions/FUN_00445CA0.cpp
// Historical source SHA256: f6b9d19d78f56d04c860c4183715324759493247a69402889c1906c9089404a1
// Behavior candidate; original bytes are not claimed to match.

extern int DAT_004A2B24;
extern int DAT_004A2B30;
extern unsigned int DAT_004A2F58;
extern unsigned int DAT_004A2F5C;
extern int DAT_004A2F60;
extern int DAT_004A2F64;
extern int DAT_004A2F6C;
extern int DAT_004A2F78;
extern int DAT_004A2F88;
extern unsigned int DAT_004A2F8C;
extern int DAT_004A33AC;

extern "C" int* __cdecl FUN_00402400(unsigned char r, unsigned char g, unsigned char b, unsigned int ppvBitsUnk, int a);

extern "C" void __cdecl FUN_00445ca0_DrawTilesInner4(unsigned char* param_1)
{
    unsigned int tmp;

    DAT_004A2F58 = (unsigned int)param_1[0xc];
    DAT_004A2F5C = (unsigned int)param_1[0xd];
    DAT_004A2F60 = (int)*(short*)(param_1 + 8);
    DAT_004A2F64 = (int)*(short*)(param_1 + 0xa);
    DAT_004A2F8C = (unsigned int)*(short*)(param_1 + 0x10);
    DAT_004A2F88 = (int)*(short*)(param_1 + 0x12);

    DAT_004A2F6C = (int)FUN_00402400(param_1[4], param_1[5], param_1[6], (unsigned int)param_1[0xe], 0x10);

    if ((int)DAT_004A2F8C > 0 && DAT_004A2F88 > 0 && DAT_004A2F60 < 0x140) {
        if (DAT_004A2F60 < 0) {
            tmp = DAT_004A2F60 + DAT_004A2F8C;
            if ((int)tmp < 1) return;
            DAT_004A2F60 = DAT_004A2F60 + (DAT_004A2F8C - tmp);
            DAT_004A2F58 = DAT_004A2F58 + (DAT_004A2F8C - tmp);
            DAT_004A2F8C = tmp;
            if ((int)tmp > 0x140) DAT_004A2F8C = 0x140;
        } else if (DAT_004A2F60 + (int)DAT_004A2F8C > 0x13f) {
            DAT_004A2F8C = DAT_004A2F8C - ((DAT_004A2F60 + (int)DAT_004A2F8C) - 0x140);
        }

        if (DAT_004A2F64 < 0xe8) {
            if (DAT_004A2F64 < 8) {
                tmp = DAT_004A2F64 + DAT_004A2F88 + -8;
                if (tmp == 0 || DAT_004A2F64 + DAT_004A2F88 < 8) return;
                DAT_004A2F64 = DAT_004A2F64 + (DAT_004A2F88 - tmp);
                DAT_004A2F5C = DAT_004A2F5C + (DAT_004A2F88 - tmp);
                DAT_004A2F88 = tmp;
                if ((int)tmp > 0xe0) DAT_004A2F88 = 0xe0;
            } else if ((unsigned int)(DAT_004A2F64 + DAT_004A2F88) > 0xe7) {
                DAT_004A2F88 = DAT_004A2F88 - ((DAT_004A2F64 + DAT_004A2F88) - 0xe8U);
            }

            DAT_004A2B30 = 0x800 - ((int)DAT_004A2F8C >> 1);
            DAT_004A2B24 = (int)DAT_004A2F8C * -2 + 0x800;

            unsigned short* palette = (unsigned short*)DAT_004A2F6C;
            unsigned char* texture = (unsigned char*)(DAT_004A2F78 + DAT_004A2F5C * 0x800);
            unsigned short* framebuffer = (unsigned short*)(DAT_004A33AC + DAT_004A2F64 * 0x800 + DAT_004A2F60 * 2);

            for (int row = 0; row < DAT_004A2F88; ++row) {
                unsigned short* destination = framebuffer + row * 0x400;
                unsigned char* source = texture + row * 0x800;
                for (unsigned int column = 0; column < DAT_004A2F8C; ++column) {
                    unsigned int textureX = DAT_004A2F58 + column;
                    unsigned char packed = source[textureX >> 1];
                    unsigned int paletteIndex = (textureX & 1) == 0 ? packed & 0xf : packed >> 4;
                    unsigned short colour = palette[paletteIndex];
                    if (colour == 0)
                        continue;
                    if ((colour & 0x8000) != 0)
                        colour = (unsigned short)(((colour >> 1) & 0x3def) + ((destination[column] & 0x7bde) >> 1));
                    destination[column] = colour;
                }
            }
        }
    }
}
