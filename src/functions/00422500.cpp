// Adapted from pc_decomp_backup/src/functions/FUN_00422500.cpp
// Historical source SHA256: d68b8a63c6384a8a7c0328ab187164ecb9e20c07d2bf5fb94b6c8f458eee4d35
extern "C" {
extern void* DAT_004A2838;
extern "C" { extern int DAT_004A0234; }
extern "C" { extern int DAT_0045AA30; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004A2838 != (void*)0x0) {
        param_1[0x20] = (void*)(((unsigned int)param_1[0x20] & 0xffffff00) << 3);
        param_1[0x23] = (void*)(((unsigned int)param_1[0x23] & 0xffffff00) << 3);
        return;
    }
    param_1[0x20] = (void*)(*(int*)((int)&DAT_0045AA30 + DAT_004A0234 * 4) * ((int)param_1[0x20] >> 8));
    param_1[0x23] = (void*)(*(int*)((int)&DAT_0045AA30 + DAT_004A0234 * 4) * ((int)param_1[0x23] >> 8));
}
}
