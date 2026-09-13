// Adapted from pc_decomp_backup/src/functions/FUN_00414330.cpp
// Historical source SHA256: 67002f0141348ce765eced975b3f7b79a39965829d5af44f237cfb11215b1f07
extern "C" {
extern "C" void __cdecl FUN_00426CA0(void**);
extern "C" void __cdecl GEX_Target(void** p)
{
    int count = (int)p[0x26] + 1;
    p[0x26] = (void*)count;
    if (count <= 0) return;
    if ((int)p[0x15] == 3) {
        FUN_00426CA0(p);
        return;
    }
    p[0x26] = 0;
    p[0x15] = (void*)((int)p[0x15] + 1);
}
}
