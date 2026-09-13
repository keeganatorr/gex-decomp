// Adapted from pc_decomp_backup/src/functions/FUN_0040b6d0.cpp
// Historical source SHA256: 76ed2c458374ddd90ef159956a64629fa27716d88d05e159bb31cda080982053
extern "C" {
void __cdecl GEX_Target(int *param_1,int param_2,int param_3)

{
  if (param_3 < 1) {
    return;
  }
  do {
    *param_1 = param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 0x2000;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}
}
