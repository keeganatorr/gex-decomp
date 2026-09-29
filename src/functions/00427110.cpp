extern "C" {
extern void* DAT_004A2990;
extern int __cdecl FUN_00424980(void**);
extern void __cdecl FUN_004213F0(void*);
extern void __cdecl FUN_004213C0(void*, void*);
extern int __cdecl FUN_00421560(void*, void*);
extern void __cdecl FUN_004250B0(void*);
extern void __cdecl FUN_00424AA0(void**);

extern void __cdecl PlayerRunTurnStop_00427110(void** param_1)
{
    int iVar1;

    iVar1 = FUN_00424980(param_1);
    if (iVar1 == 0) {
        param_1[0x26] = (void*)((int)param_1[0x26] + 1);
        if ((int)param_1[0x26] >= 2) {
            param_1[0x26] = (void*)0x0;
            if ((int)param_1[0x15] == 2) {
                param_1[0x1b] = (void*)((unsigned int)param_1[0x1b] ^ 0x80000000);
                FUN_00424AA0(param_1);
                return;
            }
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        }
        FUN_004213F0((void*)param_1);
        FUN_004213C0(DAT_004A2990, (void*)param_1);
        iVar1 = FUN_00421560(DAT_004A2990, (void*)param_1);
        if (iVar1 == 0) {
            FUN_004250B0((void*)param_1);
        }
    }
}
}
