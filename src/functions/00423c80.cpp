extern "C" { extern int DAT_00456B04; }
struct GXObject;
extern "C" {
void __cdecl GX_ResetRotAndScale_00423c80(GXObject **param_1)

{
  param_1[0x31] = (GXObject *)0x0;
  if (DAT_00456B04 != 0) {
    param_1[0x32] = (GXObject *)0x10000;
    param_1[0x33] = (GXObject *)0x10000;
  }
  return;
}
}
