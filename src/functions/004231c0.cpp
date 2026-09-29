// Adapted from pc_decomp_backup/src/functions/FUN_004231C0.cpp
// Historical source SHA256: 66998e43d8e32b387b7f29bb81287e98db35a931fbd997b84bf8f248daf5b133
extern "C" {
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern unsigned char DAT_004A0295; }
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" void __cdecl FUN_00425930(void**);
extern "C" void __cdecl FUN_00425690(void**);

extern "C" int __cdecl FUN_004231c0_JumpTongueLash(void** param_1)
{
    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        if (DAT_004A0282 != 0)
            FUN_00425930(param_1);
        else
            FUN_00425690(param_1);
        return 1;
    }
    return 0;
}
}
