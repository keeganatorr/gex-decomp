// Adapted from pc_decomp_backup/src/functions/FUN_004093E0.cpp
// Historical source SHA256: c6002967900327471b767ef267bd013907afa89c2020b7c76e4dc0952b9baaac
extern "C" {
extern "C" { extern int DAT_004626E4; }
extern "C" void __cdecl FUN_00409250(void*, void*, int);
extern "C" void* __cdecl FUN_004096C0(int);

extern "C" int __cdecl GEX_Target(void* levelFileHandle)
{
    FUN_00409250(*(void**)((char*)levelFileHandle + 8), &DAT_004626E4, 4);
    int bytesToRead = (DAT_004626E4 + 1) * 0x10;
    *(int*)((char*)levelFileHandle + 0) = DAT_004626E4;
    void* buf = FUN_004096C0(bytesToRead);
    *(void**)((char*)levelFileHandle + 4) = buf;
    FUN_00409250(*(void**)((char*)levelFileHandle + 8), buf, bytesToRead);
    return 1;
}
}
