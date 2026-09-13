typedef unsigned int uint;
extern "C" {
void __cdecl GEX_Target(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xffe00000;
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xffe00000;
  }
  return;
}
}
