// Adapted from pc_decomp_backup/src/functions/FUN_00425CF0.cpp
// Historical source SHA256: c4b59e17c37ea17294b2c7aa4caa84e7a4e0571e5e478264e50fc966fc9c9b80
extern "C" {
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern int FUN_004A2990; }
extern "C" void __cdecl FUN_00424090(void*);
extern "C" void __cdecl FUN_00424940(void*);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(int, void*);
extern "C" int __cdecl FUN_00421560(int, void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    if (DAT_004A0280 == 0 && DAT_004A0281 == 0 && DAT_004A0294 == 0 && DAT_004A0295 == 0 && DAT_004A0293 == 0) {
        int val;
        val = *(int*)((char*)param_1 + 0x98) + 0x8000;
        *(int*)((char*)param_1 + 0x98) = val;
        if (val >= 0x10000) {
            *(int*)((char*)param_1 + 0x98) = val - 0x10000;
            if (*(int*)((char*)param_1 + 0x54) == 3) {
                FUN_00424090(param_1);
                return;
            }
            (*(int*)((char*)param_1 + 0x54))++;
        }
        FUN_004213F0(param_1);
        FUN_004213C0(FUN_004A2990, param_1);
        FUN_00421560(FUN_004A2990, param_1);
        return;
    }
    FUN_00424940(param_1);
}
}
