// Adapted from pc_decomp_backup/src/functions/FUN_004256E0.cpp
// Historical source SHA256: c0af5c6be54d64e20f4dba5d52b51d47b55268bf4df7c5c9f7bf26181138c96b
extern "C" {
extern "C" int __cdecl FUN_00420820(int, int);
extern "C" int __cdecl FUN_00420C70(void**);
extern "C" void __cdecl FUN_004213C0(int, void**);
extern "C" void __cdecl FUN_004213F0(void**);
extern "C" void __cdecl FUN_004214D0(void**);
extern "C" int __cdecl FUN_004215D0(void**);
extern "C" void __cdecl FUN_00421740(void**);
extern "C" void __cdecl FUN_00422790(void**);
extern "C" void __cdecl FUN_00423120(void);
extern "C" void __cdecl FUN_00423130(void**);
extern "C" int __cdecl FUN_00423190(void**);
extern "C" int __cdecl FUN_00423AB0(void**);
extern "C" int __cdecl FUN_00423B40(void**);
extern "C" void __cdecl FUN_00423B80(void**);
extern "C" void __cdecl FUN_004244E0(void**, int);
extern "C" int __cdecl FUN_0041CB80(void**, int**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00425460(void**);
extern "C" void __cdecl FUN_00425AF0(void**);
extern "C" void __cdecl FUN_00425C10(void**);

extern "C" void __cdecl PlayerJumpTongueLashUp_004256e0(void** param_1)
{
    int local_28[8];
    FUN_00423B80(param_1);
    if (FUN_0041CB80(param_1, (int**)local_28) != 0) {
        FUN_00420C70(param_1);
    }
    if (FUN_00423AB0(param_1) == 0) {
        if (FUN_00423190(param_1) == 0) {
            if (FUN_00423B40(param_1) == 0) {
                param_1[0x26] = (void*)((int)param_1[0x26] + 1);
                if ((int)param_1[0x26] > 1) {
                    param_1[0x26] = 0;
                    param_1[0x15] = (void*)((int)param_1[0x15] + 1);
                    FUN_00420960(param_1);
                    FUN_00422790(param_1);
                }
                FUN_004244E0(param_1, 0x10000);
                FUN_004213F0(param_1);
            }
        }
    }
    FUN_00423130(param_1);
}
}
