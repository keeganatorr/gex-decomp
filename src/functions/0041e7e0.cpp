// Adapted from pc_decomp_backup/src/functions/FUN_0041E7E0.cpp
// Historical source SHA256: a2648115d7ccdea37c85583d2991126f29f92b5b08463a0ec3e8d7ed26d32a41
extern "C" {
extern "C" { extern int DAT_004595E8; }
extern "C" { extern int DAT_00459604; }
extern "C" { extern void* DAT_00463680; }
extern "C" { extern void* DAT_00463728; }
extern "C" { extern int DAT_004A23C0; }
extern "C" void __cdecl FUN_00405350(int, int);
extern "C" void __cdecl FUN_00405390(int);
extern "C" void* __cdecl FUN_0042CC20(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);

extern "C" void __cdecl GEX_Target(void** objectType, int* func1, int* func2, int* func3)
{
    void* CollisionObjects;

    if (((unsigned int)objectType[0x1b] & 0x100000) != 0) {
        FUN_00405350((int)&DAT_00459604, (int)objectType[2]);
        return;
    }
    if (func2 != (int*)0x0) {
        CollisionObjects = FUN_0042CC20((void**)&DAT_00463728);
        if (CollisionObjects == (void*)0x0) {
            FUN_00405390((int)&DAT_004595E8);
            return;
        }
        DAT_004A23C0 = DAT_004A23C0 + 1;
        *(int*)((int)CollisionObjects + 0x08) = (int)objectType;
        objectType[0x5a] = (void*)func1;
        objectType[0x5b] = (void*)func3;
        objectType[0x60] = CollisionObjects;
        objectType[0x1b] = (void*)(((unsigned int)objectType[0x1b] & 0xfffff0ff) | ((int)func2 << 8));
        FUN_0042CC00((void**)&DAT_00463680, (void**)CollisionObjects);
    }
}
}
