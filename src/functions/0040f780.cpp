extern "C" { extern int* DAT_004a27dc; }
typedef unsigned int undefined4;
extern "C" {
void __cdecl GEX_Target(int param_1)

{
  *(undefined4 *)(param_1 * 0x24 + 0xc + (int)DAT_004a27dc) = 0;
  return;
}
}
