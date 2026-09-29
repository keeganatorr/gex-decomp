typedef unsigned int uint;

extern "C" {
void __cdecl HelpBoxClid_0040d910(int param_1, int *param_2)
{
  if (*param_2) {
    uint flags = *(uint *)(param_1 + 0xa0);
    if ((flags & 0xf) == 0) {
      if ((**(uint **)(*(int *)(param_1 + 0x178) + 0x170) & 0xffff) == 1) {
        *(int *)(param_1 + 0xa4) = 0;
        *(int *)(param_1 + 0xa8) = 0;
        *(uint *)(param_1 + 0xa0) = (flags & 0xfffffff1) | 1;
      }
    }
  }
  *(uint *)(param_1 + 0xa0) = (*(uint *)(param_1 + 0xa0) & 0xfffffef) | 0x10;
}
}
