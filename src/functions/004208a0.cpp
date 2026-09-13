// Adapted from pc_decomp_backup/src/functions/FUN_004208A0.cpp
// Historical source SHA256: beda0861a03d5cd31da774d6b6118a525636fd67100dc012c6145e9edede7077
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1, void* param_2)
{
    *(unsigned int*)((char*)param_1 + 0x78) += 0x200000 - (*(unsigned int*)((char*)param_2 + 0x18) & 0x1fffff);
}
}
