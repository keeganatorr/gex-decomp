// Adapted from pc_decomp_backup/src/functions/FUN_00429B80.cpp
// Historical source SHA256: fa4926cdde4f6e0671f32228fa1c61b88655914adbac0ea3b323d7684d87746b
extern "C" {
extern "C" { extern int DAT_004A2964; }
extern "C" void __cdecl FUN_004339C0(void**);

extern "C" int __cdecl GEX_Target(void** p)
{
    int* base = (int*)0x004A28A0;
    
    while ((int)base < 0x004A2918) {
        int* node = (int*)*base;
        if (node != 0 && *node != 0) {
            while (node != 0) {
                if (node[2] == 0xdc) {
                    int val = node[0x27];
                    if (val == DAT_004A2964 || (val >= 0x31 && val <= 0x36)) {
                        FUN_004339C0(p);
                        return 1;
                    }
                }
                node = (int*)*node;
            }
        }
        base += 3;
    }
    return 0;
}
}
