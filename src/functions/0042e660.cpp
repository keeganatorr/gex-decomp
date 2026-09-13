// Adapted from pc_decomp_backup/src/functions/FUN_0042E660.cpp
// Historical source SHA256: 56a4c622ae5ed9f6916af9d6ff1b3c9d3968401204c9e9f3ed34cd5e4c5552dd
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" void __cdecl FUN_0042e5e0(int, int, int);
extern "C" void __cdecl GEX_Target(void** param1, int param2) {
    int local_28[6];
    int local_10, local_c, local_8, local_4;
    if (param2 == 0) {
        int iVar1 = FUN_0041CB80(param1, local_28);
        if (iVar1 != 0)
            FUN_0042e5e0((int)param1, ((local_c - local_10) >> 1) + local_10, ((local_4 - local_8) >> 1) + local_8);
    } else {
        int a = (*(int*)(param2 + 0x24) - *(int*)(param2 + 0x20) >> 1) + *(int*)(param2 + 0x20);
        int b = (*(int*)(param2 + 0x2c) - *(int*)(param2 + 0x28) >> 1) + *(int*)(param2 + 0x28);
        int c = (*(int*)(param2 + 0x4c) - *(int*)(param2 + 0x48) >> 1) + *(int*)(param2 + 0x48);
        int d = (*(int*)(param2 + 0x54) - *(int*)(param2 + 0x50) >> 1) + *(int*)(param2 + 0x50);
        int minX = a; int maxX = c;
        if (c < a) { minX = c; maxX = a; }
        int minY = b; int maxY = d;
        if (d < b) { minY = d; maxY = b; }
        FUN_0042e5e0((int)param1, ((maxX - minX) >> 1) + minX, ((maxY - minY) >> 1) + minY);
    }
}
}
