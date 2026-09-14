extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00427980(void *);
void __cdecl GEX_Target(int *object)
{
    FUN_00420BC0(object);
    object[0x15] = 0;
    object[0x26] = 0;
    object[0x20] = 0;
    object[0x14] = 0x2c;
    object[0x22] = 0;
    FUN_00427980(object);
}
}
