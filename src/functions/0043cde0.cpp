// Adapted from pc_decomp_backup/src/functions/FUN_0043CDE0.cpp
// Historical source SHA256: 2828f0ff2ec67a5202a8c7bf08e67dd764d1fa48cbd00bad6a4b154da38525de
extern "C" {
extern "C" {
    extern void __cdecl FUN_00444530(void*);
    extern void __cdecl FUN_00444590(void*);
}

extern "C" void __cdecl ob1Draw_0043cde0(void* p)
{
    int esi = (int)p;
    int eax = *(int*)(esi + 0xe0);
    if (eax & 0x40000) {
        FUN_00444530((void*)esi);
    }
    FUN_00444590((void*)esi);
}
}
