extern "C" {
int CAMERA_XPos_004a2a38;
int CAMERA_YPos_004a2a1c;
int DAT_004A2964;
void FUN_00419B80(void*, int);
void FUN_0040FE80(int, int, int);
}

extern "C" void FUN_0040FE00(int *param_1)
{
    int temp = param_1[0x1e];
    param_1[0x2a] = temp - CAMERA_XPos_004a2a38;
    param_1[0x2b] = param_1[0x1f] - CAMERA_YPos_004a2a1c;
    param_1[0x2c] = CAMERA_XPos_004a2a38;
    param_1[0x2d] = CAMERA_YPos_004a2a1c;
    if (DAT_004A2964 == 0x3c && param_1[0x26] == 0) {
        param_1[0x1e] = temp + 0x10000;
    }
    FUN_00419B80(param_1, 9);
    FUN_0040FE80((int)param_1, 0x1400000, 1);
}
