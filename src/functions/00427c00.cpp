// Adapted from pc_decomp_backup/src/functions/FUN_00427C00.cpp
// Historical source SHA256: f0382ea1548d2b9ee9784a9c20ec375842765d23078c299391b08520b4246676
extern "C" {
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int FUN_004A2990; }
extern "C" void __cdecl FUN_00422360(void*);
extern "C" void __cdecl FUN_00424B80(void*);
extern "C" void __cdecl FUN_00427760(void*);
extern "C" void __cdecl FUN_00424AA0(void*);
extern "C" void __cdecl FUN_00424090(void*);
extern "C" void __cdecl FUN_004250B0(void*);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(int, void*);
extern "C" int __cdecl FUN_00421560(int, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00422360(param_1);
        if (DAT_004A0294 != 0) {
            FUN_00424B80(param_1);
            return;
        }
        FUN_00427760(param_1);
        return;
    }
    (*(int*)((char*)param_1 + 0x98))++;
    if (*(int*)((char*)param_1 + 0x98) > 2) {
        *(int*)((char*)param_1 + 0x98) = 0;
        (*(int*)((char*)param_1 + 0x54))++;
        if (*(int*)((char*)param_1 + 0x54) > 3) {
            FUN_00422360(param_1);
            if (*(int*)((char*)param_1 + 0xa4) != 0) {
                FUN_00424AA0(param_1);
                return;
            }
            FUN_00424090(param_1);
            return;
        }
    }
    FUN_004213F0(param_1);
    FUN_004213C0(FUN_004A2990, param_1);
    if (FUN_00421560(FUN_004A2990, param_1) == 0) {
        FUN_00422360(param_1);
        FUN_004250B0(param_1);
    }
}
}
