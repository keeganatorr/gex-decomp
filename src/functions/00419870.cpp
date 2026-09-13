// Adapted from pc_decomp_backup/src/functions/FUN_00419870.cpp
// Historical source SHA256: 37c43fcb78ca9c5e1d1a8dda903c8bbc5683714101a5000daa63dcb19a5734d3
extern "C" {
extern int FUN_004A27B0;
extern int FUN_004A27A4;
extern int FUN_004A28A0;
extern int FUN_0045CA38;
extern int FUN_004A2934;
extern int FUN_004A2A78;

extern "C" void *__cdecl FUN_0042CC20(int *);
extern "C" void __cdecl FUN_0042CC00(int *, int);
extern "C" void __cdecl FUN_00405350(char *, int, int);
extern "C" void __cdecl FUN_0041E7E0(int *, int *, int *, int *);
extern "C" void __cdecl FUN_0040F2E0(int *, int);
extern "C" int __cdecl FUN_0041E190(void**, void*);

extern "C" void __cdecl GEX_Target(int *objectType, int *param_2)
{
    int *loaded_gOb;
    int *ppGVar7;
    int iVar3;
    unsigned int priority;
    unsigned int uVar6;
    int pGVar2;
    int pGVar5;
    int *puVar4;
    int *objectType_00;
    int *puVar1;
    int obs_entry;

    loaded_gOb = (int *)FUN_0042CC20((int *)&FUN_004A27B0);
    if (loaded_gOb != 0) {
        ppGVar7 = loaded_gOb;
        for (iVar3 = 0x81; iVar3 != 0; iVar3 = iVar3 + -1) {
            *ppGVar7 = 0;
            ppGVar7 = ppGVar7 + 1;
        }
        priority = ((objectType[2] & 0xf000000) >> 0x18) + 1;
        if (8 < priority) {
            FUN_00405350((char *)0x458ee0, objectType[1] & 0x3fff, (int)priority);
            FUN_0042CC00((int *)&FUN_004A27B0, (int)loaded_gOb);
            FUN_004A27A4 = FUN_004A27A4 - 1;
            return;
        }
        FUN_0042CC00((int *)(&FUN_004A28A0 + priority * 3), (int)loaded_gOb);
        pGVar2 = objectType[1] & 0x3fff;
        loaded_gOb[2] = pGVar2;
        uVar6 = objectType[2] & 0xffff;
        if (uVar6 != 0) {
            loaded_gOb[3] = *(int *)(FUN_004A2934 + uVar6 * 8 - 8);
        }
        loaded_gOb[0x1e] = objectType[0] & 0xffff0000;
        loaded_gOb[0x1f] = objectType[0] << 0x10;
        loaded_gOb[0x35] = loaded_gOb[0x1e];
        loaded_gOb[0x36] = loaded_gOb[0x1f];
        loaded_gOb[0x37] = 0x7fffffff;

        obs_entry = (int)(&FUN_0045CA38) + pGVar2 * 24;
        pGVar5 = (*(int *)(obs_entry + 0x14) & 0xfffffff0) | priority;
        loaded_gOb[0x1b] = pGVar5;
        loaded_gOb[0x1b] = (objectType[2] & 0xc0000000) | pGVar5;
        loaded_gOb[0x32] = 0x10000;
        loaded_gOb[0x33] = 0x10000;
        loaded_gOb[0x34] = param_2[0x0e];
        loaded_gOb[0x16] = *(int *)obs_entry;
        loaded_gOb[0x19] = *(int *)(obs_entry + 0xc);
        loaded_gOb[0x17] = *(int *)(obs_entry + 0x4);
        loaded_gOb[0x18] = *(int *)(obs_entry + 0x8);
        loaded_gOb[99] = (int)objectType;
        loaded_gOb[100] = (int)param_2;
        objectType[1] = objectType[1] | 0x8000;
        FUN_0041E7E0(
            loaded_gOb,
            (int *)((*(int *)(obs_entry + 0x14) & 0xf0) >> 4),
            (int *)((*(int *)(obs_entry + 0x14) & 0xf00) >> 8),
            (int *)&FUN_0041E190);
        if (uVar6 != 0) {
            puVar4 = (int *)*(int *)(FUN_004A2934 + uVar6 * 8 - 4);
            priority = *puVar4;
            while (priority != 0) {
                puVar1 = puVar4 + 1;
                priority = *puVar4;
                puVar4 = puVar4 + 2;
                loaded_gOb[(priority & 0xffff) + 0x1a] = *puVar1;
                priority = *puVar4;
            }
        }
        puVar4 = (int *)objectType[3];
        priority = *puVar4;
        while (priority != 0) {
            pGVar2 = puVar4[1];
            if ((priority & 0x10000000) == 0) {
                loaded_gOb[(priority & 0xffff) + 0x1a] = pGVar2;
            }
            else {
                objectType_00 = (int *)((int *)FUN_004A2A78)[(unsigned int)pGVar2 >> 0x10] + ((unsigned int)pGVar2 & 0xffff) * 0x10;
                if ((objectType_00[1] & 0x8000) == 0) {
                    GEX_Target(objectType_00, (int *)((int *)FUN_004A2A78)[(unsigned int)pGVar2 >> 0x10]);
                }
            }
            puVar1 = puVar4 + 2;
            puVar4 = puVar4 + 2;
            priority = *puVar1;
        }
        FUN_0040F2E0(loaded_gOb, 0);
        FUN_004A27A4 = FUN_004A27A4 + 1;
    }
}
}
