// Adapted from pc_decomp_backup/src/functions/FUN_00429AC0.cpp
// Historical source SHA256: 456371b62e6c85c7b0f4dfdb7aa45a579acaf730fcaa083c74196e9d6157c21b
extern "C" {
extern "C" void __cdecl FUN_0041A360(int, int);
extern "C" void __cdecl FUN_004372F0(void**);
extern "C" { extern int FUN_0045ACC0; }
extern "C" { extern unsigned char DAT_004A2540[]; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int flags = (unsigned int)param_1[0x29];
    
    if ((flags & 0x200) != 0 && (flags & 0x400) != 0) {
        int idx = (int)param_1[0x27];
        if ((DAT_004A2540[idx] & 1) != 0) {
            if ((flags & 0x40000000) == 0) {
                FUN_0041A360(0x65, 0xff);
                param_1[0x15] = (void*)0x0;
                FUN_004372F0(param_1);
            }
            else if ((flags & 0x20000000) != 0) {
                FUN_0045ACC0 = 1;
            }
            param_1[0x29] = (void*)(flags & 0xfffffbff);
        }
    }
}
}
