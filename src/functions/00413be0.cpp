// Adapted from pc_decomp_backup/src/functions/FUN_00413BE0.cpp
// Historical source SHA256: dc9a70dc4ddeca53c29e4506a44fe88bc9be58f5e59275e0bdb80fa24fa8639e
extern "C" {
extern "C" { extern int DAT_00462E50; }
extern "C" { extern int DAT_004A284C; }
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_00414030(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004213F0(void*);
extern "C" void __cdecl FUN_004213C0(void*, void*);
extern "C" int __cdecl FUN_00421560(void*, void*);
extern "C" void __cdecl FUN_00421900(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int pGVar2;

    DAT_004A284C = 1;
    pGVar2 = (int)param_1[0x26];
    param_1[0x26] = (void*)(pGVar2 + 0x40);
    if ((int)param_1[0x26] > 0xffff) {
        param_1[0x26] = (void*)(pGVar2 - 0x40);
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        if ((int)param_1[0x15] == 9) {
            DAT_00462E50 = 0;
            FUN_00414030(param_1);
            return;
        }
        FUN_00420960(param_1);
        FUN_00421900(param_1);
    }
    FUN_004213F0((void*)param_1);
    FUN_004213C0(DAT_004A2990, (void*)param_1);
    if (DAT_00462E50 == 0) {
        FUN_00421560(DAT_004A2990, (void*)param_1);
    }
}
}
