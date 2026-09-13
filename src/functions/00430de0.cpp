extern "C" { int __cdecl FUN_00449E10(); }
struct GXObject;
typedef unsigned int uint;
extern "C" {
int __cdecl GEX_Target(GXObject **param_1)

{
  int iVar1;
  
  param_1[0x38] = (GXObject *)((uint)param_1[0x38] | 0x40);
  iVar1 = FUN_00449E10();
  param_1[0x2c] = (GXObject *)0x3;
  param_1[0x2b] = (GXObject *)(iVar1 % 10);
  return iVar1 / 10;
}
}
