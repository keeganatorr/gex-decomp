// Adapted from pc_decomp_backup/src/functions/FUN_00423B40.cpp
// Historical source SHA256: 8daae83dc845dfaecdc62b30c1024c7db57918a2cb42f88fece474456a3597a2
extern "C" {
extern "C" { extern int DAT_0045a6d8; }
extern "C" { extern unsigned char FUN_004A0283; }
extern "C" { extern unsigned char FUN_004A0293; }
extern "C" { extern unsigned char FUN_004A0295; }
extern "C" void __cdecl FUN_00413E60(void**);

extern "C" int __cdecl GEX_Target(void** param_1)
{
    if (DAT_0045a6d8 != 0 &&
        FUN_004A0283 != 0 &&
        FUN_004A0293 == 0 &&
        FUN_004A0295 == 0) {
        FUN_00413E60(param_1);
        return 1;
    }
    return 0;
}
}
