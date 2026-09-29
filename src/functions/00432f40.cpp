// Adapted from pc_decomp_backup/src/functions/FUN_00432F40.cpp
// Historical source SHA256: 73e5b703c60c1f3f58a972530cfa1e52e88852d6607bb58251c27de1fedc1b15
extern "C" {
extern "C" void __cdecl FUN_0041A340(void**, int);
extern "C" void __cdecl FUN_00432e60(void**);
extern "C" void __cdecl FUN_0041BE80(void**, int, int);
extern "C" void __cdecl FUN_004317E0(void**);
extern "C" void __cdecl FUN_00437330(void**);
extern "C" void __cdecl FUN_00419520(void**);

extern "C" void __cdecl FUN_00432f40(void** param_1)
{
    if (((unsigned int)param_1[0x1b] & 0x100000) == 0) {
        void** obj = (void**)param_1[0x28];
        FUN_0041A340(param_1, 0x7d);
        FUN_00432e60(param_1);
        FUN_0041BE80(obj, 0, 0);
        FUN_004317E0(obj);
        FUN_00437330(obj);
        FUN_00419520(param_1);
    }
}
}
