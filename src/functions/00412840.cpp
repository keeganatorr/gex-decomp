// Adapted from pc_decomp_backup/src/functions/FUN_00412840.cpp
// Historical source SHA256: 921fcb8fbd9ebb1a009a3f11a6a5cac5f79d3c0f3fe98f193b8e1d8569e44a3b
extern "C" {
extern "C" void __cdecl FUN_00420BC0(int*);
extern "C" void __cdecl FUN_00412830(int*);

extern "C" void __cdecl InitPlayerOutside90Trans_00412840(int* p)
{
    int* esi = p;
    FUN_00420BC0(esi);
    esi[0x70 / 4] = 0x51;
    FUN_00412830(esi);
}
}
