// Raster clipping follows the source replacement viewport, including sprite spans.
extern "C" int __cdecl GEX_WidescreenWidth(void);
// Adapted from pc_decomp_backup/src/functions/FUN_004466A0.cpp
// Historical source SHA256: 52ca8c9fd7cddef105684d10c0f96c34952d8bc8c99843e63946e075ba4fbafa
extern "C" {
extern int FUN_004A33AC;
extern unsigned short *DAT_004a2f54_ppvBitsUnk;

extern "C" void __cdecl FUN_004466a0_DrawBoxBehindText(int xPos, int yPos, unsigned int Blue, int Green, unsigned int Red, int Transparency)
{
    unsigned int uVar1, uVar2;
    unsigned int *puVar3, *puVar4;

    if (xPos < GEX_WidescreenWidth() && (int)(Blue + xPos) > 0 && yPos < 0xe8 && Green + yPos > 8) {
        if (xPos < 0) {
            Blue = Blue + xPos;
            xPos = 0;
        }
        if ((int)(Blue + xPos) > GEX_WidescreenWidth()) {
            Blue = GEX_WidescreenWidth() - xPos;
        }
        if (yPos < 8) {
            Green = Green + yPos - 8;
            yPos = 8;
        }
        if (Green + yPos > 0xe8) {
            Green = 0xe8 - yPos;
        }

        if (Green != 0 && Blue != 0) {
            puVar4 = (unsigned int *)((int)FUN_004A33AC + (yPos * 0x400 + xPos) * 2);
            DAT_004a2f54_ppvBitsUnk = (unsigned short *)puVar4;

            if (Transparency == 0) {
                uVar1 = (Red << 0x10) | (Red & 0xffff);
                do {
                    while (1) {
                        uVar2 = Blue >> 1;
                        puVar3 = puVar4;
                        if (uVar2 == 0) break;
                        if ((Blue & 1) != 0) {
                            if (((unsigned int)puVar4 & 2) == 0) {
                                do {
                                    *puVar3 = uVar1;
                                    puVar3 = puVar3 + 1;
                                    uVar2 = uVar2 - 1;
                                } while (uVar2 != 0);
                                break;
                            }
                            *(unsigned short *)puVar4 = (unsigned short)Red;
                            puVar3 = (unsigned int *)((int)puVar4 + 2);
                        }
                        do {
                            *puVar3 = uVar1;
                            puVar3 = puVar3 + 1;
                            uVar2 = uVar2 - 1;
                        } while (uVar2 != 0);
                        puVar4 = puVar4 + 0x200;
                        Green = Green - 1;
                        if (Green == 0) return;
                    }
                    *(unsigned short *)puVar3 = (unsigned short)Red;
                    puVar4 = puVar4 + 0x200;
                    Green = Green - 1;
                } while (Green != 0);
            } else {
                uVar1 = ((Red << 0x10) | (Red & 0xffff)) >> 1 & 0x3def3def;
                do {
                    while (1) {
                        uVar2 = Blue >> 1;
                        puVar3 = puVar4;
                        if (uVar2 == 0) break;
                        if ((Blue & 1) != 0) {
                            if (((unsigned int)puVar4 & 2) == 0) {
                                do {
                                    *puVar3 = uVar1 + (*puVar3 >> 1 & 0x3def3def);
                                    puVar3 = puVar3 + 1;
                                    uVar2 = uVar2 - 1;
                                } while (uVar2 != 0);
                                break;
                            }
                            *(unsigned short *)puVar4 = (unsigned short)((unsigned short)uVar1 + ((unsigned short)(*puVar4 >> 1) & 0x3def));
                            puVar3 = (unsigned int *)((int)puVar4 + 2);
                        }
                        do {
                            *puVar3 = uVar1 + (*puVar3 >> 1 & 0x3def3def);
                            puVar3 = puVar3 + 1;
                            uVar2 = uVar2 - 1;
                        } while (uVar2 != 0);
                        puVar4 = puVar4 + 0x200;
                        Green = Green - 1;
                        if (Green == 0) return;
                    }
                    *(unsigned short *)puVar3 = (unsigned short)((unsigned short)uVar1 + ((unsigned short)(*puVar3 >> 1) & 0x3def));
                    puVar4 = puVar4 + 0x200;
                    Green = Green - 1;
                } while (Green != 0);
            }
        }
    }
}
}
