// Adapted from pc_decomp_backup/src/functions/FUN_00409320.cpp
// Historical source SHA256: 2e14167be65e60d6368b86080208c15f12f21d849e12b91b33ebd8570532ded1
extern "C" {
extern "C" void __cdecl FUN_00409200(void*);
extern "C" void __cdecl FUN_00409740(void*);

extern "C" void __cdecl GEX_Target(void* param_1)
{
    int* ip = (int*)param_1;
    if ((void*)ip[2] > (void*)2) {
        FUN_00409200((void*)ip[2]);
        FUN_00409740(*(void**)(ip + 1));
    }
    ip[0] = 0;
    ip[1] = 0;
    ip[2] = 0;
}
}
