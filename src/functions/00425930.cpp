// Adapted from pc_decomp_backup/src/functions/FUN_00425930.cpp
// Historical source SHA256: 37e5726b4f33c5f25527d979fa529dcd81acd8088ea64a25791a9dbd335a40fa
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004256E0(void**);

extern "C" void __cdecl InitPlayerJumpTongueLashUp_00425930(void** p)
{
    FUN_00420BC0(p);
    p[0x26] = 0;
    p[0x28] = 0;
    p[0x1c] = (void*)0x14;
    p[0x14] = (void*)0x37;
    p[0x15] = (void*)2;
    FUN_00420960(p);
    FUN_004256E0(p);
}
}
