extern "C" {
extern unsigned DAT_00461180;
int __cdecl _rand(void)

{
  DAT_00461180 = DAT_00461180 * 0x343fd + 0x269ec3;
  return (DAT_00461180 & 0x7fff0000) >> 0x10;
}
}
