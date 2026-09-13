// Adapted from pc_decomp_backup/src/functions/FUN_00437790.cpp
// Historical source SHA256: dded4d4cdfd41a4063032c1f00d1fa78c2ad585f1446aee025271f1da48c8738
extern "C" {
extern "C" { extern int DAT_0045C9A0; }
extern "C" { extern void** PTR_00464510; }
extern "C" { extern int PTR_00464518; }

extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" int __cdecl FUN_004373C0(int);
extern "C" void __cdecl FUN_004374A0(unsigned int*, unsigned int*);
extern "C" int __cdecl FUN_00439130(unsigned int, unsigned int);
extern "C" int __cdecl FUN_00439190(int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int local_10 = *(unsigned int*)(PTR_00464518 + 0x7c);
    int iVar3 = *(int*)(PTR_00464518 + 0x78);
    
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    {
        unsigned int p38 = (unsigned int)param_1[0x38];
        p38 = ((p38 * 2 ^ p38) & 0x200 ^ p38);
        p38 = p38 & 0xfffffeff;
        param_1[0x38] = (void*)p38;
    }
    
    if (FUN_0040FCE0(param_1) == 0) {
        param_1[0x38] = PTR_00464510[0x38];
        
        int local_c, local_4;
        int iVar2 = FUN_00419C00(PTR_00464510, 0, 0, &local_c, &local_4);
        int iVar1 = local_c;
        int iVar5 = local_c;
        if (iVar2 != 0) {
            iVar1 = (int)PTR_00464510[0x1f] + local_4 + -0x1c;
            iVar5 = (int)PTR_00464510[0x1e] + local_c + -0x1c;
        }
        iVar3 = ((iVar3 - iVar5) * (int)param_1[0x2c]) / 10;
        iVar2 = (int)((local_10 - iVar1) * (int)param_1[0x2c]) / 10;
        
        if (DAT_0045C9A0 == 0x640000) {
            param_1[0x1f] = (void*)(iVar1 + iVar2);
            iVar2 = iVar2 >> 16;
            if (((unsigned int)PTR_00464510[0x1b] & 0x80000000) == 0) {
                iVar3 = FUN_004373C0(iVar2);
                param_1[0x1e] = (void*)(iVar3 * 0x10000 + iVar5);
            } else {
                iVar3 = FUN_004373C0(iVar2);
                param_1[0x1e] = (void*)(iVar5 + iVar3 * -0x10000);
            }
        } else {
            param_1[0x1e] = (void*)(iVar5 + iVar3);
            if (((unsigned int)PTR_00464510[0x1b] & 0x80000000) == 0) {
                iVar3 = FUN_004373C0(iVar3 >> 16);
                param_1[0x1f] = (void*)(iVar3 * 0x10000 + iVar1);
            } else {
                iVar3 = FUN_004373C0(-iVar3 >> 16);
                param_1[0x1f] = (void*)(iVar3 * 0x10000 + iVar1);
            }
        }
        
        if (param_1[0x35] != param_1[0x1e]) {
            unsigned int local_8 = (unsigned int)param_1[0x1e] - (unsigned int)param_1[0x35];
            unsigned int local_10_val = (unsigned int)param_1[0x1f] - (unsigned int)param_1[0x36];
            FUN_004374A0(&local_8, &local_10_val);
            
        }
        
        if (param_1[0x45] == (void*)0xffffffff) {
            param_1[0x44] = 0;
        }
        param_1[0x45] = (void*)0xffffffff;
    }
}
}
