// Adapted from pc_decomp_backup/src/functions/FUN_004256E0.cpp
// Historical source SHA256: c0af5c6be54d64e20f4dba5d52b51d47b55268bf4df7c5c9f7bf26181138c96b
extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int DAT_004a01e0;
extern void *DAT_004A2990;
extern void *DAT_004a2888;
extern "C" int __cdecl FUN_00420C10(int, int);
extern "C" int __cdecl FUN_00420820(int, int);
extern "C" int __cdecl FUN_00420C70(void**);
extern "C" void __cdecl FUN_004213C0(void*, void**);
extern "C" void __cdecl FUN_004213F0(void**);
extern "C" void __cdecl FUN_004214D0(void**);
extern "C" int __cdecl FUN_004215D0(void**, int);
extern "C" void __cdecl FUN_00421740(void**);
extern "C" int __cdecl FUN_004212D0(void**);
extern "C" void __cdecl FUN_004219C0(void);
extern "C" void __cdecl FUN_0042D2C0(void*, void**, void (__cdecl *)(void));
extern "C" void __cdecl FUN_00422360(void**);
extern "C" void __cdecl FUN_00422410(void**);
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
    int local_28[10];
    if ((DAT_004A0294 && FUN_00420C70(param_1)) ||
        (DAT_004A0295 && !DAT_004A0293)) {
        FUN_00423120();
        if (DAT_004a2888)
            FUN_00425460(param_1);
        else if (DAT_004A0294)
            FUN_004250B0(param_1);
        else
            FUN_00425AF0(param_1);
        return;
    }
    FUN_00423B80(param_1);
    if (FUN_0041CB80(param_1, (int**)local_28) != 0) {
        int x = (int)param_1[0x1e];
        if ((FUN_00420C10(x - 0xc0000, local_28[7]),
             FUN_00420820(x - 0xc0000, local_28[7])) ||
            FUN_00420820(x + 0xc0000, local_28[7])) {
            FUN_00423120();
            if (DAT_004a2888)
                FUN_00425460(param_1);
            else
                FUN_004250B0(param_1);
            return;
        }
    }
    if (FUN_00423AB0(param_1) || FUN_00423190(param_1) ||
        FUN_00423B40(param_1) >= 1) {
        FUN_00423130(param_1);
        return;
    }
    param_1[0x26] = (void*)((int)param_1[0x26] + 1);
    if ((int)param_1[0x26] >= 2) {
        param_1[0x26] = 0;
        if ((int)param_1[0x15] == 10) {
            FUN_00423120();
            if (DAT_004a2888)
                FUN_00425460(param_1);
            else
                FUN_004250B0(param_1);
            return;
        }
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        FUN_00420960(param_1);
        FUN_00422790(param_1);
    }
    FUN_004244E0(param_1, 0x10000);
    FUN_004213F0(param_1);
    DAT_004a01e0 = 0;
    FUN_004213C0(DAT_004A2990, param_1);
    FUN_004214D0(param_1);
    FUN_0042D2C0(DAT_004A2990, param_1, FUN_004219C0);
    FUN_00421740(param_1);
    if (FUN_004212D0(param_1)) {
        if (DAT_004a2888) {
            FUN_00422410(param_1);
            FUN_00422360(param_1);
        }
    } else if (FUN_004215D0(param_1, 0)) {
        if (DAT_004a2888) {
            FUN_00422410(param_1);
            FUN_00422360(param_1);
        }
        FUN_00425C10(param_1);
    }
    FUN_00423130(param_1);
}
}
