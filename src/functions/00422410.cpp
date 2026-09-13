// Adapted from pc_decomp_backup/src/functions/FUN_00422410.cpp
// Historical source SHA256: 9dbc1537b2d8f99e8b30456409e3538a7d63c040efbe2b0d1a6200122e316a05
extern "C" {
extern "C" { extern int DAT_00458C88; }
extern "C" { extern int DAT_004A0218; }
extern "C" { extern int DAT_004A0224; }
extern "C" { extern int DAT_004A0254; }
extern void* DAT_004A2888;
extern "C" void __cdecl FUN_00419A80(void**);

extern "C" void __cdecl GEX_Target()
{
    void* gEatingObject;
    int* pType;

    gEatingObject = DAT_004A2888;
    if (gEatingObject == (void*)0x0) return;
    DAT_004A0218 = 0x6d;
    pType = (int*)((int)gEatingObject + 8);
    if ((*pType >= 0x39 && *pType <= 0x42) || *pType == 0x130 || *pType == 0xea) {
        DAT_004A0254 = 1;
        DAT_004A0224 = *pType - 0x39;
        FUN_00419A80((void**)DAT_004A2888);
    } else {
        DAT_00458C88 = 1;
    }
}
}
