// Adapted from pc_decomp_backup/src/functions/FUN_00438AF0.cpp
// Historical source SHA256: a969cdaf352ce6e71db33bf2232da2b95cac6ee30c7f6802930b8948f8b36e0b
extern "C" {
extern "C" { extern int DAT_00455c54_DebugVar; }
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" { extern const char FUN_0045F088[]; }
extern "C" { extern const char FUN_0045F0D0[]; }

extern "C" int __cdecl event_hit45down_00438af0(int param_1)
{
    if ((*(unsigned int*)(param_1 + 0x6c) & 0x1f000000) == 0x9000000) {
        if (DAT_00455c54_DebugVar > 1) {
            FUN_00405390(FUN_0045F088, *(int*)(param_1 + 8));
            FUN_00405390(FUN_0045F0D0);
        }
        return 1;
    }
    return 0;
}
}
