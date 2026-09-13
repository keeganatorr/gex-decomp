// Adapted from pc_decomp_backup/src/functions/FUN_00440430.cpp
// Historical source SHA256: 5e31653ef61650e306786c30c846b14772683e5fa302b891ecaf46938e09fc16
extern "C" {
extern "C" void* __cdecl GEX_Target(void* param_1, void** tileData, unsigned int xPos, unsigned int yPos)
{
    int iVar2;
    unsigned short uVar1;

    iVar2 = *(int*)((int)param_1 + 0x2c +
        ((int)(yPos & 0xff3fffff) >> 0x16) * *(int*)((int)param_1 + 0x0c) +
        ((int)(xPos & 0xff3fffff) >> 0x16));
    if (iVar2 == 0) {
        return *tileData;
    }
    uVar1 = *(unsigned short*)(((xPos & 0xe00000) >> 0x14) + ((yPos & 0xe00000) >> 0x11) + 8 + iVar2);
    return (void*)(*(int*)((unsigned int)(uVar1 >> 3 & 0xfffc) + (int)tileData) + (uVar1 & 0x1f) * 0x10);
}
}
