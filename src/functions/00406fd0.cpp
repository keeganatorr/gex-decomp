// Adapted from pc_decomp_backup/src/functions/FUN_00406fd0.cpp
// Historical source SHA256: a71f3a0240d9e32f744479e4b5ed19a50b638b7809f06f205bda74c86473cba6
typedef unsigned int uint;
extern "C" {
int __cdecl GEX_Target(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    for (; (param_1 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  return iVar1;
}
}
