// Adapted from pc_decomp_backup/src/functions/FUN_00418040.cpp
// Historical source SHA256: d2afc8446a7ac618ab17586544d7e1587961a5ac5a7643efdc93f55523f6301e
extern "C" {
extern "C" { extern int DAT_0049FB90; }
extern "C" { extern int DAT_0049FB94; }

extern "C" void __cdecl GEX_Target(unsigned char* p, int* parent)
{
    unsigned char idx = *p;
    int* table = (int*)parent[0x57];
    if (table == 0) {
        table = (int*)DAT_0049FB94;
        if (table == 0) return;
    }
    DAT_0049FB90 = table[0x1a + idx];  
}
}
