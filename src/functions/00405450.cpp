extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
extern unsigned char *PTR_00487f70;
extern short DAT_00453510_BeforeDrawWindow1[];
void __cdecl FUN_00405450_BeforeDrawWindow(void)
{
    unsigned char *row;
    short key;
    short *src;
    short *dst;
    int x;
    int y;
    row = PTR_00487f70;
    for (y = 240; y; y--) {
        memset(row, 0, 640);
        row += 0x800;
    }
    key = DAT_00453510_BeforeDrawWindow1[0];
    src = DAT_00453510_BeforeDrawWindow1;
    dst = (short *)(PTR_00487f70 + 0x368a0);
    for (y = 21; y; y--) {
        for (x = 160; x; x--) {
            if (key != *src)
                *dst = *src;
            dst++;
            src++;
        }
        dst += 0x360;
    }
}
}
