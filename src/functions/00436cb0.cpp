// Adapted from pc_decomp_backup/src/functions/FUN_00436CB0.cpp
// Historical source SHA256: 964a3217fb7dfe4240ac9e410b681253a5ba33f56452d564035e4c03b42708b6
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00444590(void*);

extern "C" void __cdecl FUN_00436cb0_Graphics_unk(void* param1)
{
    int flags = *(int*)((char*)param1 + 0xe0);
    if (flags & 0x40) {
        FUN_00441150(param1);
        return;
    }
    if (*(int*)((char*)param1 + 0xc4) != 0) {
        FUN_00441150(param1);
        return;
    }
    FUN_00444590(param1);
}
}
