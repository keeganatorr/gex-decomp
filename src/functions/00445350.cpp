typedef unsigned int uint;
extern "C" {
void __cdecl
GEX_Target(void *tileStructPtr,int tileRow,int baseOffset,uint tileCol)

{
                     
  *(uint *)((int)tileStructPtr + 4) =
       (baseOffset + -0xf8000 + tileRow * 2) * 0x200 + (tileCol & 0x1ff);
  return;
}
}
