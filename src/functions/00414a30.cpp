extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00414900(void *);
void __cdecl InitPlayerDuckTongueLash_00414a30(int *object)
{
    FUN_00420BC0(object);
    object[0x15] = 0;
    object[0x26] = 0;
    object[0x28] = 0;
    object[0x20] = 0;
    object[0x22] = 0;
    object[0x1c] = 0x1f;
    object[0x14] = 0x36;
    FUN_00414900(object);
}
}
