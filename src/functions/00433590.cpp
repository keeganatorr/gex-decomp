extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int DAT_00464278;
extern void** DAT_004642A0;
void __cdecl FUN_00405390(const char*, ...);
void* __cdecl FUN_00435D90(void**, void*, void*);
extern const char* DAT_0045B57C[];
extern const char DAT_0045B5F0[];

void* __cdecl SCRIPT_DoEvent_00433590(void** param_1, void* param_2, void* PointerToScript, int eventNumber)
{
    if (DAT_00464278 != 0 && param_1[2] == (void*)DAT_004642A0) {
        FUN_00405390(DAT_0045B5F0, DAT_0045B57C[eventNumber], PointerToScript);
    }
    return FUN_00435D90((PointerToScript, param_1), param_2, PointerToScript);
}
}
