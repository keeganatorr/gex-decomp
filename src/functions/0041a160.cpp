// Adapted from pc_decomp_backup/src/functions/FUN_0041A160.cpp
// Historical source SHA256: 1e9138248b50b378aae661fe84af57a2fcb75898dab7343528b247df1fbeca08
extern "C" {
extern "C" int __cdecl FUN_0040F1D0(void*, void**);
extern "C" void __cdecl FUN_00405390(const char*, int);
extern "C" { extern int DAT_00455c54; }
extern "C" { extern void** DAT_004a27fc; }
extern "C" { extern const char DAT_00458f68[]; }
extern "C" int __cdecl GEX_Target(void* param1, void** param2) {
    int bVar1;
    if (param2[0x44] == 0 || (bVar1 = 1, param2[0x45] != 0)) bVar1 = 0;
    int glueDist = FUN_0040F1D0(param1, param2);
    if (DAT_00455c54 > 2 && param2 == DAT_004a27fc) {
        FUN_00405390(DAT_00458f68, glueDist >> 0x10);
    }
    int absGlue = ((unsigned int)glueDist ^ (glueDist >> 0x1f)) - (glueDist >> 0x1f);
    if (absGlue < 0x100000 && (!bVar1 || ((int)param2[0x37] > 0 && glueDist < 1))) {
        param2[0x37] = 0;
        param2[0x44] = 0;
        param2[0x45] = (void*)-1;
        param2[0x1f] = (void*)((int)param2[0x1f] + (int)glueDist);
        param2[0x3b] = param2[0x1f];
        return 1;
    }
    if (bVar1) {
        param2[0x3b] = param2[0x1f];
        param2[0x1f] = param2[0x36];
        param2[0x37] = 0;
        return 1;
    }
    param2[0x37] = (void*)glueDist;
    return 0;
}
}
