// Adapted from pc_decomp_backup/src/functions/FUN_0041FC20.cpp
// Historical source SHA256: 3ce26e949122f278a9b87382d6d1a7717a2ec4c2046aa036ce56c4ab9d0043f1
extern "C" {
extern "C" void __cdecl FUN_0040F300(int, void*);
extern "C" { extern int DAT_00463A28; }
extern "C" { extern int DAT_004639E0; }
extern "C" void __cdecl GEX_Target() {
    DAT_00463A28 = (int)&DAT_004639E0;
    FUN_0040F300(2, (void*)&DAT_004639E0);
}
}
