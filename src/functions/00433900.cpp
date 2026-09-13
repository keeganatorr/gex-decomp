// Adapted from pc_decomp_backup/src/functions/FUN_00433900.cpp
// Historical source SHA256: 1700a78a17269da1949ba10a330e1fc50143e3d6d9cc703a9fc2636c785da3b9
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_00439090(void**);
extern "C" void __cdecl FUN_004390D0(void**);
extern "C" void* __cdecl FUN_00433590(void**, void*, void*, int);

extern "C" void __cdecl GEX_Target(void** objectType)
{
    if (objectType[0x57] == 0 && FUN_0040FCE0(objectType) != 0) return;
    unsigned int flags = (unsigned int)objectType[0x1b];
    objectType[0x1b] = (void*)(flags & 0xe0ffffff);
    if (flags & 0x4000) FUN_00439090(objectType);
    if ((unsigned int)objectType[0x1b] & 0x8000) FUN_004390D0(objectType);
    if (objectType[4] != 0) objectType[4] = FUN_00433590(objectType, objectType + 4, objectType[4], 0);
    if (objectType[0xc] != 0) objectType[0xc] = FUN_00433590(objectType, objectType + 0xc, objectType[0xc], -1);
    for (int i = 0; i < 12; i++) {
        int* event = (int*)((char*)objectType + 0x194 + i * 8);
        int evNum = event[0];
        if (evNum != 0) {
            int (*handler)(void**) = (int(*)(void**))((int*)0x0045f00c)[evNum];
            if (handler(objectType) != 0) {
                FUN_00433590(objectType, (void*)0x00464258, (void*)event[1], evNum);
            }
        }
    }
}
}
