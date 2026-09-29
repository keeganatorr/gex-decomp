// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
void __cdecl decl_fn_0(void);
void __cdecl decl_fn_1(void);
void __cdecl decl_fn_2(void);
void __cdecl decl_fn_3(void);
void __cdecl decl_fn_4(void);
void __cdecl decl_fn_5(void);
void __cdecl decl_fn_6(void);
void __cdecl decl_fn_7(void);
void __cdecl decl_fn_8(void);
extern "C" {
extern unsigned int UINT_ARRAY_00457c88[];
void __cdecl FUN_0040f700_InputInner(unsigned int buttons, unsigned char *map, unsigned char *out)
{
    int i;
    for (i = 0; UINT_ARRAY_00457c88[i] != 0xffffffff; i++)
        out[map[i]] = (UINT_ARRAY_00457c88[i] & buttons) != 0;
}
}
