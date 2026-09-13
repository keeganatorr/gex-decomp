// Adapted from pc_decomp_backup/src/functions/FUN_0040E3F0.cpp
// Historical source SHA256: c286a825063935f859327a57255c77245e39b54df2bc9f28272a9e254186d4b5
extern "C" {
extern "C" { extern int DAT_00456334; }
extern "C" int** __cdecl FUN_0040C110(int, int);
extern "C" int __cdecl FUN_0040C1A0(int, unsigned int);
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** object)
{
    int oldColour = (int)object[0x2f];
    int oldX = (int)object[0x1e];
    int oldY = (int)object[0x1f];
    int oldPrevX = (int)object[0x7e];
    int oldPrevY = (int)object[0x7f];
    int oldChar = (int)object[0x15];
    int y = (int)object[0x27];

    object[0x1f] = (void*)y;
    object[0x7f] = (void*)y;
    object[0x1e] = (void*)0x7d0000;
    object[0x7e] = (void*)0x7d0000;
    object[0x15] = (void*)4;

    if (y < 0x550001) {
        int** start = FUN_0040C110(0x7b, 1);
        if (DAT_00456334 == 0) {
            DAT_00456334 = 1;
            start[0x2d] = (int*)((unsigned int)start[0x2d] & ~1u);
            start[0x15] = 0;
            FUN_0040C1A0(1, 8);
            object[0x2c] = (void*)1;
            int** password = FUN_0040C110(0x7b, 2);
            password[0x2d] = (int*)((unsigned int)password[0x2d] & ~1u);
            password[0x15] = (int*)-1;
            int** exit = FUN_0040C110(0x7b, 3);
            exit[0x2d] = (int*)((unsigned int)exit[0x2d] & ~1u);
            exit[0x15] = (int*)-1;
        }
    } else {
        object[0x27] = (void*)(y - 0x80000);
        object[0x1f] = (void*)(y - 0x80000);
    }

    FUN_00444590((void**)object);
    object[0x1e] = (void*)oldX;
    object[0x1f] = (void*)oldY;
    object[0x7e] = (void*)oldPrevX;
    object[0x7f] = (void*)oldPrevY;
    object[0x15] = (void*)oldChar;
    object[0x2f] = (void*)oldColour;
}
}
