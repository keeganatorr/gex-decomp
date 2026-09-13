// Adapted from pc_decomp_backup/src/functions/FUN_004125B0.cpp
// Historical source SHA256: cc44125edfb0a1396cda83ad7f664c5a5785327b82179f34fab5e0d80579ee4d
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004124C0(void**);
extern "C" { extern int DAT_004586a8; }
extern "C" { extern int DAT_004586c0; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar1;
    
    FUN_00420BC0(param_1);
    param_1[0x15] = (void*)0;
    param_1[0x26] = (void*)0;
    param_1[0x1c] = (void*)0x46;  
    param_1[0x14] = (void*)0x4d;
    if ((((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15) == 8) {
        param_1[0x1b] = (void*)((unsigned int)param_1[0x1b] | 0x80000000);
    }
    iVar1 = DAT_004586a8;
    if (((unsigned int)param_1[0x1b] & 0x80000000) == 0) {
        iVar1 = -DAT_004586a8;
    }
    param_1[0x1e] = (void*)((int)param_1[0x1e] + iVar1);
    param_1[0x1f] = (void*)((int)param_1[0x1f] + DAT_004586c0);
    FUN_004124C0(param_1);
}
}
