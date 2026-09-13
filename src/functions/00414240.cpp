// Adapted from pc_decomp_backup/src/functions/FUN_00414240.cpp
// Historical source SHA256: 482b0d87474bda196b8c9116ef644224950d7181e9f95ffe32f5266d9575fb6a
extern "C" {
extern "C" void __cdecl FUN_00421cd0(void**);
extern "C" void __cdecl FUN_00411A40(void**);

extern "C" void __cdecl GEX_Target(void** p)
{
    int v;
    FUN_00421cd0(p);
    v = (int)p[0x26] + 1;
    p[0x26] = (void*)v;
    if (v > 0) {
        if (p[0x15] == (void*)4) {
            FUN_00411A40(p);
            return;
        }
        p[0x26] = 0;
        p[0x15] = (void*)((int)p[0x15] + 1);
    }
}
}
