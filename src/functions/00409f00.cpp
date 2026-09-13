// Adapted from pc_decomp_backup/src/functions/FUN_00409F00.cpp
// Historical source SHA256: 6f43d3d69b9d443698395959e0f4cbaac6b9f2e98f3784b7557dd784c0e2e11c
extern "C" {
extern "C" { extern char DAT_00455B38; }
extern "C" { extern int DAT_00455C24; }
extern "C" { extern int DAT_00455C28; }
extern "C" { extern int DAT_00456B00; }
extern "C" { extern int DAT_00459498; }
extern "C" { extern int DAT_004A2964; }
extern "C" { extern int DAT_004A2AC0; }

extern "C" void __cdecl GEX_Target()
{
    if (DAT_004A2964 != 0x44 && DAT_004A2AC0 == 0) {
        volatile int state = (unsigned char)DAT_00455B38;
        if (state == 2) {
            DAT_00455B38 = 0xb;
            DAT_00455C24 = 1;
            DAT_00456B00 = 99;
            return;
        }
        if (state == 3) {
            DAT_00455B38 = 0xb;
            DAT_00459498 = 5;
            return;
        }
        if (state == 4) {
            DAT_00455B38 = 0xb;
            DAT_00459498 = 4;
            return;
        }
        if (state == 5) {
            DAT_00455B38 = 0xb;
            DAT_00459498 = 6;
            return;
        }
        if (state == 6) {
            DAT_00455B38 = 0xb;
            DAT_00459498 = 2;
            return;
        }
        if (state == 7) {
            DAT_00455B38 = 0xb;
            DAT_00459498 = 8;
            return;
        }
        if (state == 8) {
            DAT_00455B38 = 0xb;
            DAT_00455C28 = 1;
            return;
        }
    }
}
}
