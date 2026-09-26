extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
void** __cdecl FUN_0042CC20(void**);
void __cdecl FUN_0042CC00(void**, void**);
void __cdecl FUN_0041E7E0(void**, int*, int*, int*);
void __cdecl FUN_0040F2E0(void**, int);
int __cdecl FUN_0041E190(void**, void*);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_004A27B0;
extern unsigned int obs_0045ca38[][6];
extern int DAT_004A28A0;
extern int DAT_004A27A4;

void** __cdecl GEX_Target(int gObType, long xpos, long ypos, int gOb) {
    void** GexObject = FUN_0042CC20((void**)&DAT_004A27B0);
    if (GexObject != 0) {
        unsigned int* data = obs_0045ca38[gObType];
        unsigned int uVar2 = (data[5] & 0xf) + 1;
        memset(GexObject, 0, 0x204);
        FUN_0042CC00((void**)((char*)&DAT_004A28A0 + uVar2 * 12), GexObject);
        GexObject[3] = (void*)gOb;
        ((long*)GexObject)[0x1e] = xpos;
        ((long*)GexObject)[0x1f] = ypos;
        ((long*)GexObject)[0x35] = xpos;
        ((long*)GexObject)[0x36] = ypos;
        GexObject[0x37] = (void*)0x7fffffff;
        GexObject[0x1b] = (void*)((data[5] & 0xfffffff0) | uVar2);
        GexObject[2] = (void*)gObType;
        GexObject[0x32] = (void*)0x10000;
        GexObject[0x33] = (void*)0x10000;
        GexObject[0x34] = (void*)0xc00000;
        GexObject[0x16] = (void*)data[0];
        GexObject[0x19] = (void*)data[3];
        GexObject[0x17] = (void*)data[1];
        GexObject[0x18] = (void*)data[2];
        FUN_0041E7E0(GexObject,
            (int*)((data[5] & 0xf0) >> 4),
            (int*)((data[5] & 0xf00) >> 8),
            (int*)&FUN_0041E190);
        FUN_0040F2E0(GexObject, 0);
        DAT_004A27A4++;
    }
    return GexObject;
}
}
