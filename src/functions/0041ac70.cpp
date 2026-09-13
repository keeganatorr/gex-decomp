// Adapted from pc_decomp_backup/src/functions/FUN_0041AC70.cpp
// Historical source SHA256: c2ce70497d7ee0f6acebc5c51f27ddff6c392725e42b2e0658168802eb7f3edb
extern "C" {
extern "C" { extern int DAT_00459048; }
extern "C" { extern int DAT_00455C3C; }
extern "C" { extern int DAT_004A2964; }
extern "C" { extern int DAT_004A2A7C; }

extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" int __cdecl FUN_0041A0A0(void**, int);
extern "C" void __cdecl FUN_0041A600(void);
extern "C" void __cdecl FUN_004372F0(void**);
extern "C" void __cdecl FUN_00419A80(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    {
        unsigned int p38 = (unsigned int)param_1[0x38];
        p38 = ((p38 * 2 ^ p38) & 0x200 ^ p38);
        p38 = p38 & 0xfffffeff;
        param_1[0x38] = (void*)p38;
    }
    if (FUN_0040FCE0(param_1) == 0) {
        unsigned int p2b = (unsigned int)param_1[0x2b];
        if (p2b == 1) {
            param_1[0x23] = (void*)0xfffd0000;
            param_1[0x25] = (void*)0xa000;
            param_1[0x32] = (void*)0xa000;
            param_1[0x33] = (void*)0xa000;
            param_1[0x2b] = (void*)2;
        } else if (p2b == 2) {
            
        } else if (p2b == 3) {
            param_1[0x2b] = (void*)4;
            FUN_004372F0(param_1);
        }
        if (param_1[0x2b] != 0) {
            param_1[0x2c] = (void*)((int)param_1[0x2c] - 1);
            if (param_1[0x2c] == 0) {
                
            }
        }
        param_1[0x2a] = (void*)((int)param_1[0x2a] - 1);
    }
    if (param_1[0x45] == (void*)0xffffffff) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = (void*)0xffffffff;
}
}
