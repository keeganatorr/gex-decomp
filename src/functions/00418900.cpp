// Adapted from pc_decomp_backup/src/functions/FUN_00418900.cpp
// Historical source SHA256: 51f0b25682f4a0af98762acc5c3550b27f2340adc510fc7ebb2f4828fe838a5c
extern "C" {
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" unsigned int __cdecl FUN_0040F1D0(int, void**);
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl GEX_Target(int p1, void** p2)
{
    int local_8, local_4;
    int r = FUN_00419C00(p2, 0, 0, &local_8, &local_4);
    if (r != 0) {
        p2[0x1e] = (void*)((int)p2[0x1e] + local_8 + -0x1c);
        p2[0x1f] = (void*)((int)p2[0x1f] + local_4 + -0x1c);
        unsigned int u = FUN_0040F1D0(FUN_004A2990, p2);
        if ((int)u > -0x200000 && (int)u < 0x200000) {
            p2[0x1f] = (void*)((int)p2[0x1f] + (int)(u - 0x1c));
        }
        p2[0x1e] = (void*)((int)p2[0x1e] - local_8);
        p2[0x37] = (void*)0x7fff0000;
        p2[0x1f] = (void*)((int)p2[0x1f] - local_4);
    }
    return p1;
}
}
