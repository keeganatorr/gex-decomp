// Adapted from pc_decomp_backup/src/functions/FUN_0040EFA0.cpp
// Historical source SHA256: 3c38d6a998380be8bb3b3da3dfd9c2455d85154fe46ea05af9faed0e63ddfa8e
extern "C" {
extern "C" { extern int DAT_004A27A4; }
extern "C" { extern int DAT_004A2AC8; }
extern "C" void __cdecl FUN_0042CBF0(int*);
extern "C" void __cdecl FUN_0042CC00(int*, int*);
extern "C" void __cdecl FUN_00417920(int, int*);

typedef void (__cdecl *ObjectCallback)(int*);

extern "C" void __cdecl GEX_Target(int* object)
{
    while (*object != 0) {
        int* next = (int*)object[0];
        if ((object[0x1b] & 0x100000) == 0) {
            ObjectCallback callback = (ObjectCallback)object[0x18];
            
            
            if (callback != 0 && callback != (ObjectCallback)FUN_00417920)
                callback(object);
            if ((object[0x38] & 0x2000000) == 0) {
                object[0x7e] = object[0x1e];
                object[0x7f] = object[0x1f];
            }
            object[0x7d] = DAT_004A2AC8;
        } else {
            FUN_0042CBF0(object);
            FUN_0042CC00((int*)0x004A27B0, object);
            --DAT_004A27A4;
        }
        object = next;
    }
}
}
