// Adapted from pc_decomp_backup/src/functions/FUN_00414030.cpp
// Historical source SHA256: 2ab3eabb353d434ba2845df50117a5c52280b84b42e94ee20c199e9b7a5e82c8
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_00413F10(void**);
extern "C" { extern unsigned char DAT_004a0282; }
extern "C" { extern unsigned char DAT_004a0285; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1;
    int iVar2;
    int iVar3;
    
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)5;  
    param_1[0x26] = (void*)5;
    param_1[0x14] = (void*)0x2e;
    param_1[0x15] = (void*)9;

    if (DAT_004a0282 == 0 || DAT_004a0285 == 0) {
        param_1[0x23] = (void*)0xfff60000;
    } else {
        param_1[0x23] = (void*)0xfff20000;
    }
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x27] = param_1[0x23];
    pGVar1 = param_1[0x44];
    if (pGVar1 != 0) {
        iVar2 = *(int*)((char*)pGVar1 + 0x78);  
        iVar3 = *(int*)((char*)pGVar1 + 0xd4);  
        param_1[0x44] = (void*)0;
        param_1[0x20] = (void*)((int)param_1[0x20] + (iVar2 - iVar3));
    }
    FUN_00420960(param_1);
    FUN_00413F10(param_1);
}
}
