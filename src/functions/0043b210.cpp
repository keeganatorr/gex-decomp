// Adapted from pc_decomp_backup/src/functions/FUN_0043B210.cpp
// Historical source SHA256: c93bd0c509693d2fdc709b1e8bf87f0f80f3be16f1d34deff3a4e5e72868795f
extern "C" {
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int idx;
    int val1, val2;

    idx = 0;
    do {
        val1 = *(int*)(0x004649b8 + idx);
        idx += 4;
        val2 = *(int*)(0x00464bb8 + idx - 4);
        param_1[0x1e] = (void*)val1;
        param_1[0x1f] = (void*)val2;
        param_1[0x7e] = (void*)(val1 - *(int*)(0x00464ab8 + idx - 4));
        param_1[0x14] = (void*)0x0;
        param_1[0x7f] = (void*)(val2 - *(int*)(0x004648b8 + idx - 4));
        param_1[0x15] = (void*)(*(int*)(0x004647b8 + idx - 4));
        FUN_00444590(param_1);
    } while (idx < 0x100);
    param_1[0x14] = (void*)2;
    param_1[0x15] = (void*)0x0;
}
}
