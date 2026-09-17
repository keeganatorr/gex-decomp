// Adapted from pc_decomp_backup/src/functions/FUN_00423130.cpp
extern "C" {
extern "C" int __cdecl FUN_00419C00(void**, int, int, int*, int*);
extern "C" { extern void** DAT_004a2888; }
extern "C" void __cdecl GEX_Target(void** param1) {
    if (DAT_004a2888 == 0) return;
    int local_8, local_4;
    int iVar1 = FUN_00419C00(param1, 1, 0, &local_8, &local_4);
    if (iVar1 != 0) {
        DAT_004a2888[0x1e] = (void*)((int)param1[0x1e] + local_8);
        DAT_004a2888[0x1f] = (void*)((int)param1[0x1f] + local_4);
    }
}
}
