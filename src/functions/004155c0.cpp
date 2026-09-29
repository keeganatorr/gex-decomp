// Adapted from pc_decomp_backup/src/functions/FUN_004155C0.cpp
// Historical source SHA256: 567379436d7e1f1d4124dc7243ecc8f85cf353ef7bb4a2ad2d75c201765cd882
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004155A0(void**);

extern "C" void __cdecl InitPlayerStartFromCamera_004155c0(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x55;
    param_1[0x14] = (void*)0x29;
    param_1[0x26] = 0;
    param_1[0x1b] = (void*)((unsigned int)param_1[0x1b] | 0x80000000);
    FUN_004155A0(param_1);
}
}
