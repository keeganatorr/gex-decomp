// Adapted from pc_decomp_backup/src/functions/FUN_00425E80.cpp
// Historical source SHA256: 2fe87651d01ca3956429b1fa1128a95c58c4abe9143f0ce521ed868353df212d
extern "C" {
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);
extern "C" int __cdecl FUN_00421560(void*, void*);
extern "C" void __cdecl FUN_004260C0(void*);

extern "C" void __cdecl PlayerRunJumpStart_00425e80(void** param_1)
{
    if (param_1[0x26] != (void*)0x0) {
        param_1[0x26] = (void*)((int)param_1[0x26] - 1);
    } else {
        param_1[0x26] = (void*)0x0;
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] == 2) {
            FUN_004260C0((void*)param_1);
            return;
        }
    }
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
    if (FUN_00421560(DAT_004A2990, (void*)param_1) == 0) {
        FUN_004260C0((void*)param_1);
    }
}
}
