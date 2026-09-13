// Adapted from pc_decomp_backup/src/functions/FUN_0041E970.cpp
// Historical source SHA256: 2c5b15aab249fc2ee26cbf1da76c65fb77eaeddb01e9d5124afa3252b5eee7c5
extern "C" {
extern "C" void __cdecl FUN_0041E9A0(void**);
extern "C" { extern int DAT_00463680; }
extern "C" void __cdecl GEX_Target() {
    void** pp = (void**)0x463698;
    do {
        FUN_0041E9A0(pp);
        pp += 3;
    } while ((unsigned int)pp <= 0x46371cu);
    FUN_0041E9A0((void**)0x463680);
}
}
