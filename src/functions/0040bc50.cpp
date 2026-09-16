extern "C" {
extern int DAT_00456034;
void __cdecl GEX_Target(register unsigned amount) { unsigned current=(unsigned)DAT_00456034; unsigned delta=(unsigned)amount; if (current != 0xffffffffu) { unsigned result=current + delta; DAT_00456034=result & 0x7fffffffu; } }
}
