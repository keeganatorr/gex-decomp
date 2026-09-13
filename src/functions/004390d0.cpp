// Adapted from pc_decomp_backup/src/functions/FUN_004390D0.cpp
// Historical source SHA256: 99097a1aea2ecf37c45b7808837f411000e47e9b906c4c3891a788cbcd8a2d7f
extern "C" {
extern "C" void __cdecl FUN_00437F40(void*, int);

extern "C" void __cdecl GEX_Target(void** p)
{
    int b = (int)p[0x23];
    int a = (int)p[0x25];
    int sum = a + b;
    int bound = (int)p[0x24];
    p[0x23] = (void*)sum;
    if (sum > bound) {
        p[0x23] = (void*)bound;
    } else if (sum > -bound) {
        p[0x23] = (void*)(-bound);
    }
    FUN_00437F40(p, (int)p[0x23]);
}
}
