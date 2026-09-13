// Adapted from pc_decomp_backup/src/functions/FUN_00419FE0.cpp
// Historical source SHA256: e29832488d28c6ff8f5ad49cbe42065fd713282dab8d33c33b2a3c471194280b
extern "C" {
extern "C" int __cdecl FUN_00440430_CheckWallCollisionInner(void*, void*, int, int);

extern "C" { extern void* FUN_004A2990; }

extern "C" int __cdecl GEX_Target(void* param_1, int param_2, unsigned int param_3)
{
    if (param_2 >= 0 &&
        param_2 < *(int*)(*(int*)((int)FUN_004A2990 + 4) + 4) &&
        (int)param_3 >= 0 &&
        (int)param_3 < *(int*)(*(int*)((int)FUN_004A2990 + 4) + 8)) {
        return (int)FUN_00440430_CheckWallCollisionInner(
            *(void**)((int)param_1 + 4),
            *(void**)((int)param_1 + 0x14),
            param_2, param_3);
    }
    return **(int**)((int)param_1 + 0x14);
}
}
