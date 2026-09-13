// Adapted from pc_decomp_backup/src/functions/FUN_004260C0.cpp
// Historical source SHA256: b3f2ed84e3f7691aa40e0d29628cf05ff73363133d6e304ab40f01ee5b2449f9
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern int DAT_0045a6d4; }
extern "C" { extern int DAT_004a0214; }
extern "C" void __cdecl FUN_00425F40(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0xe;  
    param_1[0x14] = (void*)0x28;
    param_1[0x15] = (void*)2;
    param_1[0x21] = (void*)DAT_0045a6d4;
    if (DAT_004a0214 < 1) {
        param_1[0x26] = (void*)7;
        param_1[0x22] = (void*)0xFFF38000;
    } else {
        param_1[0x26] = (void*)0xa;
        param_1[0x22] = (void*)0xFFF20000;
    }
    param_1[0x25] = (void*)0x14000;
    param_1[0x29] = (void*)2;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x27] = param_1[0x22];

    iVar1 = (int)param_1[0x44];
    if (iVar1 != 0) {
        int iVar2 = *(int*)((char*)iVar1 + 0x78);  
        int iVar3 = *(int*)((char*)iVar1 + 0xd4);  
        param_1[0x44] = (void*)0;
        param_1[0x20] = (void*)((int)param_1[0x20] + (iVar2 - iVar3));
    }
    *(unsigned char*)0x004a0294 = 0;
    FUN_00425F40(param_1);
}
}
