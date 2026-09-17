extern "C" void GOB_ResetState_00420bc0(int *);
extern "C" void PlayerSideUnspin_004133a0(int *);

extern "C" void GEX_Target(int *param_1)
{
  GOB_ResetState_00420bc0(param_1);
  param_1[0x1c] = 0x4a;
  param_1[0x26] = 0;
  param_1[0x14] = 0x55;
  param_1[0x15] = 0x9;
  PlayerSideUnspin_004133a0(param_1);
}
