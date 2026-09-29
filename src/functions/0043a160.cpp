extern "C" void __cdecl FUN_00441150(void*);
extern "C" int DAT_00464610;
extern "C" int DAT_00464660;

extern "C" void __cdecl FUN_0043a160(void** param1) {
    int* piVar4 = &DAT_00464660;
    int* piVar3 = &DAT_00464610;
    do {
        int iVar1 = *piVar4;
        int iVar2 = (iVar1 >> 8) * 0xa0;
        param1[0x32] = (void*)(((int)((iVar1 / 0x60) & 0xffffff01) >> 1) + 0x10000);
        param1[0x1e] = (void*)(*(int*)(*piVar3 + 0x78) + iVar2);
        param1[0x1f] = (void*)(*(int*)(*piVar3 + 0x7c) + iVar2);
        param1[0x31] = (void*)*(int*)(*piVar3 + 0xc4);
        param1[0x14] = (void*)*(int*)(*piVar3 + 0x50);
        param1[0x15] = (void*)*(int*)(*piVar3 + 0x54);
        FUN_00441150(param1);
        piVar3++;
        piVar4 += 4;
    } while (piVar4 < &DAT_00464660 + 32);
}
