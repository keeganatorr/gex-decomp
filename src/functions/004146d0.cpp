extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00414600(void *);
void __cdecl GEX_Target(int *object)
{
    FUN_00420BC0(object);
    object[0x15] = 0;
    object[0x26] = 0;
    object[0x20] = 0;
    object[0x1c] = 6;
    object[0x14] = 0x37;
    object[0x22] = 0;
    FUN_00414600(object);
}
}
