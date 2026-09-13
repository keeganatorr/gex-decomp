extern "C" { void __cdecl FUN_00441150(void*); }
struct GXObject;
extern "C" {
void __cdecl
GEX_Target
          (GXObject **param_1,GXObject *param_2,GXObject *param_3,GXObject *param_4,
          GXObject *param_5)

{
  GXObject *pGVar1;
  GXObject *pGVar2;
  GXObject *pGVar3;
  GXObject *pGVar4;
  
  pGVar1 = param_1[0x14];
  pGVar2 = param_1[0x15];
  pGVar3 = param_1[0x1e];
  pGVar4 = param_1[0x1f];
  param_1[0x1e] = param_4;
  param_1[0x1f] = param_5;
  param_1[0x15] = param_3;
  param_1[0x14] = param_2;
  FUN_00441150((GXObject *)param_1);
  param_1[0x1e] = pGVar3;
  param_1[0x1f] = pGVar4;
  param_1[0x15] = pGVar2;
  param_1[0x14] = pGVar1;
  return;
}
}
