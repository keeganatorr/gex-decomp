// Adapted from pc_decomp_backup/src/functions/FUN_00435980.cpp
// Historical source SHA256: 01090efeee458c202e6319e0d32e9513d0e71eba5b07b2504c8b6af16cfdb936
extern "C" {
extern "C" void __cdecl FUN_00435a10(void**);
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00444590(void*);
extern "C" { extern int DAT_0045b7b4; }

extern "C" void __cdecl GEX_Target(void** gOb)
{
    int val = (int)gOb[0x1c];
    if (val == 0) {
        FUN_00435a10(gOb);
        gOb[0x15] = gOb[0x26];
        gOb[0x14] = 0;
        if (((unsigned int)gOb[0x2d] & 1) == 0) {
            FUN_00444590(gOb);
            return;
        }
        int tmp = (int)gOb[0x2a];
        int adj = DAT_0045b7b4;
        tmp = tmp + adj - 0x1c;
        gOb[0x2a] = (void*)tmp;
        unsigned int val2 = (unsigned int)tmp & 0xff0000;
        gOb[0x2a] = (void*)val2;
        gOb[0x31] = (void*)val2;
        FUN_00441150(gOb);
        gOb[0x31] = 0;
        return;
    }
    if (val == 1) {
        FUN_00444590(gOb);
    }
}
}
