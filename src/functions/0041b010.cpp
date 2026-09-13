// Adapted from pc_decomp_backup/src/functions/FUN_0041B010.cpp
// Historical source SHA256: 81dfc9f5d83fbaee7076c24df55ea3b75a52329f2ac006526c2c30672b663438
extern "C" {
extern "C" void __cdecl FUN_00444590(void*);
extern "C" void __cdecl FUN_00441150(void*);

extern "C" void __cdecl GEX_Target(void* param1)
{
    if (*(int*)((char*)param1 + 0xac) == 0) {
        FUN_00444590(param1);
        return;
    }
    if (*(int*)((char*)param1 + 0xb0) < 0) {
        FUN_00441150(param1);
    }
}
}
