// Adapted from pc_decomp_backup/src/functions/FUN_00422790.cpp
// Historical source SHA256: adec7f372e2c46ad71d8c7dd07d16f452b928520e46c8068574fb8c2600dbf58
extern "C" {
extern "C" { extern int DAT_004A2818; }
extern "C" { extern int DAT_004A2838; }

extern "C" int __cdecl FUN_00419C00(int, int, int, int*, int*);

extern "C" void __cdecl GEX_Target(int param_1)
{
    int a;
    int b;
    int pad1, pad2;

    if (DAT_004A2818 != 0 && DAT_004A2838 != 0) {
        if (FUN_00419C00(param_1, 3, 0, &a, &b) != 0) {
            *(int*)(DAT_004A2838 + 0x78) = *(int*)(param_1 + 0x78) + b;
            *(int*)(DAT_004A2838 + 0x7c) = *(int*)(param_1 + 0x7c) + a;
        }
    }
}
}
