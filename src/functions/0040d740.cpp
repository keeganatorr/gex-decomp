// Adapted from pc_decomp_backup/src/functions/FUN_0040D740.cpp
// Historical source SHA256: fd31ca49d5a8a5df321969dcfb3f8612fa8c546556e1ed5dd9688db3314f52f9
extern "C" {
extern "C" { extern int DAT_00455c04; }
extern "C" { extern int DAT_00456228; }
extern "C" void __cdecl FUN_00419B80(void**, int);
extern "C" int __cdecl FUN_0040D890(char*, unsigned int*);
extern "C" int __cdecl FUN_0043FAE0(char*);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    char* passwordString;
    int iVar6;
    int iVar7;
    unsigned int uVar5;
    unsigned int local_4;

    passwordString = (char*)param_1[0x26];
    FUN_00419B80(param_1, 9);
    param_1[0x20] = (void*)((unsigned int)param_1[0x20] | 1);
    param_1[0x28] = (void*)((unsigned int)param_1[0x28] & 0xfffffff0);
    if ((DAT_00455c04 == 4) && (param_1[0x21] != 0)) {
        {
            int* piVar2;
            piVar2 = (int*)((int)param_1[0x21] + 0x1c + 0x0c + 0x0c + 0x0c + 8); 
            uVar5 = (*piVar2 >> 0x10) + 0x20;
            iVar7 = (piVar2[1] >> 0x10) + 0x20;
            if ((int)uVar5 < 5 || iVar7 < 5) {
                uVar5 = 100;
                iVar7 = 100;
            }
        }
    } else {
        iVar6 = 0;
        iVar7 = ((unsigned int)param_1[0x27] >> 0x10) * 2;
        while (*passwordString != '\0') {
            char* pGVar3;
            int iVar4;
            pGVar3 = (char*)FUN_0040D890(passwordString, &local_4);
            iVar4 = FUN_0043FAE0(passwordString);
            if (iVar6 < iVar4 >> 16) {
                iVar6 = iVar4 >> 16;
            }
            if ((local_4 & 1) == 0) {
                *pGVar3 = '\\';
                pGVar3 = pGVar3 + 2;
            }
            if ((void*)passwordString != (void*)pGVar3) {
                iVar7 = iVar7 + ((unsigned int)param_1[0x28] >> 16);
            }
            passwordString = pGVar3;
        }
        uVar5 = iVar6 + ((unsigned int)param_1[0x27] & 0xffff) * 2;
        iVar7 = (iVar7 - ((unsigned int)param_1[0x28] >> 16)) + 7;
    }
    param_1[0x2d] = (void*)(uVar5 | (iVar7 << 16));
    param_1[0x2b] = (void*)((int)(uVar5 << 16) / DAT_00456228);
    param_1[0x2c] = (void*)((iVar7 << 16) / DAT_00456228);
}
}
