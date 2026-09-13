// Adapted from pc_decomp_backup/src/functions/FUN_00429C10.cpp
// Historical source SHA256: 87cb8c37c234691b0e9cbb6ab49bfe5cde8cd23c8122ecec42a2087e16ea533e
extern "C" {
extern "C" void __cdecl FUN_004339C0(void**);

extern "C" int __cdecl GEX_Target(void** p)
{
    
    
    
    
    
    int* entry = (int*)0x004A28A0;
    int* end = (int*)0x004A2918;
    
    while (entry < end) {
        int* node = (int*)*entry;
        if (node != 0 && *node != 0) {
            
            while (node != 0) {
                if (node[2] == 0x10e && (unsigned int)(node[0x27] >> 16) == (unsigned int)p) {
                    FUN_004339C0(p);
                    return 1;
                }
                node = (int*)*node;
            }
        }
        entry += 3;
    }
    return 0;
}
}
