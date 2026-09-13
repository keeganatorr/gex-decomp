// Adapted from pc_decomp_backup/src/functions/FUN_00435A10.cpp
// Historical source SHA256: dd35934cc0f9d5085eda207f420305c95a7e22629fcd3acbff0a2d6318c5a404
extern "C" {
extern "C" { extern int DAT_0045B7C0; }
extern "C" { extern int DAT_0045B7C4; }
extern "C" { extern int DAT_0045B7C8; }
extern "C" { extern int DAT_0045B7D8; }
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar1;
    int iVar2;
    unsigned int uVar5;

    pGVar1 = (int)param_1[0x2f];
    param_1[0x2f] = (void*)DAT_0045B7C0;
    iVar2 = *(int*)((int)&DAT_0045B7D8 + (int)param_1[0x26] * 4);
    param_1[0x15] = (void*)2;
    param_1[0x14] = (void*)(iVar2 + 1);
    FUN_00444590(param_1);
    uVar5 = (unsigned int)param_1[0x28] & 3;
    if (uVar5 == 1) goto label;
    if (uVar5 == 2) {
        param_1[0x15] = (void*)1;
        param_1[0x2f] = (void*)DAT_0045B7C8;
        FUN_00444590(param_1);
    } else if (uVar5 != 3) {
        param_1[0x2f] = (void*)pGVar1;
        return;
    }
label:
    param_1[0x15] = (void*)0;
    param_1[0x2f] = (void*)DAT_0045B7C4;
    FUN_00444590(param_1);
    param_1[0x2f] = (void*)pGVar1;
}
}
