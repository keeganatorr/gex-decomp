extern "C" { extern int DAT_00456034; }
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  if (DAT_00456034 != 0xffffffff) {
    DAT_00456034 = param_1 + DAT_00456034 & 0x7fffffff;
  }
  return;
}
}
