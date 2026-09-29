// Adapted from pc_decomp_backup/src/functions/FUN_004094C0.cpp
// Historical source SHA256: f83103f91397d9a6e81d0931e693c907413d2d97ccfe336111098cc6b3045eb8
extern "C" {
extern "C" void __cdecl FUN_00409200(void*);

extern "C" void __cdecl FILE_Close_004094c0(void* fileHandle)
{
    int flag = *(int*)(*(int*)((char*)fileHandle + 4) + 8);
    if (flag == 1) FUN_00409200(*(void**)((char*)fileHandle + 8));
    *(int*)((char*)fileHandle + 0) = 0;
    *(void**)((char*)fileHandle + 4) = 0;
    *(void**)((char*)fileHandle + 8) = 0;
    *(int*)((char*)fileHandle + 0xc) = 0;
}
}
