extern "C" {
extern unsigned DAT_004645a8;extern unsigned DAT_00464658;extern unsigned DAT_0046465c;extern unsigned DAT_004646f8;extern unsigned DAT_00464704;
void FUN_004397c0_HuntDiveInner(void)

{
  *(int *)(DAT_00464704 + 0xc4) = DAT_004645a8 << 0x10;
  DAT_00464658 = 0;
  DAT_004646f8 = 0;
  DAT_0046465c = 0x8000;
  return;
}
}
