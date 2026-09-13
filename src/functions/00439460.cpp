// Adapted from pc_decomp_backup/src/functions/FUN_00439460.cpp
// Historical source SHA256: 386d9072c28c7fdd1db4371e8c17252311d61d791c4740590d712e6141d24e1d
extern "C" {
extern "C" void __cdecl FUN_00419840(void**);
extern "C" { extern int DAT_00464520; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int val = DAT_00464520;
    int sign = val >> 0x1f;
    
    if ((((val ^ sign) - sign) & 1) == 0) {
        param_1[0x15] = (void*)((char*)param_1[0x15] + 1);
    }
    if (param_1[0x15] == (void*)5) {
        FUN_00419840(param_1);
    }
    param_1[0x1e] = (void*)((int)param_1[0x20] + ((int)param_1[0x1e] - 0x144) - 0xc);
    param_1[0x1f] = (void*)((int)param_1[0x23] + ((int)param_1[0x1f] - 0x144) - 0xc);
}
}
