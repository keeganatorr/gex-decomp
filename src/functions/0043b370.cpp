// Adapted from pc_decomp_backup/src/functions/FUN_0043B370.cpp
// Historical source SHA256: ce460675704362b26ef6705e2ce921c2c5aedb080039f0aaab19284335f5450f
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);

extern "C" { extern int DAT_0045FFE0; }
extern "C" { extern int DAT_0045FFE4; }

extern "C" void __cdecl GEX_Target(int* param_1)
{
    if (param_1[0x27] & 2) return;
    if (param_1[0x27] & 1) {
        param_1[0x15] += DAT_0045FFE0;
        if (param_1[0x15] > 0x1c) {
            param_1[0x15] -= 0x1d;
            FUN_00441150((void*)param_1);
            return;
        }
    } else {
        param_1[0x15] -= DAT_0045FFE4;
        if (param_1[0x15] < 0) {
            param_1[0x15] += 0x1d;
        }
    }
    FUN_00441150((void*)param_1);
}
}
