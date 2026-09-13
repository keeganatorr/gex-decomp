// Adapted from pc_decomp_backup/src/functions/FUN_0040F4C0.cpp
// Historical source SHA256: 1dfa1dc3d59e0fdd1337cbb2994057f44f2e10ed05de880b03cb8201871312bb
extern "C" {
extern "C" unsigned int __cdecl FUN_0040F400(int);
extern "C" unsigned int __cdecl FUN_0040F500(int*);
extern "C" { extern int* DAT_004a27dc; }
extern "C" unsigned int __cdecl GEX_Target(int param1) {
    int* pRecords = DAT_004a27dc;
    int* pEntry = (int*)((char*)pRecords + param1 * 0x24);
    unsigned int KeyInput;
    if (pEntry[3] == 0)
        KeyInput = FUN_0040F400(param1);
    else
        KeyInput = FUN_0040F500(pEntry + 3);
    pEntry[1] = KeyInput;
    return KeyInput;
}
}
