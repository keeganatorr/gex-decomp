// Adapted from pc_decomp_backup/src/functions/FUN_0040EA90.cpp
// Historical source SHA256: 4cd28a0d65c681db354d9b9294508dfb0f8f6eb6aca117a87dcc3cb590dff085
extern "C" {
extern "C" void __cdecl FUN_0040C340(void**);
extern "C" { extern char* DAT_00487ff0; }
extern "C" { extern char* DAT_00488000; }
extern "C" { extern char* DAT_0048a010; }
extern "C" { extern char* DAT_0048a018; }
extern "C" { extern char* DAT_0048a01c; }
extern "C" { extern char* DAT_00487ffc; }
extern "C" void __cdecl GEX_Target(void* param1) {
    int* p = (int*)param1;
    p[0x1e] = 0x1e0000; p[0x1f] = 0x780000; p[0x27] = (int)DAT_00487ff0;
    FUN_0040C340((void**)param1);
    p[0x1e] = 0x820000; p[0x27] = (int)DAT_00488000; p[0x1f] = 0x780000;
    FUN_0040C340((void**)param1);
    p[0x1e] = 0x1e0000; p[0x27] = (int)DAT_0048a010; p[0x1f] = 0x910000;
    FUN_0040C340((void**)param1);
    p[0x1e] = 0x820000; p[0x27] = (int)DAT_0048a018; p[0x1f] = 0x910000;
    FUN_0040C340((void**)param1);
    p[0x1e] = 0x1e0000; p[0x27] = (int)DAT_0048a01c; p[0x1f] = 0xaa0000;
    FUN_0040C340((void**)param1);
    p[0x1e] = 0x820000; p[0x27] = (int)DAT_00487ffc; p[0x1f] = 0xaa0000;
    FUN_0040C340((void**)param1);
}
}
