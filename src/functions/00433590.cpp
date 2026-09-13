// Adapted from pc_decomp_backup/src/functions/FUN_00433590.cpp
// Historical source SHA256: 9f1807630d9158d9b0490e5129f7ff3230fe6fd96397d41b88670d633deccb8e
extern "C" {
extern "C" { extern int DAT_00464278; }
extern "C" { extern void** DAT_004642A0; }
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" void* __cdecl FUN_00435D90(void**, void*, void*);
extern "C" { extern const char* DAT_0045B57C[]; }
extern "C" { extern const char DAT_0045B5F0[]; }

extern "C" void* __cdecl GEX_Target(void** param_1, void* param_2, void* PointerToScript, int eventNumber)
{
    if (DAT_00464278 != 0 && param_1[2] == (void*)DAT_004642A0) {
        FUN_00405390(DAT_0045B5F0, DAT_0045B57C[eventNumber], PointerToScript);
    }
    return FUN_00435D90(param_1, param_2, PointerToScript);
}
}
