extern "C" { extern int DAT_0049fb90; }
struct GXObject;
typedef unsigned char byte;
extern "C" {
byte * __cdecl SCRIPT_SubWorkField_00418c80(byte *param_1,GXObject **param_2)

{
  DAT_0049fb90 = DAT_0049fb90 - (int)param_2[*param_1 + 0x1a];
  return param_1 + 1;
}
}
