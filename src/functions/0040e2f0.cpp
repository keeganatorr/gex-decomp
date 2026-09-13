// Adapted from pc_decomp_backup/src/functions/FUN_0040E2F0.cpp
// Historical source SHA256: 7732fb54a6aeda24acdc52c30ea8299055df1e41d37006441235fc8269b31664
extern "C" {
extern "C" void __cdecl FUN_00444590(void**);
extern "C" { extern int DAT_00462C78; }
extern "C" void __cdecl GEX_Target(void** param1) {
    void* pGVar1 = param1[0x1e];
    void* pGVar2 = param1[0x1f];
    void* pGVar3 = param1[0x7e];
    void* pGVar4 = param1[0x7f];
    void* pGVar5 = param1[0x15];
    param1[0x7e] = (void*)((int)param1[0x2a] + (int)param1[0x23] * 2 + -0x1c);
    param1[0x15] = (void*)3;
    param1[0x1e] = (void*)((int)param1[0x23] + (int)param1[0x2a] + -0x28);
    param1[0x1f] = param1[0x28];
    param1[0x7f] = param1[0x28];
    FUN_00444590(param1);
    if ((int)param1[0x23] < 1) {
        if (DAT_00462C78 != 0) {
            if (DAT_00462C78 < 0x20001) {
                param1[0x1e] = (void*)((int)param1[0x2a] + -0x600);
                param1[0x7e] = (void*)((int)param1[0x2a] + -0x600);
                param1[0x15] = (void*)6;
                param1[0x1f] = (void*)((int)param1[0x28] + -0x4a00);
                param1[0x7f] = (void*)((int)param1[0x28] + -0x4a00);
                FUN_00444590(param1);
            }
            DAT_00462C78 = DAT_00462C78 + -0x8000;
        }
    } else {
        param1[0x23] = (void*)((int)param1[0x23] >> 2);
        param1[0x1e] = pGVar1;
        param1[0x1f] = pGVar2;
        param1[0x7e] = pGVar3;
        param1[0x7f] = pGVar4;
        param1[0x15] = pGVar5;
    }
}
}
