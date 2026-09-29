extern "C" {
void __cdecl FUN_00420BC0(int *);
void __cdecl FUN_00422410_EatingObject_pState_Call(int *);
void __cdecl PlayerFaceSwallow_00414fa0(int *);

void __cdecl InitPlayerFaceSwallow_00415040(int *param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = 0x30;
    param_1[0x14] = 0x47;
    FUN_00422410_EatingObject_pState_Call(param_1);
    PlayerFaceSwallow_00414fa0(param_1);
}
}
