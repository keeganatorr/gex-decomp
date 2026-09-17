extern "C" {
unsigned int __cdecl FUN_0040F400(int);
unsigned int __cdecl FUN_0040F500(int*);
}

struct InputRecord {
    int          field0;    // +0x00
    unsigned int keyInput;  // +0x04
    int          field8;    // +0x08
    int          recorded;  // +0x0c
    int          pad[5];    // +0x10 .. +0x20
};

extern "C" InputRecord* gInputRecords_004a27dc;

extern "C" unsigned int __cdecl GEX_Target(int param_1)
{
    unsigned int KeyInput;
    if (gInputRecords_004a27dc[param_1].recorded != 0)
        KeyInput = FUN_0040F500(&gInputRecords_004a27dc[param_1].recorded);
    else
        KeyInput = FUN_0040F400(param_1);
    gInputRecords_004a27dc[param_1].keyInput = KeyInput;
    return KeyInput;
}
