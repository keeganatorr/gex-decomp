extern "C" {
extern int CAMERA_XPos_004a2a38;
extern void __cdecl FUN_00441150(void*);
}

extern "C" void __cdecl ob258Draw_0043b890(int* param_1)
{
    int val;

    param_1[0x1e] = param_1[0x2b] + CAMERA_XPos_004a2a38;
    if (--param_1[0x2e] < 0) {
        FUN_00441150(param_1);
        return;
    }
    if (param_1[0x2e] % 2) {
        FUN_00441150(param_1);
        return;
    }
    val = param_1[0x2f];
    param_1[0x2f] = 0x1d001d00;
    FUN_00441150(param_1);
    param_1[0x2f] = val;
}
