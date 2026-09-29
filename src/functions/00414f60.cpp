extern "C" void GOB_ResetState_00420bc0(void *);
extern "C" void PlayerDuckUnspin_00414e80(void *);

extern "C" void InitPlayerDuckUnspin_00414f60(int *param_1)
{
    GOB_ResetState_00420bc0(param_1);
    param_1[0x1c] = 0x23;
    param_1[0x26] = 0;
    param_1[0x14] = 0x33;
    param_1[0x15] = 2;
    PlayerDuckUnspin_00414e80(param_1);
}
