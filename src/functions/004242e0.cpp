// Adapted from pc_decomp_backup/src/functions/FUN_004242E0.cpp
// Historical source SHA256: b6318727f0560c11443ebe0c73dfe967f9e9b41c48df46112099cc9029b6e3db
extern "C" {
extern "C" void __cdecl FUN_00424E50(void*);

extern "C" void __cdecl PlayerSlide45Jump_004242e0(void* obj)
{
    int val;

    val = *(int*)((char*)obj + 0x98);
    if (val != 0) {
        *(int*)((char*)obj + 0x98) = val - 1;
        return;
    }
    *(int*)((char*)obj + 0x98) = 0;
    *(int*)((char*)obj + 0x54) = *(int*)((char*)obj + 0x54) + 1;
    if (*(int*)((char*)obj + 0x54) == 2) {
        FUN_00424E50(obj);
    }
}
}
