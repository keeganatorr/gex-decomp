typedef unsigned __int64 undefined8;
extern "C" {
undefined8 __cdecl GEX_Target(int *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}
}
