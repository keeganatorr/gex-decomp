// Adapted from pc_decomp_backup/src/functions/FUN_00437500.cpp
// Historical source SHA256: 8631408bd24ea2bbcbff2a675760e7073dab5192c5345fc5d89b789c59421f64
extern "C" {
extern "C" { extern int DAT_00458C7C; }
extern "C" { extern int DAT_0045C990; }
extern "C" { extern int DAT_0045C994; }
extern "C" { extern int DAT_0045C99C; }
extern "C" { extern int DAT_0045C9A0; }
extern "C" { extern void** PTR_00464510; }
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" int __cdecl FUN_004373C0(int);
extern "C" void __cdecl FUN_004374A0(int*, int*);
extern "C" int __cdecl FUN_00439130(int, int);
extern "C" int __cdecl FUN_00439190(int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar2, iVar3, iVar4, iVar5;
    int local_10, local_c;
    int local_8, local_4;
    void* pGVar1;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar1 = param_1[0x38];
    pGVar1 = (void*)((((int)pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200) ^ (unsigned int)pGVar1);
    param_1[0x38] = pGVar1;
    param_1[0x38] = (void*)((unsigned int)pGVar1 & 0xfffffeff);

    if (FUN_0040FCE0(param_1) != 0) return;

    param_1[0x38] = PTR_00464510[0x38];
    if (DAT_00458C7C != 0) {
        DAT_0045C990 = 2;
        DAT_00458C7C = 0;
    }

    iVar2 = FUN_00419C00(PTR_00464510, 0, 0, &local_c, &local_10);
    if (iVar2 == 0) goto FUN_00437762;

    iVar2 = DAT_0045C99C * DAT_0045C994 + (DAT_0045C99C * DAT_0045C994 >> 0x1f & 7U);
    iVar3 = iVar2 >> 3;
    iVar4 = DAT_0045C9A0 * DAT_0045C994 + (DAT_0045C9A0 * DAT_0045C994 >> 0x1f & 7U);
    iVar5 = (int)PTR_00464510[0x1e] + local_c + -0x1c;
    local_10 = (int)PTR_00464510[0x1f] + local_10 + -0x1c;
    local_c = iVar5;

    if (DAT_0045C9A0 == 0x640000) {
        param_1[0x1f] = (void*)(local_10 + (iVar4 >> 3));
        iVar4 = iVar4 >> 0x13;
        if ((unsigned int)PTR_00464510[0x1b] & 0x80000000) {
            iVar2 = FUN_004373C0(iVar4);
            param_1[0x1e] = (void*)(iVar5 + iVar2 * -0x10000);
        } else {
            iVar2 = FUN_004373C0(iVar4);
            param_1[0x1e] = (void*)(iVar2 * 0x10000 + local_c);
        }
    } else {
        param_1[0x1e] = (void*)(iVar3 + iVar5);
        if ((unsigned int)PTR_00464510[0x1b] & 0x80000000) {
            iVar2 = FUN_004373C0(-iVar3 >> 0x10);
            param_1[0x1f] = (void*)(iVar2 * 0x10000 + local_10);
        } else {
            iVar2 = FUN_004373C0(iVar2 >> 0x13);
            param_1[0x1f] = (void*)(iVar2 * 0x10000 + local_10);
        }
    }

    if (param_1[0x35] == param_1[0x1e]) goto FUN_00437762;
    local_4 = (int)param_1[0x1e] - (int)param_1[0x35];
    local_8 = (int)param_1[0x1f] - (int)param_1[0x36];
    FUN_004374A0(&local_4, &local_8);

    {
        void* pGVar1_new;
        if ((unsigned int)PTR_00464510[0x1b] & 0x80000000) {
            if (DAT_0045C990 == 1) {
FUN_0043774B:
                iVar2 = FUN_00439130(local_4, local_8);
                pGVar1_new = (void*)FUN_00439190(iVar2);
            } else {
                pGVar1_new = (void*)FUN_00439130(local_4, local_8);
            }
        } else {
            if (DAT_0045C990 != 1) goto FUN_0043774B;
            pGVar1_new = (void*)FUN_00439130(local_4, local_8);
        }
        param_1[0x31] = pGVar1_new;
    }

FUN_00437762:
    if (param_1[0x45] == (void*)-1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = (void*)-1;
}
}
