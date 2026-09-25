extern "C" {
void GOB_ResetState_00420bc0(void**);
void PlayerRunJump_00425f40(void**);
extern int DAT_0045a6d4;
extern unsigned int DAT_004a0214_HighJump;
extern unsigned char DAT_004A0294;
}

extern "C" void __cdecl GEX_Target(int* param_1)
{
    GOB_ResetState_00420bc0((void**)param_1);
    param_1[0x1c] = 0xe;
    param_1[0x14] = 0x28;
    param_1[0x15] = 2;
    param_1[0x21] = DAT_0045a6d4;
    param_1[0x26] = (DAT_004a0214_HighJump == 0) ? 7 : 10;
    unsigned int highJump = DAT_004a0214_HighJump;
    param_1[0x25] = 0x14000;
    param_1[0x29] = 2;
    param_1[0x24] = 0xe0000;
    int currentX = ((highJump == 0) ? 0x18000 : 0) - 0xe0000;
    param_1[0x23] = currentX;
    param_1[0x27] = currentX;

    int* gOb_local = (int*)param_1[0x44];
    if (gOb_local != 0) {
        int diff = gOb_local[0x1e] - gOb_local[0x35];
        param_1[0x44] = 0;
        param_1[0x20] = param_1[0x20] + diff;
    }
    DAT_004A0294 = 0;
    PlayerRunJump_00425f40((void**)param_1);
}
