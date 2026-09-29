typedef unsigned char byte;
typedef unsigned int uint;

extern "C" {
byte * __cdecl SCRIPT_CopyFieldToChildren_004182f0(byte *param_1, void **param_2)
{
  uint idx;
  void *v;
  void **p;

  idx = *param_1++;
  v = param_2[idx + 0x1a];
  for (p = (void **)param_2[0x58]; p != 0; p = (void **)p[0x59]) {
    p[idx + 0x1a] = v;
  }
  return param_1;
}
}
