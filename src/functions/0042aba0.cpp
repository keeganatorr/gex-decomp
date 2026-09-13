// Adapted from pc_decomp_backup/src/functions/FUN_0042ABA0.cpp
// Historical source SHA256: 5f972abfa5795de9b25ac67f0b6fca5e0cce3da74281c6f2533cb8c3ba26bd1a
extern "C" {
extern "C" void** __cdecl FUN_0040C110(int, int);
extern "C" void __cdecl FUN_004372F0(void**);
extern "C" { extern unsigned char DAT_004A2540; }
extern "C" void __cdecl GEX_Target(void** param1) {
    if (((unsigned int)param1[0x27] & 2) == 0) {
        if ((((unsigned int)param1[0x27] & 1) != 0) &&
            ((*(unsigned char*)((int)&DAT_004A2540 + ((unsigned int)param1[0x26] >> 0x10)) & 1) != 0)) {
            if (((unsigned int)param1[0x28] & 2) == 0) {
                param1[0x15] = 0;
                if (((unsigned int)param1[0x28] & 1) == 0) FUN_004372F0(param1);
            } else param1[0x15] = (void*)-1;
            param1[0x27] = (void*)((unsigned int)param1[0x27] & 0xfffffffe);
        }
        return;
    }
    void** ppGVar3 = FUN_0040C110(0xdc, (unsigned int)param1[0x26] & 0xffff);
    void* pGVar1 = ppGVar3[0x27];
    void* pGVar2 = ppGVar3[0x29];
    if (((((unsigned int)pGVar2 & 0x200) == 0) || (((unsigned int)pGVar2 & 0x400) == 0)) ||
        ((*(int*)((int)pGVar1 + 0x2512 + 0x12) & 3) == 3))
    {
        if ((((unsigned int)pGVar2 & 0x200) != 0) && (((unsigned int)pGVar2 & 0x400) == 0) &&
            (((unsigned int)param1[0x28] & 2) == 0))
            goto LAB_ac32;
    } else {
        param1[0x27] = (void*)((unsigned int)param1[0x27] | 1);
        if (((unsigned int)param1[0x28] & 2) != 0) { param1[0x15] = 0; goto LAB_ac32; }
    }
    param1[0x15] = (void*)-1;
LAB_ac32:
    param1[0x26] = (void*)(((unsigned int)param1[0x26] & 0xffff) | ((unsigned int)pGVar1 << 0x10));
    param1[0x27] = (void*)((unsigned int)param1[0x27] & 0xfffffffd);
}
}
