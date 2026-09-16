extern "C" {
extern unsigned PTR_CLD_CheckCollisionNormal_00458cc0[];
unsigned char * __cdecl GEX_Target(register unsigned char *script, register unsigned *object) { unsigned index=*script++; unsigned value=PTR_CLD_CheckCollisionNormal_00458cc0[index]; object[0x5b]=value; return script; }
}
