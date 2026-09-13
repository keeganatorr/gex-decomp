// Adapted from pc_decomp_backup/src/functions/FUN_004195D0.cpp
// Historical source SHA256: 924d0a70b02259b4a41b8f62adcd64a7db8032ed9d874cf1ba0968be874cdc22
extern "C" {
extern "C" void** __cdecl FUN_0042CC20(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);
extern "C" void __cdecl FUN_0041E7E0(void**, int*, int*, int*);
extern "C" void __cdecl FUN_0040F2E0(void**, int);
extern "C" int __cdecl FUN_0041E190(void**, void*);
extern "C" { extern int DAT_004A27B0; }
extern "C" { extern int DAT_0045CA4C; }
extern "C" { extern int DAT_004A28A0; }
extern "C" { extern int DAT_004A27A4; }
extern "C" void** __cdecl GEX_Target(int gObType, int xpos, int ypos, int gOb) {
    void** GexObject = FUN_0042CC20((void**)&DAT_004A27B0);
    if (GexObject != 0) {
        unsigned int uVar2 = (*(unsigned int*)((int)&DAT_0045CA4C + gObType * 0x18) & 0xf) + 1;
        void** ppGVar3 = GexObject;
        for (int i = 0x81; i != 0; i--) *ppGVar3++ = 0;
        FUN_0042CC00((void**)((int)&DAT_004A28A0 + uVar2 * 12), GexObject);
        GexObject[3] = (void*)gOb;
        GexObject[0x1e] = (void*)xpos;
        GexObject[0x1f] = (void*)ypos;
        GexObject[0x35] = (void*)xpos;
        GexObject[0x36] = (void*)ypos;
        GexObject[0x37] = (void*)0x7fffffff;
        GexObject[0x1b] = (void*)((*(unsigned int*)((int)&DAT_0045CA4C + gObType * 0x18) & 0xfffffff0) | uVar2);
        GexObject[2] = (void*)gObType;
        GexObject[0x32] = (void*)0x10000;
        GexObject[0x33] = (void*)0x10000;
        GexObject[0x34] = (void*)0xc00000;
        GexObject[0x16] = (void*)*(int*)((int)&DAT_0045CA4C - 0x14 + gObType * 24);
        GexObject[0x19] = (void*)*(int*)((int)&DAT_0045CA4C - 0x10 + gObType * 24);
        GexObject[0x17] = (void*)*(int*)((int)&DAT_0045CA4C - 0xc + gObType * 24);
        GexObject[0x18] = (void*)*(int*)((int)&DAT_0045CA4C - 8 + gObType * 24);
        FUN_0041E7E0(GexObject,
            (int*)((*(unsigned int*)((int)&DAT_0045CA4C + gObType * 0x18) & 0xf0) >> 4),
            (int*)((*(unsigned int*)((int)&DAT_0045CA4C + gObType * 0x18) & 0xf00) >> 8),
            (int*)&FUN_0041E190);
        FUN_0040F2E0(GexObject, 0);
        DAT_004A27A4++;
    }
    return GexObject;
}
}
