// Adapted from pc_decomp_backup/src/functions/FUN_0042D680.cpp
// Historical source SHA256: fd5b0febd5bccdd5dd0a82d0383f7a1f72e45a7963e931c564982e515650b6c8
extern "C" {
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);

extern "C" int __cdecl GEX_Target(void** param_1)
{
    param_1[0x3c] = (void*)(((unsigned int)param_1[0x62] & 0xffe00000) + 0x200000);
    param_1[0x1f] = (void*)((int)param_1[0x1f] + (0x200000 - ((unsigned int)param_1[0x62] & 0x1fffff)));
    if (param_1[0x3b] != 0) {
        FUN_0042cc70_Object_unk(0, param_1);
    }
    return 1;
}
}
