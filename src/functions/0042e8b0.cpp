typedef struct Blob32 { int words[8]; } Blob32;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
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
    {
        int g = DAT_0045B098;
        if (g != param_2) {
            *(Blob32*)(param_1 + 4) = DAT_0049fba0[param_2];
        }
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
