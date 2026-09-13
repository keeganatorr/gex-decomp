extern "C" { void __cdecl FUN_00445270(void*); }
extern "C" { void __cdecl FUN_00445240(int); }
extern "C" { extern unsigned char DAT_0046A588; }
extern "C" { extern int DAT_0046A560[1]; }
extern "C" { extern unsigned int DAT_004A2B08; }
// Adapted from pc_decomp_backup/src/functions/FUN_0043F290.cpp
// Historical source SHA256: 45fbb77c7477e50aa5453caac84e5bd1f018fdf9b1073c5e294a83facfc9713e
extern "C" {
extern "C" void __cdecl FUN_00445240(int);
extern "C" void __cdecl FUN_00445270(void*);
extern "C" void GEX_Target(void)

{
  DAT_004A2B08 = DAT_004A2B08 ^ 1;
  FUN_00445240((int)&DAT_0046A560 + DAT_004A2B08 * 0x14);
  FUN_00445270(&DAT_0046A588 + DAT_004A2B08 * 0x5c);
  return;
}
}
