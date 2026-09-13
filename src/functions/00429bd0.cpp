// Adapted from pc_decomp_backup/src/functions/FUN_00429BD0.cpp
// Historical source SHA256: c440188f450cd17ae40ecd82dd3ac82ce4d33aeb3b14b926595a9031a8e892f8
extern "C" {
extern "C" { extern void* DAT_004a28a0; }
extern "C" { extern void* DAT_004a2918; }
extern "C" void* __cdecl GEX_Target() {
    void** ppList = (void**)&DAT_004a28a0;
    void** end = (void**)&DAT_004a2918;
    do {
        void* pObj = *ppList;
        if (*(void**)pObj != 0) {
            int tv_type = 0xdc;
            int work3_mask = 0x80000000;
            do {
                int type = *(int*)((int)pObj + 0x08);
                int work3 = *(int*)((int)pObj + 0xa4);
                if (type == tv_type && (work3 & work3_mask) != 0) return (void**)pObj;
                pObj = *(void**)pObj;
            } while (*(void**)pObj != 0);
        }
        ppList = (void**)((int)ppList + 12);
    } while (ppList < end);
    return 0;
}
}
