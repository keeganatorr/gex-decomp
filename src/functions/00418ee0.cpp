extern "C" { extern int FUN_0045B808; }
extern "C" { extern int DAT_0049fb90; }
extern "C" { unsigned int __cdecl FUN_00417F40(unsigned int**); }
typedef unsigned int uint;
typedef unsigned int undefined4;
// Adapted from pc_decomp_backup/src/functions/FUN_00418EE0.cpp
// Historical source SHA256: 380a3547a5bc92d72ed993fa94e12d7502e1e5e621af38411eee328f0ff732bf
extern "C" {
extern "C" unsigned int __cdecl FUN_00417F40(unsigned int**);
extern "C" { extern int FUN_0049FB90; }
extern "C" { extern int FUN_0045B808; }
extern "C" uint * __cdecl GEX_Target(uint *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00417F40(&param_1);
  DAT_0049fb90 =
       *(undefined4 *)((&FUN_0045B808)[uVar1] + DAT_0049fb90 * 4);
  return param_1;
}
}
