extern "C" { extern unsigned char BYTE_ARRAY_004a2540[]; }
extern "C" { extern int DAT_0049fb90; }
typedef unsigned char byte;
typedef unsigned int uint;
extern "C" {
byte * __cdecl SCRIPT_GetLevelStatus_00418af0(byte *param_1)

{
  DAT_0049fb90 = (uint)BYTE_ARRAY_004a2540[*param_1];
  return param_1 + 1;
}
}
