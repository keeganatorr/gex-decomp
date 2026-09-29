// Adapted from pc_decomp_backup/src/functions/FUN_0040F100.cpp
// Historical source SHA256: 587e21a096abc30c11611d4acdab2dac303c0f0f8a45418fad1584cfcc07055a
extern "C" {
extern "C" int __cdecl GEX_Target(int param_1, unsigned int param_2, unsigned int param_3)
{
    int iVar1;
    unsigned char bVar2;

    iVar1 = *(int*)(*(int*)(param_1 + 0xc) + (param_2 & 0xffff3fff) * 4);
    if (iVar1 == 0) {
        return 0;
    }
    if ((param_2 & 0x4000) == 0) {
        bVar2 = *(unsigned char*)(((param_3 & 0x1f0000) >> 0x10) + iVar1);
        if (((param_2 & 0x8000) != 0) && (bVar2 != 0))
            bVar2 = 0x21 - bVar2;
    } else {
        bVar2 = *(unsigned char*)((iVar1 - ((param_3 & 0x1f0000) >> 0x10)) + 0x1f);
        if (((param_2 & 0x8000) != 0) && (bVar2 != 0)) {
            bVar2 = 0x21 - bVar2;
        }
    }
    return (unsigned int)bVar2 << 0x10;
}
}
