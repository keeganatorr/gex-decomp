// Adapted from pc_decomp_backup/src/functions/FUN_0041FDB0.cpp
// Historical source SHA256: 24f6619c75e8c9a5809300ab689d4931083315b32380bcc6b511a9afade724e7
extern "C" {
extern "C" { extern int DAT_00463A34; }
extern "C" void __cdecl FUN_0041FD70();
extern "C" void __cdecl FUN_0041FCB0(int);
extern "C" void __cdecl GEX_Target(int p) {
    int g = DAT_00463A34;
    if (g == p) return;
    FUN_0041FD70();
    FUN_0041FCB0(p);
}
}
