// Adapted from pc_decomp_backup/src/functions/FUN_004053A0.cpp
// Historical source SHA256: c5112a5b17df292815871453abe3309aca57758e4621e9e0ba171f884c9cd470
extern "C" {
extern "C" void __cdecl GEX_Target()
{
    unsigned char* pixels = *(unsigned char**)0x00487F70;
    if (pixels == 0)
        return;

    unsigned int* sourceRow = (unsigned int*)pixels;
    unsigned int* destinationRow = (unsigned int*)(pixels + 0x78000);
    for (int y2 = 0; y2 < 0xF0; ++y2) {
        for (int x = 0; x < 0xA0; ++x)
            destinationRow[x] = sourceRow[x];
        sourceRow += 0x200;
        destinationRow += 0x200;
    }

    unsigned short* row = (unsigned short*)(pixels + 0x78000);
    for (int y = 0; y < 0xF0; ++y) {
        for (int x = 0; x < 0x140; ++x)
            row[x] = (unsigned short)((row[x] & 0x7BDE) >> 1);
        row += 0x400;
    }

    const short* source = (const short*)0x004517F0;
    const short transparent = *source;
    short* destination = (short*)(pixels + 0xAD0B6);
    for (int y3 = 0; y3 < 0x1B; ++y3) {
        for (int x = 0; x < 0x8A; ++x) {
            if (*source != transparent)
                destination[x] = *source;
            ++source;
        }
        destination += 0x400;
    }
}
}
