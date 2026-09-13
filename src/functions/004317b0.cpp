struct GXObject;
// Adapted from pc_decomp_backup/src/functions/FUN_004317b0.cpp
// Historical source SHA256: c822ad64a1f1bb5aab33a68dfac16ddd3153fcf032c7984eb7d5483c705af406
extern "C" {
void __cdecl GEX_Target(GXObject **param_1)

{
  GXObject **temp_gOb;
  
  temp_gOb = (GXObject **)param_1[0x57];
  if (temp_gOb != (GXObject **)0x0) {
    param_1[0x1e] = (GXObject *)((int)param_1[0x1e] - (int)temp_gOb[0x1e]);
    param_1[0x1f] = (GXObject *)((int)param_1[0x1f] - (int)temp_gOb[0x1f]);
  }
  return;
}
}
