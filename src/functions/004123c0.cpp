// Adapted from pc_decomp_backup/src/functions/FUN_004123C0.cpp
// Historical source SHA256: c13f1e478643ec7987d59c1fd4305fa75c072809f6a75f7e5d04df6869718300
extern "C" {
extern "C" { extern int DAT_00457EE8; }
extern "C" { extern int DAT_00457F68; }
extern "C" { extern int DAT_00457F6C; }
extern "C" { extern int DAT_00458548; }
extern "C" { extern int DAT_004585E8; }
extern "C" { extern int DAT_004585EC; }
extern "C" { extern int DAT_004A2864; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004112E0(void**, int);
extern "C" void __cdecl FUN_00412290(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar3;
    void** pGVar1;
    void** pGVar2;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x44;
    param_1[0x26] = 0;
    param_1[0x14] = (void*)0x52;
    param_1[0x15] = 0;
    uVar3 = ((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15;
    if (DAT_004A2864 == 0) {
        param_1[0x1e] = (void*)((unsigned int)param_1[0x1e] & 0xffe00000);
        param_1[0x1f] = (void*)((unsigned int)param_1[0x1f] & 0xffe00000);
    } else {
        FUN_004112E0(param_1, *(int*)((int)&DAT_00457EE8 + uVar3 * 4));
    }
    pGVar2 = (void**)((int)((void**)((int***)param_1[0x1e])[0])[0] + *(int*)((int)&DAT_00457F68 + uVar3 * 8) + -0x1c);
    param_1[0x1e] = pGVar2;
    pGVar1 = (void**)((int)((void**)((int***)param_1[0x1f])[0])[0] + *(int*)((int)&DAT_00457F6C + uVar3 * 8) + -0x1c);
    param_1[0x1f] = pGVar1;
    param_1[0x1e] = (void*)((int)((void**)((int***)pGVar2)[0])[0] + *(int*)((int)&DAT_00458548 + ((int)((void**)((int***)param_1[0x15])[0])[0] + *(int*)((int)&DAT_004585E8 + uVar3 * 8) * 5 + -0x1c) * 4) + -0x1c);
    param_1[0x1f] = (void*)((int)((void**)((int***)pGVar1)[0])[0] + *(int*)((int)&DAT_00458548 + ((int)((void**)((int***)param_1[0x15])[0])[0] + *(int*)((int)&DAT_004585EC + uVar3 * 8) * 5 + -0x1c) * 4) + -0x1c);
    FUN_00412290(param_1);
}
}
