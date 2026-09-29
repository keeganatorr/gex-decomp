struct Glyph {
    short width;
    char pad[6];
};

struct FontData {
    char pad[0x28];
    Glyph glyphs[1];
};

struct Font {
    int field_0;
    FontData *field_4;
    unsigned char field_8;
    unsigned char field_9;
    char pad[6];
    int field_10;
};

extern Font *gFont_004a2af4;

extern "C" int TXT_PixelLength_0043fae0(char *passwordString) {
    int iVar1 = 0;
    if (*passwordString != 0) {
        do {
            int c = *passwordString++;
            if ((unsigned)c >= gFont_004a2af4->field_8) {
                if ((unsigned)c <= gFont_004a2af4->field_9) {
                    iVar1 += gFont_004a2af4->field_4->glyphs[c - gFont_004a2af4->field_8].width + gFont_004a2af4->field_10;
                }
            }
        } while (*passwordString != 0);
    }
    return iVar1 << 16;
}
