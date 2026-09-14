typedef unsigned int uint;
extern "C" {
extern unsigned char DAT_004A0295;
extern unsigned char DAT_004A0293;
extern void __cdecl FUN_00425AF0(void *);
uint __cdecl GEX_Target(void *object)
{
    if (DAT_004A0295 == 0 || DAT_004A0293 != 0)
        return 0;
    FUN_00425AF0(object);
    return 1;
}
}
