// Adapted from pc_decomp_backup/src/functions/FUN_0041B700.cpp
// Historical source SHA256: be3649ba61c0f024700512c7bd23da57956a146ed02ef706d870784e036de299
extern "C" {
extern "C" { extern int DAT_004635a0; }
extern "C" void __cdecl FUN_0041B500(void**);

extern "C" void __cdecl FUN_0041b700_ObjCallUnkInner(void** param_1)
{
    if (DAT_004635a0 == 0) {
        DAT_004635a0 = 1;
        int val = (int)param_1[0x1b];
        while ((val & 0x100000) == 0) {
            FUN_0041B500(param_1);
            val = (int)param_1[0x1b];
        }
        DAT_004635a0 = 0;
    }
}
}
