// Raster clipping follows the source replacement viewport, including sprite spans.
extern "C" int __cdecl GEX_WidescreenWidth(void);
// Adapted from pc_decomp_backup/src/functions/FUN_004459E0.cpp
// Historical source SHA256: 86ef2d66d0e5d752b25a057c3576d3fd56d0a5e0ddce828ec96fd83d030b2a3a
extern "C" {
extern "C" { extern int DAT_00450008; }
extern "C" { extern int DAT_0045000C; }
extern "C" { extern int DAT_00450010; }
extern "C" { extern int DAT_00450014; }
extern "C" { extern int DAT_00450018; }
extern "C" { extern int DAT_0045001C; }
extern "C" { extern int DAT_0047EDB4; }
extern "C" { extern int DAT_0047EDB8; }
extern "C" { extern int DAT_0047EDBC; }
extern "C" { extern int DAT_0047EDC0; }
extern "C" { extern int DAT_004A2B24; }
extern "C" { extern unsigned char DAT_004A2B50[]; }
extern "C" { extern unsigned int DAT_004A2F58; }
extern "C" { extern unsigned int DAT_004A2F5C; }
extern "C" { extern int DAT_004A2F60; }
extern "C" { extern int DAT_004A2F64; }
extern "C" { extern int DAT_004A2F78; }
extern "C" { extern int DAT_004A2F88; }
extern "C" { extern unsigned int DAT_004A2F8C; }
extern "C" { extern unsigned short* DAT_004A33AC; }

extern "C" void __cdecl FUN_004459e0_DrawTilesInner3(void* param_1)
{
    unsigned int uVar3;
    int iVar6;
    unsigned int* ppvBits;
    unsigned int uVar4;

    DAT_004A2F58 = (unsigned int)((unsigned char*)param_1)[0x0c];
    DAT_004A2F5C = (unsigned int)((unsigned char*)param_1)[0x0d];
    DAT_004A2F60 = (int)((short*)((unsigned char*)param_1 + 8))[0];
    DAT_004A2F64 = (int)((short*)((unsigned char*)param_1 + 0xa))[0];
    DAT_004A2F8C = (unsigned int)((short*)((unsigned char*)param_1 + 0x10))[0];
    DAT_004A2F88 = (int)((short*)((unsigned char*)param_1 + 0x12))[0];
    DAT_0047EDB8 = 0;

    if ((((unsigned char*)param_1)[4] != 0x80) && (((unsigned char*)param_1)[5] != 0x80) && (((unsigned char*)param_1)[6] != 0x80)) {
        DAT_0047EDB4 = (((unsigned char*)param_1)[4] & 0xf8) << 2;
        DAT_0047EDBC = (((unsigned char*)param_1)[5] & 0xf8) << 2;
        DAT_0047EDB8 = 1;
        DAT_0047EDC0 = (((unsigned char*)param_1)[6] & 0xf8) << 2;
    }

    if (((int)DAT_004A2F8C > 0) && (DAT_004A2F88 > 0) && (DAT_004A2F60 < GEX_WidescreenWidth())) {
        if (DAT_004A2F60 < 0) {
            uVar3 = DAT_004A2F60 + DAT_004A2F8C;
            if ((int)uVar3 < 1) {
                return;
            }
            DAT_004A2F60 = DAT_004A2F60 + (int)(DAT_004A2F8C - uVar3);
            DAT_004A2F58 = DAT_004A2F58 + (DAT_004A2F8C - uVar3);
            DAT_004A2F8C = uVar3;
            if (GEX_WidescreenWidth() < (int)uVar3) {
                DAT_004A2F8C = GEX_WidescreenWidth();
            }
        }
        else if ((GEX_WidescreenWidth() - 1) < DAT_004A2F60 + (int)DAT_004A2F8C) {
            DAT_004A2F8C = DAT_004A2F8C - ((DAT_004A2F60 + (int)DAT_004A2F8C) - GEX_WidescreenWidth());
        }

        if (DAT_004A2F64 < 0xe8) {
            if (DAT_004A2F64 < 8) {
                iVar6 = DAT_004A2F64 + DAT_004A2F88 + -8;
                if ((iVar6 == 0) || (DAT_004A2F64 + DAT_004A2F88 < 8)) {
                    return;
                }
                DAT_004A2F64 = DAT_004A2F64 + (DAT_004A2F88 - iVar6);
                DAT_004A2F5C = DAT_004A2F5C + (DAT_004A2F88 - iVar6);
                DAT_004A2F88 = iVar6;
                if (0xe0 < iVar6) {
                    DAT_004A2F88 = 0xe0;
                }
            }
            else if (0xe7 < (unsigned int)(DAT_004A2F64 + DAT_004A2F88)) {
                DAT_004A2F88 = DAT_004A2F88 - ((DAT_004A2F64 + DAT_004A2F88) - 0xe8);
            }

            DAT_004A2B24 = 0x800 - (int)DAT_004A2F8C * 2;
            unsigned int* source = (unsigned int*)(DAT_004A2F5C * 0x800 + (int)DAT_004A2F78 + DAT_004A2F58 * 2);
            unsigned short* destination = (unsigned short*)(DAT_004A2F64 * 0x800 + DAT_004A2F60 * 2 + (int)DAT_004A33AC);
            while (DAT_004A2F88 != 0) {
                unsigned int remaining = DAT_004A2F8C;
                if (DAT_0047EDB8 == 0) {
                    while (remaining >= 4) {
                        unsigned int first = *source++;
                        unsigned int second = *source++;
                        unsigned short p0 = (unsigned short)first;
                        unsigned short p1 = (unsigned short)(first >> 16);
                        unsigned short p2 = (unsigned short)second;
                        unsigned short p3 = (unsigned short)(second >> 16);
                        if (p0 != 0) destination[0] = p0;
                        if (p1 != 0) destination[1] = p1;
                        if (p2 != 0) destination[2] = p2;
                        if (p3 != 0) destination[3] = p3;
                        destination += 4;
                        remaining -= 4;
                    }
                    while (remaining != 0) {
                        unsigned short colour = (unsigned short)(*(unsigned int*)((char*)source - 2) >> 16);
                        source = (unsigned int*)((char*)source + 2);
                        if (colour != 0) *destination = colour;
                        ++destination;
                        --remaining;
                    }
                } else {
                    while (remaining != 0) {
                        unsigned short colour = (unsigned short)(*(unsigned int*)((char*)source - 2) >> 16);
                        source = (unsigned int*)((char*)source + 2);
                        if (colour != 0) {
                            unsigned int red = (colour & 0x1f) | (unsigned int)DAT_0047EDB4;
                            unsigned int green = ((colour >> 5) & 0x1f) | (unsigned int)DAT_0047EDBC;
                            unsigned int blue = ((colour >> 10) & 0x1f) | (unsigned int)DAT_0047EDC0;
                            unsigned int packed = (unsigned int)DAT_004A2B50[blue] << 5;
                            packed = (packed | DAT_004A2B50[green]) << 5;
                            *destination = (unsigned short)(packed | DAT_004A2B50[red]);
                        }
                        ++destination;
                        --remaining;
                    }
                }
                source = (unsigned int*)((char*)source + DAT_004A2B24);
                destination = (unsigned short*)((char*)destination + DAT_004A2B24);
                --DAT_004A2F88;
            }
        }
    }
}
}
