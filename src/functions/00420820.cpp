// Adapted from pc_decomp_backup/src/functions/FUN_00420820.cpp
// Historical source SHA256: 3a0a2d47d3825472b58c0f5279a8805746117afa11d3954b726ed9d49c01c160
extern "C" {
extern "C" { extern int DAT_004A2990; }
extern "C" int* FUN_00419FE0(int, unsigned int, unsigned int);
extern "C" int __cdecl FUN_0040F100(int, unsigned int, unsigned int);

extern "C" int __cdecl GEX_Target(unsigned int xPos, unsigned int yPos)
{
    int* block = FUN_00419FE0(DAT_004A2990, xPos, yPos);
    int attr = *(int*)((char*)0x0045b9a0 + *(unsigned short*)((char*)block + 6) * 0x20);
    if ((attr & 0x80000000) != 0) {
        if (*(unsigned short*)((char*)block + 2) == 0) return 1;
        int contour = FUN_0040F100(DAT_004A2990, *(unsigned short*)((char*)block + 2), xPos);
        if (contour != 0 && ((yPos & 0xffe00000) + contour) - 0x10000 <= yPos) return 1;
    }
    return 0;
}
}
