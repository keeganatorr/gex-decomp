// Adapted from pc_decomp_backup/src/functions/FUN_00432D40.cpp
// Historical source SHA256: 1d4b336d9f73b9c20879ab23ee679f40414f741a4f78634f87eab934a25a4545
extern "C" {
extern "C" void __cdecl FUN_0041A340(void*, int);
extern "C" void __cdecl FUN_00432E60(void*);
extern "C" void __cdecl FUN_00432D10(void*);
extern "C" void __cdecl FUN_00419520(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int v38;

    *(int*)((char*)param_1 + 0xd4) = *(int*)((char*)param_1 + 0x78);
    *(int*)((char*)param_1 + 0xd8) = *(int*)((char*)param_1 + 0x7c);
    *(int*)((char*)param_1 + 0xfc) = *(int*)((char*)param_1 + 0x6c);
    *(int*)((char*)param_1 + 0xf4) = *(int*)((char*)param_1 + 0x50);
    *(int*)((char*)param_1 + 0xf8) = *(int*)((char*)param_1 + 0x54);
    *(int*)((char*)param_1 + 0xe4) = 0;
    v38 = *(int*)((char*)param_1 + 0xe0);
    *(int*)((char*)param_1 + 0xe8) = 0;
    *(int*)((char*)param_1 + 0xec) = 0;
    *(int*)((char*)param_1 + 0xf0) = 0;
    v38 = (v38 * 2 ^ (unsigned int)v38) & 0x200 ^ (unsigned int)v38;
    *(int*)((char*)param_1 + 0xe0) = v38;
    *(int*)((char*)param_1 + 0xe0) = v38 & 0xfffffeff;

    if (*(int*)((char*)param_1 + 0x98) == 0) {
        FUN_0041A340(param_1, 0x7d);
        FUN_00432E60(param_1);
        FUN_00432D10(*(void**)((char*)param_1 + 0xa0));
        FUN_00419520(param_1);
    } else {
        int v26 = *(int*)((char*)param_1 + 0x98) - 1;
        *(int*)((char*)param_1 + 0x98) = v26;
        if (v26 < 0x14) {
            int cond = ((unsigned int)v26 & 1) == 0;
            *(int*)((char*)(*(void**)((char*)param_1 + 0xa0)) + 0x1c) =
                *(int*)((char*)(*(void**)((char*)param_1 + 0xa0)) + 0x1c) +
                (cond ? -0x20000 : -0x10000);
            if (*(int*)((char*)param_1 + 0x9c) != 0) {
                *(int*)((char*)param_1 + 0x9c) = 0;
                FUN_0041A340(param_1, 0x7e);
            }
        }
    }
    if (*(int*)((char*)param_1 + 0x114) == -1) {
        *(int*)((char*)param_1 + 0x110) = 0;
    }
    *(int*)((char*)param_1 + 0x114) = -1;
}
}
