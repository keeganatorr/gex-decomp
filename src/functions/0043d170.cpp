// Adapted from pc_decomp_backup/src/functions/FUN_0043D170.cpp
// Historical source SHA256: bd12ae4f19a92e31081fcacc2691516e1f2454d4221eb4acdc3d358ebc5ccd0e
extern "C" {
extern "C" void __cdecl FUN_00417B70(void*);
extern "C" { extern void* FUN_004A27FC; }

extern "C" void __cdecl GEX_Target(int param_1, int* param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;

    if (*param_2 != 0) {
        uVar2 = **(unsigned int**)(param_1 + 0x170) & 0xffff;
        uVar1 = **(unsigned int**)(param_1 + 0x174) & 0xffff;
        if (*(void***)(param_1 + 0x178) == (void**)FUN_004A27FC &&
            ((uVar2 == 1 || uVar2 == 7 ||
              ((uVar2 == 0 || uVar2 == 8) && (uVar1 == 0 || uVar1 == 8))))) {
            FUN_00417B70((void*)param_1);
        }
    }
}
}
