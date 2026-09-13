// Adapted from pc_decomp_backup/src/functions/FUN_0040CB70.cpp
// Historical source SHA256: 7be33b4a719d0c6404a7bbe56f50fc38663c218a92c2e3ca2054b3d8bd57167f
extern "C" {
extern "C" void* FUN_0040C110(int, int);
extern "C" void FUN_00405350(const char*, ...);

extern "C" void __cdecl GEX_Target(int indexNumber, unsigned char* buttonNumber)
{
    void** activeGob = (void**)FUN_0040C110(0x7b, indexNumber);
    void* pGVar2 = activeGob[0x27];
    int result = 0;

    {
        unsigned char* pbVar10 = buttonNumber;
        void* pGVar8 = pGVar2;
        while (1) {
            unsigned char bVar1 = *(unsigned char*)pGVar8;
            if (bVar1 != *pbVar10) {
                result = (bVar1 < *pbVar10) ? -1 : 1;
                break;
            }
            if (bVar1 == 0) break;
            bVar1 = *(unsigned char*)((int)pGVar8 + 1);
            if (bVar1 != pbVar10[1]) {
                result = (bVar1 < pbVar10[1]) ? -1 : 1;
                break;
            }
            pGVar8 = (void*)((int)pGVar8 + 2);
            pbVar10 += 2;
        }
    }

    if (result != 0) {
        activeGob[0x27] = (void*)buttonNumber;
        int iVar4 = 0;
        int* piVar5 = (int*)0x004560F4;
        while (*piVar5 != indexNumber) {
            piVar5 += 3;
            iVar4++;
        }
        unsigned char* pbVar6 = (unsigned char*)0x004560F0;
        unsigned char* pbVar10 = buttonNumber;
        int iVar9 = 0;
        while (*pbVar6 != 0 || iVar9 < 10) {
            unsigned char* a = pbVar6;
            unsigned char* b = pbVar10;
            int cmp;
            while (1) {
                if (*a != *b) { cmp = (*a < *b) ? -1 : 1; break; }
                if (*a == 0) { cmp = 0; break; }
                a++; b++;
                if (*a != *b) { cmp = (*a < *b) ? -1 : 1; break; }
                if (*a == 0) { cmp = 0; break; }
                a++; b++;
            }
            if (cmp == 0) break;
            pbVar6 += 10;
            iVar9++;
        }
        *(int*)((int)activeGob + 0x9c + iVar4 * 4) = *(int*)(0x004560F4 + iVar9 * 4);
        *(int*)(0x004560F4 + iVar4 * 4) = indexNumber;
    }
}
}
