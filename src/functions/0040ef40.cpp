// Adapted from pc_decomp_backup/src/functions/FUN_0040EF40.cpp
// Historical source SHA256: 0572b03040754cbf611790b38ae440ccec5b100c078c0ec53420ce0e5415e6a8
extern "C" {
extern "C" void __cdecl FUN_0042CBF0(int*);
extern "C" void __cdecl FUN_0042CC00(int*, int*);
extern "C" { extern int DAT_004A27A4; }

typedef void (__cdecl *ObjectCallback)(int*);

extern "C" void __cdecl GEX_Target(int* object)
{
    while (*object != 0) {
        int* next = (int*)object[0];
        if ((object[0x1b] & 0x100000) == 0) {
            ObjectCallback callback = (ObjectCallback)object[0x17];
            
            
            
            if ((unsigned int)callback >= 0x00401000 &&
                (unsigned int)callback < 0x00450000) {
                callback(object);
            }
        } else {
            FUN_0042CBF0(object);
            FUN_0042CC00((int*)0x004A27B0, object);
            --DAT_004A27A4;
        }
        object = next;
    }
}
}
