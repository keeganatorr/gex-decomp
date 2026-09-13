// Adapted from pc_decomp_backup/src/functions/FUN_00419BC0.cpp
// Historical source SHA256: c6e7c9176bfcc4e3c13ce079889cf379ff051436131552f7a0e10697ec4b3de8
extern "C" {
extern "C" void __cdecl FUN_0042CBF0(void**);
extern "C" void __cdecl FUN_0042CBB0(void**, void**);
extern "C" void __cdecl GEX_Target(void** p1, void** p2) {
    FUN_0042CBF0(p1);
    FUN_0042CBB0(p2, p1);
}
}
