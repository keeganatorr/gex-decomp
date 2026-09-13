extern "C" { extern int FUN_004A2934; }
extern "C" { extern int DAT_0049fb90; }
typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl GEX_Target(undefined4 param_1)

{
  DAT_0049fb90 =
       *(undefined4 *)(FUN_004A2934 + -8 + (DAT_0049fb90 & 0xffff) * 8)
  ;
  return param_1;
}
}
