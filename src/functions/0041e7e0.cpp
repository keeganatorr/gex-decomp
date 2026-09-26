extern "C" {
extern "C" { extern int DAT_004595E8; }
extern "C" { extern int DAT_00459604; }
extern "C" { extern void* DAT_00463680; }
extern "C" { extern void* DAT_00463728; }
extern "C" { extern int DAT_004A23C0; }
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" void __cdecl FUN_00405350(int, int);
extern "C" void __cdecl FUN_00405390(int);
extern "C" void* __cdecl FUN_0042CC20(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);

extern "C" void __cdecl GEX_Target(void** objectType, int* func1, int* func2, int* func3)
{
    void* CollisionObjects;

    if (((unsigned int)objectType[0x1b] & 0x100000) != 0) {
        FUN_00405350((int)&DAT_00459604, (int)objectType[2]);
        return;
    }
    if (func2 != (int*)0x0) {
        CollisionObjects = FUN_0042CC20((void**)&DAT_00463728);
        if (CollisionObjects == (void*)0x0) {
            FUN_00405390((int)&DAT_004595E8);
            return;
        }
        DAT_004A23C0 = DAT_004A23C0 + 1;
        *(int*)((int)CollisionObjects + 0x08) = (int)objectType;
        objectType[0x5a] = (void*)func1;
        objectType[0x5b] = (void*)func3;
        objectType[0x60] = CollisionObjects;
        unsigned int mask = (unsigned int)objectType[0x1b] & 0xfffff0ff;
        objectType[0x1b] = (void*)(mask | ((unsigned int)((int)func2 << 8)));
        FUN_0042CC00((void**)&DAT_00463680, (void**)CollisionObjects);
    }
}
}
