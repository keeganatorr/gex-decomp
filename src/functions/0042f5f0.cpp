extern "C" {
extern void *GEX_pGlob_004a2ad4;
int *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
int __cdecl UTL_ReallyRandom_00428c80(int);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(int *, int *);

void __cdecl FUN_0042f5f0(int *parent, int mode)
{
    int *object = GOB_AddObject_004195d0(0x5c, parent[0x1e], parent[0x1f], GEX_pGlob_004a2ad4);
    if (object != 0) {
        if (mode == 0) {
            object[0x1b] |= 0xc000;
            object[0x21] = 0x7fff0000;
            object[0x20] = UTL_ReallyRandom_00428c80(2)
                ? UTL_ReallyRandom_00428c80(0x30000)
                : -UTL_ReallyRandom_00428c80(0x30000);
            object[0x24] = 0x7fff0000;
            object[0x23] = UTL_ReallyRandom_00428c80(2)
                ? UTL_ReallyRandom_00428c80(0x30000)
                : -UTL_ReallyRandom_00428c80(0x30000);
            object[0x26] = 3;
        } else {
            object[0x26] = 8;
        }
        object[0x14] = 0x20;
        object[0x1c] = 0x30;
        if ((parent[0x38] & 0x40) != 0)
            object[0x38] |= 0x40;
        GOB_PutObjectInfrontOfObject_00419be0(object, parent);
    }
}
}
