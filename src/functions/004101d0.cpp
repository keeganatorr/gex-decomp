extern "C" { extern unsigned __cdecl FUN_0040fce0(unsigned *); extern unsigned __cdecl FUN_0040fe80(unsigned *,unsigned,unsigned);
unsigned __cdecl GEX_Target(register unsigned *object) { unsigned result=FUN_0040fce0(object); if (result==0) result=FUN_0040fe80(object,0x500000u,0u); return result; }
}
