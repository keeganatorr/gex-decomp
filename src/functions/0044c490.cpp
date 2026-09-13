typedef unsigned int undefined4;
extern "C" {
undefined4 __cdecl GEX_Target(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}
}
