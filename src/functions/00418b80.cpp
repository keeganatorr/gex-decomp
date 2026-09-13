// Adapted from pc_decomp_backup/src/functions/FUN_00418B80.cpp
// Historical source SHA256: 52d67cea8de09e456186e96e8690bcf00b0fb9e84e2a947ae60a44ea974f9b99
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F40(unsigned char**);
extern "C" void __cdecl FUN_0041A360(unsigned int, int);

extern "C" unsigned char* __cdecl GEX_Target(unsigned char* p)
{
    unsigned int sound;
    unsigned int byte_val;
    unsigned char* result;
    
    sound = FUN_00417F40(&p);
    byte_val = p[0];
    result = p + 1;
    FUN_0041A360(sound, (int)(unsigned char)byte_val >> 1);
    return result;
}
}
