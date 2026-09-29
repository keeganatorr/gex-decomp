// Adapted from pc_decomp_backup/src/functions/FUN_0042a49b_MapFunkUnk.cpp
// Historical source SHA256: c9f6ee51558c5b2752cdb03670c236909f1eabb7fdc0f08042ae77b15ee8e375
extern "C" {
extern "C" int __cdecl FUN_0042A630_Gex_Frames(void**);
extern "C" void __cdecl FUN_0041A360(int, int);
extern "C" void __cdecl FUN_0042a49b_MapFunkUnk() { void** unaff_ESI; if (FUN_0042A630_Gex_Frames(unaff_ESI)) { unaff_ESI[0x1c] = (void*)8; FUN_0041A360(100, 0xff); } }
}
