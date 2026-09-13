// Adapted from pc_decomp_backup/src/functions/FUN_00423A50.cpp
// Historical source SHA256: 35fa0729005b80fdf564ebee748c50e67e534e67898ee4e0f999d524f5a71a5a
extern "C" {
extern "C" int __cdecl FUN_00423910(void**);
extern "C" int __cdecl FUN_00423960(void**);
extern "C" int __cdecl FUN_004239B0(void**);
extern "C" int __cdecl FUN_00423A00(void**);

extern "C" int __cdecl GEX_Target(void** param_1)
{
    if (FUN_00423910(param_1) == 0) return 0;
    if (FUN_00423960(param_1) == 0) return 0;
    if (FUN_004239B0(param_1) == 0) return 0;
    if (FUN_00423A00(param_1) == 0) return 0;
    return 1;
}
}
