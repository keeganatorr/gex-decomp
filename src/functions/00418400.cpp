extern "C" {
extern void __cdecl FUN_00405390(const char*);
extern int DAT_00455c54;
extern const char DAT_00458e3c[];
}

extern "C" int __cdecl GEX_Target(int param1, void** param2)
{
    void** pObj = param2;
    int iVar5 = 0;
    if (pObj[0x57] != 0) {
        int iVar6 = 0;
        void* pGVar3 = *(void**)((int)pObj[0x57] + 0x160);
        if (DAT_00455c54 > 1) {
            FUN_00405390(DAT_00458e3c);
        }
        if (pGVar3 == pObj) {
            *(void**)((int)pObj[0x57] + 0x160) = pObj[0x59];
        } else {
            void* pGVar4 = *(void**)((int)pGVar3 + 0x164);
            while (pGVar4 != pObj) {
                pGVar3 = *(void**)((int)pGVar3 + 0x164);
                pGVar4 = *(void**)((int)pGVar3 + 0x164);
            }
            *(void**)((int)pGVar3 + 0x164) = pObj[0x59];
        }
        pGVar3 = pObj[0x57];
        void* pGVar4 = *(void**)((int)pGVar3 + 0x15c);
        while (pGVar4 != 0) {
            iVar5 += *(int*)((int)pGVar3 + 0x78);
            iVar6 += *(int*)((int)pGVar3 + 0x7c);
            pGVar3 = *(void**)((int)pGVar3 + 0x15c);
            pGVar4 = *(void**)((int)pGVar3 + 0x15c);
        }
        *(int*)((int)pObj + 0x78) += *(int*)((int)pGVar3 + 0x78) + iVar5;
        int yAdd = *(int*)((int)pGVar3 + 0x7c);
        int newy = *(int*)((int)pObj + 0x7c);
        pObj[0x57] = 0;
        newy += yAdd + iVar6;
        *(int*)((int)pObj + 0x7c) = newy;
    }
    return param1;
}
