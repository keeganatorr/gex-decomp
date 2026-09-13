// Adapted from pc_decomp_backup/src/functions/FUN_0041FB50.cpp
// Historical source SHA256: 09898e6eef129eaa358822f0ab0d956f50dce8c69e14d89e0ee3547cb4e685bd
extern "C" {
extern "C" int __cdecl FUN_00401B00();
extern "C" { extern int DAT_004639D8; }
extern "C" int __cdecl GEX_Target() {
    int g = DAT_004639D8;
    if (g != 0) {
        int playing = FUN_00401B00();
        g = (playing == 0) ? 1 : 0;
    }
    DAT_004639D8 = g;
    return (g == 0) ? 1 : 0;
}
}
