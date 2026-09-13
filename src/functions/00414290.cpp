// Adapted from pc_decomp_backup/src/functions/FUN_00414290.cpp
// Historical source SHA256: 6f095d31791d086f1b3148cda592eb8ed814ea62cad562ca4440dd63619588de
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414240(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)0x4e; 
    param_1[0x14] = (void*)0x59;
    int dir = (((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c) | ((int)param_1[0x31] >> 0x15);
    if (dir == 0 || dir == 0xc) { param_1[0x1f] = (void*)((int)param_1[0x1f] - 0x1000); FUN_00414240(param_1); return; }
    if (dir == 4 || dir == 8) { param_1[0x1f] = (void*)((int)param_1[0x1f] - 0x1000); }
    FUN_00414240(param_1);
}
}
