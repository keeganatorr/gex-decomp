extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00414330(void *);
void __cdecl GEX_Target(int *object)
{
    FUN_00420BC0(object);
    object[0x15] = 0;
    object[0x26] = 0;
    object[0x1f] -= 0x1000;
    object[0x1c] = (int)0;
    object[0x14] = 0x5b;
    FUN_00414330(object);
}
}
