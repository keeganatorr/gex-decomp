typedef struct Blob32 { int words[8]; } Blob32;

extern "C" {
extern int DAT_00455B88;
extern int DAT_0045B098;
extern Blob32 DAT_0049fba0[];
extern void* __cdecl FUN_00433590(void**, void*, void*, int);
}

extern "C" int __cdecl GEX_Target(void** param_1, int param_2)
{
    void* pSVar1;

    if (param_2 == 4) {
        DAT_00455B88 = 1;
    }
    if (param_2 != DAT_0045B098) {
        *(Blob32*)(param_1 + 4) = DAT_0049fba0[param_2];
    }
    pSVar1 = FUN_00433590(param_1, (void*)(param_1 + 4), (void*)param_1[4], 0);
    param_1[4] = pSVar1;
    DAT_0045B098 = param_2;
    if (param_1[4] == (void*)0) {
        *(Blob32*)(param_1 + 4) = DAT_0049fba0[param_2];
        return 1;
    }
    return 0;
}
