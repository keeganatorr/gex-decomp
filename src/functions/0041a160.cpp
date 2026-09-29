extern "C" {
int __cdecl FUN_0040F1D0(void*, void**);
void __cdecl FUN_00405390(const char*, int);
int __cdecl abs(int);
extern int DAT_00455c54;
extern void** DAT_004a27fc;
extern const char DAT_00458f68[];

int __cdecl GOB_LandedOnContoursWithOffset_0041a160(void* param1, void** param2) {
    int glueDist;
    int bVar1 = param2[0x44] != 0 && param2[0x45] == 0;
    glueDist = FUN_0040F1D0(param1, param2);
    if (DAT_00455c54 > 2 && param2 == DAT_004a27fc)
        FUN_00405390(DAT_00458f68, glueDist >> 16);
    if (abs(glueDist) < 0x100000 && (!bVar1 || ((int)param2[0x37] > 0 && glueDist <= 0))) {
        param2[0x37] = 0;
        param2[0x44] = 0;
        param2[0x45] = (void*)-1;
        unsigned int newY = (unsigned int)param2[0x1f] + (unsigned int)glueDist;
        param2[0x1f] = (void*)newY;
        param2[0x3b] = (void*)newY;
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
