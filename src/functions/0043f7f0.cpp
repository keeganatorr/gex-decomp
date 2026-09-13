// Adapted from pc_decomp_backup/src/functions/FUN_0043F7F0.cpp
// Historical source SHA256: a65ee03296f9ca69bd32cd8651534228365bc85911ce74d758c0b4d9bac6bfb2
extern "C" {
extern "C" unsigned int __cdecl FUN_0043ECF0(void*);
extern "C" void __cdecl FUN_00445350(int*, int, int, unsigned int);


extern "C" void __cdecl GEX_Target(char* text)
{
    int* cursor = *(int**)0x004A2AE4;
    int* end = *(int**)0x004A2ADC;
    int* base = *(int**)0x004A2AE0;
    int* command;

    if (end < cursor + 6) {
        cursor = base;
        *(int**)0x004A2AE4 = base + 6;
    } else {
        *(int**)0x004A2AE4 = cursor + 6;
    }
    command = cursor;

    unsigned char* font = *(unsigned char**)0x004A2AF4;
    unsigned int texture = FUN_0043ECF0(*(void**)font);
    FUN_00445350(command, 0, 1, *(unsigned int*)0x0046A66C);
    *(unsigned short*)0x004A2B20 = (unsigned short)*(unsigned int*)0x0046A66C;

    int* lowTail = *(int**)0x004A2B18;
    *lowTail = (int)command;
    *(int**)0x004A2B18 = command;
    int* high = command + 3;
    high[0] = command[0]; high[1] = command[1]; high[2] = command[2];
    int* highTail = *(int**)0x004A2B14;
    *highTail = (int)high;
    *(int**)0x004A2B14 = high;

    (void)texture; 
    short cameraX = 0, cameraY = 0;
    int* player = *(int**)0x00459414;
    if (player != 0 && player[0x7d] - *(int*)0x004A2AC8 == -1) {
        int dx = player[0x1e] - player[0x7e];
        if (dx < 0) dx += 0x10000;
        cameraX = (short)(dx >> 0x11) - *(short*)0x004A2A96;
        int dy = player[0x1f] - player[0x7f];
        if (dy < 0) dy += 0x10000;
        cameraY = (short)(dy >> 0x11) - *(short*)0x004A2A94;
        int ax = cameraX < 0 ? -(int)cameraX : (int)cameraX;
        int ay = cameraY < 0 ? -(int)cameraY : (int)cameraY;
        if (ax + ay > 100) cameraX = cameraY = 0;
    }

    while (*text != 0) {
        unsigned int c = (unsigned char)*text++;
        if (c >= 'a' && c <= 'z') c -= 0x20;
        unsigned int minChar = font[8];
        unsigned int maxChar = font[9];
        if (c < minChar || c > maxChar) continue;

        unsigned char* glyph = *(unsigned char**)(font + 4) + (c - minChar) * 8 + 0x24;
        cursor = *(int**)0x004A2AE4;
        end = *(int**)0x004A2ADC;
        if (end < cursor + 10) {
            cursor = base;
            *(int**)0x004A2AE4 = base + 10;
        } else {
            *(int**)0x004A2AE4 = cursor + 10;
        }
        command = cursor;
        *(unsigned char*)((char*)command + 7) = 0x64;
        *(short*)((char*)command + 8) = (short)*(int*)0x004A2AF0;
        *(short*)((char*)command + 0x0a) = (short)*(int*)0x004A2AEC;
        *(short*)((char*)command + 0x10) = *(short*)(glyph + 4);
        *(short*)((char*)command + 0x12) = *(short*)(glyph + 6);
        *(unsigned char*)((char*)command + 4) = *(unsigned char*)0x004A2AFA;
        *(unsigned char*)((char*)command + 5) = *(unsigned char*)0x004A2AF9;
        *(unsigned char*)((char*)command + 6) = *(unsigned char*)0x004A2AF8;
        *(unsigned short*)((char*)command + 0x0e) = (unsigned short)texture;
        *(unsigned char*)((char*)command + 0x0c) = (unsigned char)(*(short*)(glyph + 0) + *(unsigned char*)0x0046A664);
        *(unsigned char*)((char*)command + 0x0d) = (unsigned char)(*(short*)(glyph + 2) + *(unsigned char*)0x0046A668);

        int* duplicate = (int*)((char*)command + 0x14);
        for (int i = 0; i < 5; ++i) duplicate[i] = command[i];
        *(short*)((char*)duplicate + 8) -= cameraX;
        *(short*)((char*)duplicate + 10) -= cameraY;

        lowTail = *(int**)0x004A2B18;
        *lowTail = (int)command;
        *(int**)0x004A2B18 = command;
        highTail = *(int**)0x004A2B14;
        *highTail = (int)duplicate;
        *(int**)0x004A2B14 = duplicate;
        *(int*)0x004A2AF0 += *(short*)(glyph + 4) + *(int*)(font + 0x10);
    }
}
}
