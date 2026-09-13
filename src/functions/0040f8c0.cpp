// Adapted from pc_decomp_backup/src/functions/FUN_0040F8C0.cpp
// Historical source SHA256: 2debd96346c16337d948c92431178afbb663413e84b620777394db48a786bf72
extern "C" {
extern "C" { extern int DAT_004a27d4; }

typedef void (__cdecl *ObjectCallback)(int*, int*);

extern "C" void __cdecl GEX_Target(int* objectSet)
{
    DAT_004a27d4 = 1;
    int* object = (int*)objectSet[0];

    for (int index = 0; index < objectSet[2]; ++index, object += 4) {
        if ((object[1] & 0x4000) != 0) {
            ((ObjectCallback)objectSet[1])(object, objectSet);
        }
    }
    DAT_004a27d4 = 0;
}
}
