// Adapted from pc_decomp_backup/src/functions/FUN_00437310.cpp
// Historical source SHA256: 356d5b88c76eebaa3a914c0559312274cee54863c4a01f4cbf50bb3b0698bc80
extern "C" {
extern "C" void __cdecl FUN_00437170();

extern "C" void __cdecl RezOutObject_00437310(void** param_1)
{
    param_1[0x18] = (void*)&FUN_00437170;
    param_1[0x2e] = 0;
}
}
