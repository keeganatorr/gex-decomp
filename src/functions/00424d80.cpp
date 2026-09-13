// Adapted from pc_decomp_backup/src/functions/FUN_00424D80.cpp
// Historical source SHA256: 32c0dfea3c84860bb15bce0bdc3f50f1f6d33ed2f92ee369f28f021a300aa1d1
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern int DAT_0045A6D0; }
extern "C" { extern unsigned int DAT_004A0214; }
extern "C" { extern unsigned char DAT_004A0294; }
extern "C" void __cdecl GEX_Target(void** gOb) {
    FUN_00420BC0(gOb);
    gOb[0x1c] = (void*)0xc;
    gOb[0x14] = (void*)0x27;
    gOb[0x15] = (void*)2;
    gOb[0x21] = (void*)&DAT_0045A6D0;
    gOb[0x26] = (void*)((-(unsigned int)(DAT_004A0214 == 0) & 0xfffffffd) + 8);
    unsigned int highJump = DAT_004A0214 == 0;
    gOb[0x29] = (void*)2;
    gOb[0x28] = 0;
    void** gOb_local = (void**)gOb[0x44];
    gOb[0x25] = (void*)0x14000;
    gOb[0x24] = (void*)0xe0000;
    void* jumpSpeed = (void*)((-(unsigned int)highJump & 0x1cccd) - 0xe0000);
    gOb[0x23] = jumpSpeed;
    if (gOb_local != 0) {
        void* currentX = gOb_local[0x1e];
        void* oldX = gOb_local[0x35];
        gOb[0x44] = 0;
        gOb[0x20] = (void*)((int)gOb[0x20] + ((int)currentX - (int)oldX));
    }
    gOb[0x27] = jumpSpeed;
    DAT_004A0294 = 0;
}
}
