extern "C" {
extern void __cdecl FUN_00419840(void *);
void __cdecl FUN_0043b510_Call_Events_GT9(int *object)
{
    object[0x2c] -= 1;
    if (object[0x2c] <= 0) {
        object[0x2c] = 3;
        object[0x15] += 1;
        if (object[0x15] > 9)
            FUN_00419840(object);
    }
}
}
