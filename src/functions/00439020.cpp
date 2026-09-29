// Adapted from pc_decomp_backup/src/functions/FUN_00439020.cpp
// Historical source SHA256: 872f63a4e1521517d2afc628feee4a88e7a7d5c248919589704a45512b6d67bf
extern "C" {
extern "C" { extern int DAT_00455C54; }
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" int __cdecl event_wallBreak_00439020(void** param_1)
{
    if (((unsigned int)param_1[0x38] & 0x800000) != 0) {
        if (DAT_00455C54 > 1) {
            FUN_00405390((const char*)0x0045f088, param_1[2]);
            FUN_00405390((const char*)0x0045f1e8);
        }
        param_1[0x38] = (void*)((unsigned int)param_1[0x38] & 0xff7fffff);
        return 1;
    }
    return 0;
}
}
