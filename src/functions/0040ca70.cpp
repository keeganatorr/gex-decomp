// Adapted from pc_decomp_backup/src/functions/FUN_0040CA70.cpp
// Historical source SHA256: 0747b2fb5e60667fc6ac1a0921b3c87707c9803407d85acf3c3183eaea1e9b09
extern "C" {
extern "C" void** __cdecl FUN_0040C110(int, int);
extern "C" { extern int DAT_00456034; }
extern "C" void __cdecl FUN_0040ca70(void** param1, int* param2) {
    void** ppGVar1 = FUN_0040C110(0x7b, (int)param1[0x2a]);
    ppGVar1[0x15] = (void*)-1;
    if ((int)ppGVar1[0x2a] > 0) {
        ppGVar1 = FUN_0040C110(0x7b, (int)ppGVar1[0x2a]);
        ppGVar1[0x15] = (void*)-1;
        if (param1[0x2a] == (void*)0xc) {
            ppGVar1 = FUN_0040C110(0x7b, 0x19);
            ppGVar1[0x15] = (void*)-1;
        }
    }
    ppGVar1 = FUN_0040C110(0x7b, (int)param2);
    param1[0x28] = ppGVar1[0x28];
    param1[0x29] = ppGVar1[0x29];
    void* frame = ppGVar1[0x2a];
    param1[0x2b] = ppGVar1[0x2b];
    void* pGVar2 = ppGVar1[0x1f];
    ppGVar1[0x15] = 0;
    if ((int)frame > 0) {
        ppGVar1 = FUN_0040C110(0x7b, (int)frame);
        ppGVar1[0x15] = 0;
        if (param2 == (int*)0xc) {
            ppGVar1 = FUN_0040C110(0x7b, 0x19);
            ppGVar1[0x15] = 0;
        }
    }
    param1[0x2a] = (void*)param2;
    ppGVar1 = FUN_0040C110(0x7b, 0x16);
    if (param2 == (int*)0xc)
        pGVar2 = (void*)((int)pGVar2 - 0x60000);
    ppGVar1[0x1f] = pGVar2;
    DAT_00456034 = 0;
}
}
