// Adapted from pc_decomp_backup/src/functions/FUN_00420770.cpp
// Historical source SHA256: db4dfb95dc9059a3f1b1ffb7e9a6ff8d1eb6493566df8461c014dd6063ceae8d
extern "C" {
extern "C" { extern void** FUN_004A27FC; }
extern "C" void __cdecl FUN_0041FA80(int);

extern "C" void __cdecl GEX_Target(void** param_1, int param_2)
{
    unsigned int uVar1;

    if (FUN_004A27FC != 0) {
        uVar1 = (int)param_1[0x1e] - (int)((void**)FUN_004A27FC)[0x1e];
        if (((int)((uVar1 ^ (int)uVar1 >> 31) - ((int)uVar1 >> 31)) < 0x3c0000) &&
            -0x280000 < (int)param_1[0x1f] - (int)((void**)FUN_004A27FC)[0x1f] &&
            (int)param_1[0x1f] - (int)((void**)FUN_004A27FC)[0x1f] < 0x280000) {
            if (((int)uVar1 > 0 && ((unsigned int)param_1[0x1b] & 0x80000000) == 0) ||
                ((int)uVar1 < 0 && ((unsigned int)param_1[0x1b] & 0x80000000) != 0)) {
                FUN_0041FA80(param_2);
            }
        }
    }
}
}
