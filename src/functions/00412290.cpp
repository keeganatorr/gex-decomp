// Adapted from pc_decomp_backup/src/functions/FUN_00412290.cpp
// Historical source SHA256: 941197a8860023b99987102ac6e21cf9eb3d0eb758d9466d44c4f4786daf0e29
extern "C" {
extern "C" int __cdecl FUN_00421F20(void*);
extern "C" void __cdecl FUN_00421CD0(void*);
extern "C" void __cdecl FUN_00411160(void*);
extern "C" void __cdecl FUN_004112E0(void*, int);
extern "C" { extern int FUN_004A2864; }
extern "C" { extern int DAT_00458548[]; }
extern "C" { extern int DAT_004585E8[]; }
extern "C" { extern int DAT_004585EC[]; }
extern "C" { extern unsigned int FUN_00458668[]; }
extern "C" { extern unsigned int FUN_00457F28[]; }
extern "C" { extern int DAT_00457FE8[]; }
extern "C" { extern int DAT_00457FEC[]; }

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int iVar1 = FUN_00421F20(param_1);
    if (iVar1 != 0) {
        FUN_00421CD0(param_1);
        int v26 = *(int*)((char*)param_1 + 0x98);
        int nv26 = v26 + 0x40;
        *(int*)((char*)param_1 + 0x98) = nv26;
        if (nv26 > 0x10000) {
            *(int*)((char*)param_1 + 0x98) = v26 - 0x40;
            unsigned int uVar5 = ((unsigned int)*(int*)((char*)param_1 + 0x6c) & 0x80000000) >> 0x1c
                               | (int)*(int*)((char*)param_1 + 0xc4) >> 0x15;
            int v15 = *(int*)((char*)param_1 + 0x54) + 1;
            *(int*)((char*)param_1 + 0x54) = v15;
            if (v15 > 3) {
                uVar5 = *(unsigned int*)((char*)FUN_00458668 + uVar5 * 4);
                int v1b_adj = *(int*)((char*)param_1 + 0x6c) & 0x7fffffff;
                *(int*)((char*)param_1 + 0x6c) = v1b_adj;
                *(int*)((char*)param_1 + 0xc4) = (uVar5 & 7) << 0x15;
                if ((uVar5 & 8) != 0) {
                    *(int*)((char*)param_1 + 0x6c) = v1b_adj | 0x80000000;
                }
                if (FUN_004A2864 == 0) {
                    *(int*)((char*)param_1 + 0x78) = *(int*)((char*)param_1 + 0x78) & 0xffe00000;
                    *(int*)((char*)param_1 + 0x7c) = *(int*)((char*)param_1 + 0x7c) & 0xffe00000;
                } else {
                    FUN_004112E0(param_1, *(unsigned int*)((char*)FUN_00457F28 + uVar5 * 4));
                }
                *(int*)((char*)param_1 + 0x78) = (*(int*)((char*)param_1 + 0x78) + *(int*)((char*)DAT_00457FE8 + uVar5 * 8)) & 0xffe00000;
                *(int*)((char*)param_1 + 0x7c) = (*(int*)((char*)param_1 + 0x7c) + *(int*)((char*)DAT_00457FEC + uVar5 * 8)) & 0xffe00000;
                FUN_00411160(param_1);
            }
        }
    }
}
}
