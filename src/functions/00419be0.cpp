// Adapted from pc_decomp_backup/src/functions/FUN_00419BE0.cpp
// Historical source SHA256: acdb6104abe3f61c74d1ea37ec2fb5ed68aab16559416364232cf9a6efbb2362
extern "C" {
extern "C" void __cdecl FUN_0042CBF0(void**);
extern "C" void __cdecl FUN_0042CBD0(void**, void**);
extern "C" void __cdecl GEX_Target(void** p1, void** p2) {
    FUN_0042CBF0(p1);
    FUN_0042CBD0(p2, p1);
}
}
