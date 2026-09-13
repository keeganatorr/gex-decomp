extern "C" { extern int DAT_0049fb90; }
struct GXObject;
typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl GEX_Target(undefined4 param_1,GXObject **param_2)

{
  DAT_0049fb90 = (int)param_2[0x1e] - (int)param_2[0x35];
  return param_1;
}
}
