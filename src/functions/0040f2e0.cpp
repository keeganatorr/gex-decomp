// Adapted from pc_decomp_backup/src/functions/FUN_0040F2E0.cpp
// Historical source SHA256: 40daf9bfd9ee0b6c26297d3074f2c21f1040dbdfacd51e13a60c3eafe56636f5
extern "C" {
extern "C" void __cdecl GOB_CallInit_0040f2e0(void* param_1, int param_2)
{
    void (*func)(void*, int);
    func = *(void(**)(void*, int))((char*)param_1 + 0x58);
    if (func != 0) {
        func(param_1, param_2);
    }
}
}
