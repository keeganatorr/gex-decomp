// Adapted from pc_decomp_backup/src/functions/FUN_00433E60.cpp
// Historical source SHA256: 78481b9601a4935dfb6d419c75ea09e5ad64d0c311296db1cc667d919de6441a
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00433B20(void**);

extern "C" { extern int DAT_00455BE8; }
extern "C" { extern int DAT_00455BEC; }

extern "C" void __cdecl ExitTVDraw_00433e60(void* param_1)
{
    if (*(int*)((int*)param_1 + 0x27) == (int)0x80000000) {
        *(int*)((int*)param_1 + 0x32) = DAT_00455BE8;
        *(int*)((int*)param_1 + 0x33) = DAT_00455BEC;
        *(int*)((int*)param_1 + 0x31) = *(int*)((int*)param_1 + 0x31) + 0x100;
        FUN_00441150(param_1);
        return;
    }
    FUN_00433B20((void**)param_1);
}
}
