// Adapted from pc_decomp_backup/src/functions/FUN_00414370.cpp
// Historical source SHA256: c088654423130dc72bc4306cf959cbfaf4f64ba2d09d7aff52b115cb4c3c888c
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414330(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = p[0x26] = 0;
    p[0x1f] = (void*)((int)p[0x1f] - 0x200000);
    p[0x1c] = (void*)0x38;
    p[0x14] = (void*)0x5B;
    FUN_00414330(p);
}
}
