extern "C" { extern int DAT_0049fb90; }
struct GXObject;
typedef unsigned char byte;
extern "C" {
byte * __cdecl GEX_Target(byte *param_1,GXObject **param_2)

{
  DAT_0049fb90 = (int)param_2[*param_1 + 0x1a] - (int)param_2[param_1[1] + 0x1a];
  return param_1 + 2;
}
}
