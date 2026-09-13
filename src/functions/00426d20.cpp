// Adapted from pc_decomp_backup/src/functions/FUN_00426D20.cpp
// Historical source SHA256: c245131a72fac1e660d949172d7937028917496e011531c0004c50de0dd4973b
extern "C" {
extern "C" { extern void* DAT_004A2990; }
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);
extern "C" int __cdecl FUN_00421560(void*, void*);
extern "C" void __cdecl FUN_00424090(void*);
extern "C" int __cdecl FUN_00424980(void*);
extern "C" void __cdecl FUN_004250B0(void*);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    param_1[0x26] = (void*)((int)param_1[0x26] + 1);
    if ((int)param_1[0x26] > 1) {
        param_1[0x26] = (void*)0x0;
        if ((int)param_1[0x15] == 5) {
            FUN_00424090((void*)param_1);
            return;
        }
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
    }
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
    if (FUN_00424980((void*)param_1) == 0) {
        if (FUN_00421560(DAT_004A2990, (void*)param_1) == 0) {
            FUN_004250B0((void*)param_1);
        }
    }
}
}
