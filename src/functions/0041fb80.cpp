extern "C" { extern unsigned int DAT_004638C4; }
extern "C" { extern unsigned int DAT_004A02D0; }
extern "C" { extern unsigned int DAT_004639DC; }
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  DAT_004639DC = param_1;
  if (DAT_004A02D0 != param_1) {
    DAT_004638C4 = 1;
  }
  return;
}
}
