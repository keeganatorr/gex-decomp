extern "C" { extern unsigned __cdecl FUN_00417f40(unsigned char **); extern void __cdecl FUN_0041a340(unsigned *,unsigned);
unsigned char * __cdecl SCRIPT_PlaySound_00418b30(unsigned char *script, unsigned *object) {  unsigned sound=FUN_00417f40(&script); FUN_0041a340(object,sound); return script; }
}
