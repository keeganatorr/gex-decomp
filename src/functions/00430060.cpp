extern "C" {
int __cdecl GEX_Target(short **param_1)

{
  short sVar1;
  
  sVar1 = **param_1;
  *param_1 = *param_1 + 1;
  return (int)sVar1;
}
}
