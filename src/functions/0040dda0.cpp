// Adapted from pc_decomp_backup/src/functions/FUN_0040DDA0.cpp
// Historical source SHA256: 41914b3fc7547f1a0934a2c7e9be2e590887c617b707e10c6a58b6fc2cda42ae
extern "C" {
extern "C" { extern int FUN_004A2A7C; }
extern "C" { extern int DAT_00462c84; }
extern "C" { extern int DAT_0045acc4_ProcessedTitleScreenCheat; }
extern "C" { extern int DAT_00456334; }
extern "C" { extern int DAT_0045633c; }
extern "C" { extern char* FUN_004A0200; }
extern "C" { extern int DAT_004a0204; }
extern "C" { extern int DAT_004a0208; }
extern "C" { extern void* FUN_004A2AC8; }
extern "C" { extern int DAT_00462c78; }
extern "C" { extern void* FUN_00487FE0; }
extern "C" { extern void* FUN_00487FD0; }
extern "C" { extern void* FUN_00487FEC; }
extern "C" void __cdecl FUN_00417EE0();
extern "C" void __cdecl FUN_0041F8C0(int);
extern "C" void __cdecl FUN_0040b950_VoiceInner();
extern "C" void** __cdecl FUN_0040C110(int, int);

extern "C" void __cdecl GEX_Target(void** gexPlayerStruct) {
    void** start;
    void** password;
    void** exit;

    FUN_004A2A7C = 1;
    DAT_00462c84 = 0;
    DAT_0045acc4_ProcessedTitleScreenCheat = 0;
    DAT_00456334 = 0;
    DAT_0045633c = 0;
    FUN_004A0200 = (char*)0x41414141;
    DAT_004a0204 = 0x41414141;
    DAT_004a0208 = 0;
    FUN_00417EE0();
    gexPlayerStruct[0x1e] = (void*)0xfff60000;
    gexPlayerStruct[0x1f] = (void*)0x1e00000;
    gexPlayerStruct[0x2d] = FUN_004A2AC8;
    DAT_00462c78 = 0xa0000;
    gexPlayerStruct[0x2c] = (void*)0x0;
    FUN_0041F8C0(1);
    FUN_0040b950_VoiceInner();
    start = FUN_0040C110(0x7b, 1);
    start[0x2d] = (void*)((unsigned int)start[0x2d] | 1);
    start[0x27] = FUN_00487FE0;
    password = FUN_0040C110(0x7b, 2);
    password[0x2d] = (void*)((unsigned int)password[0x2d] | 1);
    password[0x27] = FUN_00487FD0;
    exit = FUN_0040C110(0x7b, 3);
    exit[0x2d] = (void*)((unsigned int)exit[0x2d] | 1);
    exit[0x27] = FUN_00487FEC;
    password[0x26] = (void*)0x3;
    exit[0x26] = (void*)0x2;
    start[0x28] = (void*)0x2;
    start[0x29] = (void*)0x3;
    password[0x28] = (void*)0x1;
    password[0x29] = (void*)0x2;
    exit[0x28] = (void*)0x3;
    exit[0x29] = (void*)0x1;
}
}
