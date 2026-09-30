// Adapted from pc_decomp_backup/src/functions/FUN_00406C00.cpp
// Historical source SHA256: 8bc519ff71a43a2218401872c6a7c640d37bb4f068cd2a22456cc88f28b23a9b
extern "C" {
int __cdecl GEX_WidescreenConfiguredWidth(void);
extern "C" { extern int DAT_004a294c; }
extern "C" { extern unsigned int* FUN_00487F70; }
extern "C" void __cdecl FUN_00406c00_IfFreeGameNotEquals1_Unk_WHAT_DOES_THIS_DO_CONTAINS_PPVBITS() {
    if (DAT_004a294c == 1) return;
    int y = 0;
    do {
        unsigned int* p = FUN_00487F70 + y;
        int x = GEX_WidescreenConfiguredWidth() / 2;
        do { *p = 0; p++; x--; } while (x != 0);
        y += 0x200;
    } while (y != 0x1e000);
}
}
