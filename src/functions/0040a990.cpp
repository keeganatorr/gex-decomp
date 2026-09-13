// Adapted from pc_decomp_backup/src/functions/FUN_0040A990.cpp
// Historical source SHA256: d5ea5b103ec3f532093e5407ed782a6cee158610d2887ba4de5e9cc4db5ae82b
extern "C" {
extern "C" { extern int DAT_00455C40; }
extern "C" { extern int DAT_004A2964; }
extern "C" { extern int DAT_004A2954; }
extern "C" { extern int FUN_004A2924; }
extern "C" { extern void* FUN_00455B7C; }
extern "C" { extern void* PTR_M1_00455b80; }
extern "C" void __cdecl FUN_0043E430(int);
extern "C" void __cdecl FUN_0043F080(int);
extern "C" void __cdecl FUN_004202D0();
extern "C" void __cdecl FUN_0040A8C0();
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" void __cdecl FUN_0041EBE0(void*, void*, int);
extern "C" { extern const char FUN_00455E5C[]; }
extern "C" { extern const char FUN_00455CC4[]; }

extern "C" void __cdecl GEX_Target()
{
    if (DAT_00455C40 < 0) {
        FUN_0043E430(1);
        FUN_0043F080(1);
        FUN_004202D0();
        DAT_004A2954 = 0;
        DAT_00455C40 = DAT_004A2964;
        FUN_0040A8C0();
        FUN_00405390(FUN_00455E5C, DAT_004A2964);
        FUN_00405390(FUN_00455CC4, FUN_004A2924);
        FUN_0041EBE0(FUN_00455B7C, PTR_M1_00455b80, 4);
    }
}
}
