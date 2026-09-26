// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
// Adapted from pc_decomp_backup/src/functions/FUN_004404B0.cpp
// Historical source SHA256: 0d42736f65aef6d09ea772b17c84bb8830d8a3807c412c73c78e5d95df26d3fa
extern "C" {
extern "C" int __cdecl GEX_Target(int param_1, unsigned int param_2, unsigned int param_3)
{
    int iVar1;

    iVar1 = *(int*)(((int)(param_3 & 0xff3fffff) >> 0x16) * *(int*)(param_1 + 0xc) + ((int)(param_2 & 0xff3fffff) >> 0x16) + 0x2c + param_1);
    if (iVar1 != 0) {
        return ((param_2 & 0xe00000) >> 0x14) + ((param_3 & 0xe00000) >> 0x11) + 8 + iVar1;
    }
    return 0;
}
}
