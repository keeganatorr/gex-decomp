// Adapted from pc_decomp_backup/src/functions/FUN_0040D980.cpp
// Historical source SHA256: 9c8a0168b25d3cac00499baa2268eb2762c2bdc71cfc7cc11c010d5296bc27c0
// Behavior candidate; original bytes are not claimed to match.

extern "C" int DAT_00455C04;
extern "C" unsigned char DAT_00455C4C;
extern "C" int DAT_00456220;
extern "C" int DAT_00456224;
extern "C" int DAT_00487FD4;
extern "C" unsigned char DAT_004A0280;
extern "C" unsigned char DAT_004A0284;
extern "C" unsigned char DAT_004A0285;
extern "C" unsigned char DAT_004A0288;
extern "C" unsigned char DAT_004A028C;
extern "C" unsigned char DAT_004A0293;
extern "C" unsigned char DAT_004A0294;
extern "C" unsigned char DAT_004A0295;
extern "C" int DAT_004A2A1C;
extern "C" int DAT_004A2A38;

extern "C" void __cdecl FUN_00419520(int**);
extern "C" void __cdecl FUN_00428CC0(int, int, int, int, int, int);
extern "C" int __cdecl FUN_0043FAE0(char*);
extern "C" void __cdecl FUN_0043FAA0(int, int, int, char*, int);
extern "C" void __cdecl FUN_00444590(int**);
extern "C" char* __cdecl FUN_0040D890(char*, int**);

