extern "C" void* __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" void __cdecl FUN_0040D740(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);

extern "C" int DAT_004a2964;
extern "C" int DAT_00455c04;
extern "C" void* DAT_004a2400[];

extern "C" void __cdecl HelpBoxNew_0040d5f0(int param_1, int param_2, int inputString, int param_4)
{
    void** gOb = (void**)FUN_004195D0(0x160, param_1, param_2, 0);

    if (gOb != 0) {
        unsigned int* ppGVar1;
        void* pGVar2;

        gOb[0x26] = (void*)inputString;
        ppGVar1 = (unsigned int*)(gOb + 0x20);
        gOb[0x27] = (void*)0x6000a;
        gOb[0x28] = (void*)0x70000;

        if (DAT_004a2964 == 0x3f) {
            *(volatile unsigned int*)ppGVar1 = 0xa;
        } else {
            *(volatile unsigned int*)ppGVar1 = 0xe;
        }

        pGVar2 = DAT_004a2400[param_4];
        gOb[0x21] = pGVar2;
        if (DAT_00455c04 == 4 && pGVar2 == 0) {
            FUN_00419520(gOb);
            return;
        }
        FUN_0040D740(gOb);
        gOb[0x28] = (void*)(((unsigned int)gOb[0x28] & 0xfffffff1) | 1);
        gOb[0x29] = 0;
        gOb[0x2a] = 0;
        *ppGVar1 |= 8;
        FUN_0041E7C0(gOb);
        gOb[0x19] = 0;
    }
}
