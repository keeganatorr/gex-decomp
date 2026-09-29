// The original forwards the SECOND stack argument and then returns the first.
// EditedGex's callee signature hides that forwarded argument because it is unused.
extern "C" {
extern void __cdecl FUN_00417CA0(void *);
unsigned char *__cdecl SCRIPT_KillPlayer_00419040(unsigned char *cursor, void *object)
{
    FUN_00417CA0(object);
    return cursor;
}
}
