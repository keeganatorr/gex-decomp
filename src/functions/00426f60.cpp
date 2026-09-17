extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00426DF0(void *);
void __cdecl GEX_Target(int *object)
{
    FUN_00420BC0(object);
    object[0x1c] = 0x19;
    int sign = object[0x20];
    object[0x14] = 0x32;
    object[0x15] = 2;
    object[0x26] = 0;
    object[0x22] = (sign < 0) ? 0x30000 : (int)0xfffd0000;
    FUN_00426DF0(object);
}
}