extern "C" void __cdecl HelpBoxDraw_0040d980(int** param_1)
{
    int iVar3, iVar6, iVar7;
    int* pGVar2, *pGVar4, *pGVar5, *pGVar9;
    int** ppGVar8;
    char cVar1;
    // The original reserves and clears a complete 0x204-byte temporary
    // object.  Ghidra split the first 0x78 bytes into local_204[30] and
    // named the following fields separately; clearing 0x81 words through
    // the truncated array corrupts this function's stack frame.
    int local_204[0x81];

    pGVar2 = param_1[0x28];

    if (((unsigned int)pGVar2 & 0xf) == 3) {
        if (((unsigned int)param_1[0x20] & 2) == 0) {
            if (((unsigned int)pGVar2 & 0x10) == 0) {
                param_1[0x28] = (int*)((unsigned int)pGVar2 & 0xfffffff4 | 4);
                param_1[0x2a] = (int*)((unsigned int)param_1[0x2d] & 0xffff0000);
                param_1[0x29] = (int*)((int)param_1[0x2d] << 0x10);
            }
        } else if (DAT_004A0288 != 0 || DAT_004A0293 != 0 || DAT_004A0294 != 0 || DAT_004A0295 != 0 || DAT_004A028C != 0 || DAT_00487FD4 != 0) {
            param_1[0x28] = (int*)((unsigned int)pGVar2 & 0xfffffff4 | 4);
            param_1[0x2a] = (int*)((unsigned int)param_1[0x2d] & 0xffff0000);
            param_1[0x29] = (int*)((int)param_1[0x2d] << 0x10);
            DAT_004A028C = 0;
        }
    }

    param_1[0x28] = (int*)((unsigned int)param_1[0x28] & 0xfffffef);

    if (param_1[3] != 0) {
        pGVar2 = (int*)(*(int*)((int)param_1[0x25] + 0x78) + (int)(param_1[0x23] - 1) + -0xc);
        param_1[0x25] = pGVar2;
        if ((int)pGVar2 > 0xffff) {
            param_1[0x25] = (int*)((int)pGVar2 + -0x80);
            param_1[0x15] = (int*)((int)param_1[0x15] + 1);
        }
        FUN_00444590(param_1);
    }

    pGVar2 = param_1[0x28];

    switch ((unsigned int)pGVar2 & 0xf) {
    case 1:
        if (((unsigned int)param_1[0x20] & 4) != 0) {
            DAT_00455C4C = DAT_00455C4C + 1;
        }
        param_1[0x28] = (int*)((unsigned int)param_1[0x28] & 0xfffffff2 | 2);
        break;
    case 2: {
        int* pGVar4_temp, *pGVar5_temp;
        pGVar4_temp = (int*)(*(int*)((int)param_1[0x29] + 0x78) + (int)(param_1[0x2b] - 1) + -0xc);
        pGVar5_temp = param_1[0x2d];
        param_1[0x29] = pGVar4_temp;
        pGVar9 = (int*)((int)pGVar5_temp * 0x10000);
        if ((int)pGVar9 <= (int)pGVar4_temp) {
            param_1[0x29] = pGVar9;
        }
        pGVar4_temp = (int*)(*(int*)((int)param_1[0x2a] + 0x78) + (int)(param_1[0x2c] - 1) + -0xc);
        param_1[0x2a] = pGVar4_temp;
        if ((int*)((unsigned int)pGVar5_temp & 0xffff0000) <= pGVar4_temp) {
            param_1[0x2a] = (int*)((unsigned int)pGVar5_temp & 0xffff0000);
        }
        if (param_1[0x29] == pGVar9 && param_1[0x2a] == (int*)((unsigned int)pGVar5_temp & 0xffff0000)) {
            param_1[0x28] = (int*)((unsigned int)pGVar2 & 0xfffffff3 | 3);
        }
        break;
    }
    case 4: {
        int* pGVar5b, *pGVar4b, *pGVar9b;
        pGVar5b = param_1[0x2b];
        pGVar4b = param_1[0x29];
        param_1[0x29] = (int*)((int)pGVar4b - (int)pGVar5b);
        if ((int)pGVar4b - (int)pGVar5b <= (int)pGVar5b) {
            param_1[0x29] = pGVar5b;
        }
        pGVar4b = param_1[0x2c];
        pGVar9b = param_1[0x2a];
        param_1[0x2a] = (int*)((int)pGVar9b - (int)pGVar4b);
        if ((int)pGVar9b - (int)pGVar4b <= (int)pGVar4b) {
            param_1[0x2a] = pGVar4b;
        }
        if (param_1[0x29] == pGVar5b && param_1[0x2a] == pGVar4b) {
            param_1[0x24] = (int*)0x14;
            param_1[0x28] = (int*)((unsigned int)pGVar2 & 0xfffffff5 | 5);
            if (((unsigned int)param_1[0x20] & 4) != 0) {
                DAT_00455C4C = DAT_00455C4C - 1;
            }
            if (((unsigned int)param_1[0x20] & 8) == 0) {
                return;
            }
            FUN_00419520(param_1);
            return;
        }
        break;
    }
    case 5: {
        int* pGVar5c = (int*)((int)&param_1[0x24][-1] + 3);
        param_1[0x24] = pGVar5c;
        if ((int)pGVar5c < 1) {
            param_1[0x28] = (int*)((unsigned int)pGVar2 & 0xfffffff0);
            return;
        }
        break;
    }
    }

    iVar3 = (0x1400000 - (int)param_1[0x29]) >> 1;
    iVar7 = (0xf00000 - (int)param_1[0x2a]) >> 1;
    FUN_00428CC0(iVar3, iVar7, (int)param_1[0x29], (int)param_1[0x2a], DAT_00456220, DAT_00456224);

    if (((unsigned int)param_1[0x28] & 0xf) == 3) {
        pGVar2 = param_1[0x21];
        if (pGVar2 != 0 && DAT_00455C04 == 4) {
            ppGVar8 = (int**)local_204;
            for (iVar7 = 0x81; iVar7 != 0; iVar7--) {
                *ppGVar8 = 0;
                ppGVar8++;
            }
            local_204[30] = DAT_004A2A38 + 0xa00000;
            local_204[31] = DAT_004A2A1C + 0x780000;
            local_204[3] = (int)pGVar2;
            FUN_00444590((int**)local_204);
            return;
        }
        iVar7 = iVar7 + ((unsigned int)param_1[0x27] & 0xffff0000);
        iVar3 = iVar3 + (int)param_1[0x27] * 0x10000;
        cVar1 = *(char*)((int)param_1[0x26] + 4);
        pGVar2 = param_1[0x26];
        while (cVar1 != 0) {
            pGVar5 = (int*)FUN_0040D890((char*)pGVar2, (int**)local_204);
            iVar6 = iVar3;
            if (((unsigned int)local_204[0] & 4) != 0) {
                iVar6 = FUN_0043FAE0((char*)pGVar2);
                iVar6 = (((int)param_1[0x2d] * 0x10000 - iVar6) >> 1) + (int)param_1[0x27] * -0x10000 + iVar3;
            }
            FUN_0043FAA0(iVar6, iVar7, (int)param_1[0x27], (char*)pGVar2, (int)param_1[0x2d]);
            if (((unsigned int)local_204[0] & 1) == 0) {
                *(char*)((int)pGVar5 + 4) = 0x5c;
                pGVar5 = (int*)((int)pGVar5 + 6);
                iVar7 = iVar7 + ((unsigned int)param_1[0x28] & 0xffff0000);
            }
            pGVar2 = pGVar5;
            cVar1 = *(char*)((int)pGVar5 + 4);
        }
    }
}
