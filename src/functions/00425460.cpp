// Adapted from pc_decomp_backup/src/functions/FUN_00425460.cpp
// Historical source SHA256: 0cd9734b0f1da8a8cadc12b7cff3167fb0c2f3912e0ce80e74adb55783b11ff0
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00422410_EatingObject_pState_Call(void);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004252E0(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    FUN_00420BC0(p);
    p[0x15] = 0;
    p[0x26] = 0;
    p[0x1c] = (void*)0x13;
    p[0x14] = (void*)0x3a;
    FUN_00422410_EatingObject_pState_Call();
    FUN_00420960(p);
    FUN_004252E0(p);
}
}
