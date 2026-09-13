// Adapted from pc_decomp_backup/src/functions/FUN_0043F310.cpp
// Historical source SHA256: 928494320a371948c9ce97e9187a8f73af3e3f7a18a588d58a62628f070e2e9a
extern "C" {
extern "C" { extern int DAT_004a2b00; }
extern "C" { extern int DAT_0046a648_InitUnk3; }
extern "C" { extern int DAT_0046a660; }
extern "C" { extern int DAT_0046a650; }
extern "C" { extern unsigned char DAT_004a2afa_InitUnk6; }
extern "C" { extern int DAT_0046a644_InitUnk2; }
extern "C" { extern int DAT_0046a65c; }
extern "C" { extern int DAT_0046a654; }
extern "C" { extern unsigned char DAT_004a2af9_InitUnk5; }
extern "C" { extern int DAT_0046a640_InitUnk1; }
extern "C" { extern int DAT_0046a658; }
extern "C" { extern int DAT_0046a64c; }
extern "C" { extern unsigned char DAT_004a2af8_InitUnk4; }
extern "C" { extern unsigned int DAT_004a2afc; }

extern "C" void __cdecl GEX_Target() {
    if (DAT_004a2b00 == 0) { return; }
    {
        int bVar1 = 0;
        if (DAT_0046a648_InitUnk3 < DAT_0046a660) {
            DAT_0046a648_InitUnk3 = DAT_0046a648_InitUnk3 + DAT_0046a650;
            if (DAT_0046a660 < DAT_0046a648_InitUnk3) {
                DAT_0046a648_InitUnk3 = DAT_0046a660;
            }
            bVar1 = 1;
            DAT_004a2afa_InitUnk6 = (unsigned char)((unsigned int)DAT_0046a648_InitUnk3 >> 0x10);
        } else if (DAT_0046a660 < DAT_0046a648_InitUnk3) {
            DAT_0046a648_InitUnk3 = DAT_0046a648_InitUnk3 + DAT_0046a650;
            if (DAT_0046a648_InitUnk3 < DAT_0046a660) {
                DAT_0046a648_InitUnk3 = DAT_0046a660;
            }
            bVar1 = 1;
            DAT_004a2afa_InitUnk6 = (unsigned char)((unsigned int)DAT_0046a648_InitUnk3 >> 0x10);
        }
        if (DAT_0046a644_InitUnk2 < DAT_0046a65c) {
            DAT_0046a644_InitUnk2 = DAT_0046a644_InitUnk2 + DAT_0046a654;
            if (DAT_0046a65c < DAT_0046a644_InitUnk2) {
                DAT_0046a644_InitUnk2 = DAT_0046a65c;
            }
            bVar1 = 1;
            DAT_004a2af9_InitUnk5 = (unsigned char)((unsigned int)DAT_0046a644_InitUnk2 >> 0x10);
        } else if (DAT_0046a65c < DAT_0046a644_InitUnk2) {
            DAT_0046a644_InitUnk2 = DAT_0046a644_InitUnk2 + DAT_0046a654;
            if (DAT_0046a644_InitUnk2 < DAT_0046a65c) {
                DAT_0046a644_InitUnk2 = DAT_0046a65c;
            }
            bVar1 = 1;
            DAT_004a2af9_InitUnk5 = (unsigned char)((unsigned int)DAT_0046a644_InitUnk2 >> 0x10);
        }
        if (DAT_0046a640_InitUnk1 < DAT_0046a658) {
            DAT_0046a640_InitUnk1 = DAT_0046a640_InitUnk1 + DAT_0046a64c;
            if (DAT_0046a658 < DAT_0046a640_InitUnk1) {
                DAT_0046a640_InitUnk1 = DAT_0046a658;
            }
            bVar1 = 1;
            DAT_004a2af8_InitUnk4 = (unsigned char)((unsigned int)DAT_0046a640_InitUnk1 >> 0x10);
        } else if (DAT_0046a658 < DAT_0046a640_InitUnk1) {
            DAT_0046a640_InitUnk1 = DAT_0046a640_InitUnk1 + DAT_0046a64c;
            if (DAT_0046a640_InitUnk1 < DAT_0046a658) {
                DAT_0046a640_InitUnk1 = DAT_0046a658;
            }
            bVar1 = 1;
            DAT_004a2af8_InitUnk4 = (unsigned char)((unsigned int)DAT_0046a640_InitUnk1 >> 0x10);
        }
        if (!bVar1) {
            DAT_004a2b00 = 0;
        }
        DAT_004a2afc = (unsigned int)DAT_004a2afa_InitUnk6 + (((unsigned int)DAT_004a2af8_InitUnk4 * 0x100 + (unsigned int)DAT_004a2af9_InitUnk5) * 0x100);
    }
}
}
