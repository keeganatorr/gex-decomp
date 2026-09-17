extern "C" int __cdecl FUN_0040F7A0(int, int, unsigned int*);

extern "C" unsigned int __cdecl GEX_Target(int param1) {
    unsigned int CurrentInputPTR;
    int SuccessBool = FUN_0040F7A0(param1 + 1, 0, &CurrentInputPTR);
    if (SuccessBool >= 0) {
        return (CurrentInputPTR >> 0x1c | CurrentInputPTR) & 0xffc000f;
    }
    return 0;
}
