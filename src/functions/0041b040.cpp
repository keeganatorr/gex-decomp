// Adapted from pc_decomp_backup/src/functions/FUN_0041B040.cpp
// Historical source SHA256: afe4a1d4094f66fac965e90cc99c7e8da215bd07c6e4861672ff63fb29a52673
extern "C" {
extern "C" { extern int DAT_004A2660[]; }
extern "C" void __cdecl FUN_00419520(void**);

extern "C" void __cdecl VCRInit_0041b040(void** param_1)
{
    int *p = DAT_004A2660;
    do {
        if (*p == 3) {
            FUN_00419520(param_1);
            return;
        }
        p++;
    } while (p < (int*)0x004A2678);
}
}
