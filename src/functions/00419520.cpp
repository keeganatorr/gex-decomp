extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" int decl_pad_2;
extern "C" int decl_pad_3;
extern "C" int decl_pad_4;
extern "C" int decl_pad_5;
extern void* PTR_004a2838;
extern void* PTR_004a2814;
extern void* PTR_004a2874;
extern void* PTR_004a27f0;
extern void* FUN_004A2864;
extern void* FUN_004A2888;
void __cdecl FUN_0040F2E0(void*, int);
void __cdecl FUN_0041E7C0(void*);
void __cdecl GEX_Target(void*);
}

extern "C" void __cdecl GEX_Target(void* gOb)
{
    do {
        if ((*(int*)((char*)gOb + 0x6c) & 0x800000) != 0) {
            FUN_0040F2E0(gOb, 1);
        }
        FUN_0041E7C0(gOb);
        if (gOb == FUN_004A2888) FUN_004A2888 = 0;
        if (gOb == FUN_004A2864) FUN_004A2864 = 0;
        if (gOb == PTR_004a27f0) PTR_004a27f0 = 0;
        if (gOb == PTR_004a2874) PTR_004a2874 = 0;
        if (gOb == PTR_004a2814) PTR_004a2814 = 0;
        if (gOb == PTR_004a2838) PTR_004a2838 = 0;
        *(int*)((char*)gOb + 0x6c) |= 0x100000;
        if (*(void**)((char*)gOb + 0x160) != 0) {
            GEX_Target(*(void**)((char*)gOb + 0x160));
        }
        gOb = *(void**)((char*)gOb + 0x164);
    } while (gOb != 0);
}