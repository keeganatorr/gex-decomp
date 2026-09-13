// Adapted from pc_decomp_backup/src/functions/FUN_00414A80.cpp
// Historical source SHA256: 57e11c1eb204de265a2f3a50f87f4b8dcf23f13df935810bd5f1862b0c7f5ca9
extern "C" {
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_00421820(void*);
extern "C" int __cdecl FUN_00421560(int, void*);
extern "C" void __cdecl FUN_00422360(void*);
extern "C" void __cdecl FUN_004250B0(void*);
extern "C" void __cdecl FUN_00424B80(void*);
extern "C" void __cdecl FUN_00414C90(void*);
extern "C" void __cdecl FUN_00427850(void*);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(int, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int iVar1;

    iVar1 = FUN_00421820(param_1);
    if (FUN_00421560(FUN_004A2990, param_1) == 0) {
        FUN_00422360(param_1);
        FUN_004250B0(param_1);
        return;
    }
    if (((iVar1 == 0 && DAT_004A0294 != 0) || DAT_004A0295 != 0) && DAT_004A0293 == 0) {
        FUN_00422360(param_1);
        if (DAT_004A0294 != 0) {
            FUN_00424B80(param_1);
            return;
        }
        FUN_00414C90(param_1);
        return;
    }
    (*(int*)((char*)param_1 + 0x98))++;
    if (*(int*)((char*)param_1 + 0x98) > 3) {
        *(int*)((char*)param_1 + 0x98) = 0;
        (*(int*)((char*)param_1 + 0x54))++;
        if (*(int*)((char*)param_1 + 0x54) > 3) {
            FUN_00427850(param_1);
            return;
        }
    }
    FUN_004213F0(param_1);
    FUN_004213C0(FUN_004A2990, param_1);
}
}
