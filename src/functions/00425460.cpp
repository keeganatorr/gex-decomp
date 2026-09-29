extern "C" {
extern void __cdecl FUN_00420BC0(void *);
extern void __cdecl FUN_00422410(void *);
extern void __cdecl FUN_00420960(void *);
extern void __cdecl FUN_004252E0(void *);
void __cdecl InitPlayerJumpSwallow_00425460(int *object)
{
    FUN_00420BC0(object);
    object[0x15] = 0;
    object[0x26] = 0;
    object[0x1c] = 0x13;
    object[0x14] = 0x3a;
    FUN_00422410(object);
    FUN_00420960(object);
    FUN_004252E0(object);
}
}
