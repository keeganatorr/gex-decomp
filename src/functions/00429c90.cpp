extern "C" { extern unsigned char BYTE_ARRAY_004a25d0[]; }
typedef unsigned int uint;
typedef unsigned __int64 ulonglong;
extern "C" {
ulonglong GEX_Target(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (BYTE_ARRAY_004a25d0[iVar2] != 0) {
      uVar1 = uVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x90);
  return (ulonglong)uVar1;
}
}
