// Adapted from pc_decomp_backup/src/functions/FUN_004275A0.cpp
// Historical source SHA256: 14b6e026e4bb1d163455e8d109e42dc1dfabbb3310f7699d90cb3ea62c1e4afc
extern "C" {
extern unsigned char FUN_004A0280;
extern unsigned char FUN_004A0281;

extern "C" void __cdecl PlayerSetXAccl_004275a0(void** param_1, int param_2)
{
    if (FUN_004A0281 != 0) {
        param_1[0x22] = (void*)param_2;
        return;
    }
    if (FUN_004A0280 != 0) {
        param_1[0x22] = (void*)(-param_2);
    }
}
}
