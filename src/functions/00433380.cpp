// Adapted from pc_decomp_backup/src/functions/FUN_00433380.cpp
// Historical source SHA256: aaccceee64786ca9b51c66f59ce048791e1c162c2d0d10308b887ea05645bd8b
extern "C" {
extern "C" int __cdecl FUN_00428C80(int);

extern "C" void __cdecl ob369Init_00433380(void** p)
{
    p[0x14] = (void*)0x1a;
    int r = FUN_00428C80(5);
    p[0x28] = (void*)2;
    p[0x34] = (void*)0x30000000;
    p[0x27] = (void*)(r + 1);
}
}
