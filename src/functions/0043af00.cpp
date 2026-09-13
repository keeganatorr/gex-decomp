// Adapted from pc_decomp_backup/src/functions/FUN_0043AF00.cpp
// Historical source SHA256: 77c9d531575b0381b495426001880899e0662a1a370920711d15fa4c0b4689d0
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_00464788;
extern int DAT_00464794;
extern int DAT_004a2b00;
extern int DAT_00455be4;
extern int DAT_0045ffd8;

extern "C" void __cdecl FUN_0043F490(int, int, int, int, int, int, int);

extern "C" void __cdecl GEX_Target(void **param_1)
{
    int iVar1;

    if (param_1[0x27] != (void *)0x0) {
        if (((((int)param_1[0x1e] < CAMERA_XPos_004a2a38) ||
             (CAMERA_XPos_004a2a38 + 0x1400000 < (int)param_1[0x1e])) ||
            ((int)param_1[0x1f] < CAMERA_YPos_004a2a1c)) ||
           (CAMERA_YPos_004a2a1c + 0xf00000 < (int)param_1[0x1f])) {
            DAT_00464788 = DAT_00464788 + -1;
            goto FUN_0043AF82;
        }
        goto FUN_0043AF82;
    }
    if (((CAMERA_XPos_004a2a38 <= (int)param_1[0x1e]) &&
        ((int)param_1[0x1e] <= CAMERA_XPos_004a2a38 + 0x1400000)) &&
       ((CAMERA_YPos_004a2a1c <= (int)param_1[0x1f] &&
        ((int)param_1[0x1f] <= CAMERA_YPos_004a2a1c + 0xf00000)))) {
        DAT_00464788 = DAT_00464788 + 1;
    }
FUN_0043AF82:
    if (((DAT_00464794 == (int)param_1) && (DAT_004a2b00 == 0)) && (DAT_00455be4 == 0)) {
        iVar1 = DAT_00464788 << 7;
        if (iVar1 < 1) {
            iVar1 = 0;
        }
        iVar1 = 0xff - iVar1;
        if (iVar1 < 1) {
            iVar1 = 0;
        }
        if (DAT_0045ffd8 == 0) {
            FUN_0043F490(0x12, 0xff - iVar1, 0xff, 0, 0xff, 0, 0xff);
            DAT_0045ffd8 = 1;
        }
        else {
            FUN_0043F490(0x12, 0, 0xff, 0, 0xff, 0, 0xff);
            DAT_0045ffd8 = 0;
        }
    }
    if ((((CAMERA_XPos_004a2a38 <= (int)param_1[0x1e]) &&
         ((int)param_1[0x1e] <= CAMERA_XPos_004a2a38 + 0x1400000)) &&
        (CAMERA_YPos_004a2a1c <= (int)param_1[0x1f])) &&
       ((int)param_1[0x1f] <= CAMERA_YPos_004a2a1c + 0xf00000)) {
        param_1[0x27] = (void *)1;
        return;
    }
    param_1[0x27] = (void *)0x0;
}
}
