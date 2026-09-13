// Adapted from pc_decomp_backup/src/functions/FUN_0040F030.cpp
// Historical source SHA256: 5b0b0f318a026a07988c142910b6482a52240a8e016c7d5325214f4d9f141ccb
extern "C" {
extern "C" int __cdecl FUN_00440430(int, int, int, int);

extern "C" int __cdecl GEX_Target(int param_1, int xPos, int yPos)
{
    unsigned short uVar1;
    int pGVar2;
    int iVar3;
    unsigned char bVar4;
    int iWVar5;

    if (xPos < 0 || yPos < 0) {
        return -0x7f000000;
    }
    pGVar2 = *(int*)(param_1 + 4);
    if (xPos < *(int*)(pGVar2 + 4) && yPos < *(int*)(pGVar2 + 8)) {
        iWVar5 = FUN_00440430(pGVar2, *(int*)(param_1 + 0x14), xPos, yPos);
        uVar1 = *(unsigned short*)(iWVar5 + 2);
        iVar3 = *(int*)(*(int*)(param_1 + 0xc) + (uVar1 & 0x3fff) * 4);
        if (iVar3 != 0) {
            if ((uVar1 & 0x4000) == 0) {
                bVar4 = *(unsigned char*)(((xPos & 0x1f0000) >> 0x10) + iVar3);
            } else {
                bVar4 = *(unsigned char*)((iVar3 - ((xPos & 0x1f0000) >> 0x10)) + 0x1f);
            }
            if ((uVar1 & 0x8000) != 0) {
                if (bVar4 == 0) {
                    return -0x7f000000;
                }
                bVar4 = 0x21 - bVar4;
            }
            if (bVar4 != 0) {
                return (bVar4 - 1) * 0x10000 - (yPos & 0x1f0000);
            }
        }
    }
    return -0x7f000000;
}
}
