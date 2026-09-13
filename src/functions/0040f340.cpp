// Adapted from pc_decomp_backup/src/functions/FUN_0040F340.cpp
// Historical source SHA256: 265edf837d7b0cb4a8cb5bf7573ad1aa5ddff9dbc3c8485d584b3dcf20cd6c1e
extern "C" {
extern "C" int __cdecl FUN_0040F7A0(int, int, unsigned int*);
extern "C" unsigned int __cdecl GEX_Target(int param1) {
    unsigned int CurrentInputPTR;
    int SuccessBool = FUN_0040F7A0(param1 + 1, 0, &CurrentInputPTR);
    if (SuccessBool >= 0) {
        unsigned int v = CurrentInputPTR;
        unsigned int shifted = v >> 0x1c;
        unsigned int masked = v & 0xffc000f;
        return shifted | masked;
    }
    return 0;
}
}
