extern "C" {
extern int DAT_00455b90;
extern int CAMERA_YPos_004a2a1c;
extern int CAMERA_XPos_004a2a38;

extern int __cdecl FUN_0041CB80(int *param_1, int *param_2);
extern void __cdecl FUN_0042cc70_Object_unk(int param_1, int *param_2);

int __cdecl GEX_Target(int *param_1, void (__cdecl *param_2)(int *, int))
{
    int local[10];
    int v;

    if (DAT_00455b90 != 0) {
        if (FUN_0041CB80(param_1, local) == 0)
            return 0;

        v = local[9] - CAMERA_YPos_004a2a1c;
        if (v >= 0xf00000) {
            param_1[0x1f] = param_1[0x1f] + (v - 0xf00001);
            if (param_2 != 0)
                param_2(param_1, 0);
            param_1[0x3b] = CAMERA_XPos_004a2a38 + 0xf00000;
            if (param_1[0x3c] != 0)
                FUN_0042cc70_Object_unk(0, param_1);
        }

        v = local[8] - CAMERA_YPos_004a2a1c;
        if (v < 0) {
            param_1[0x1f] = param_1[0x1f] - v;
            if (param_2 != 0)
                param_2(param_1, 0);
            param_1[0x3c] = CAMERA_YPos_004a2a1c;
            if (param_1[0x3b] != 0)
                FUN_0042cc70_Object_unk(0, param_1);
        }
    }

    return 0;
}
}
