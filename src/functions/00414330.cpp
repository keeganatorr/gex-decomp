extern "C" {
extern void __cdecl FUN_00426CA0(void *);
void __cdecl GEX_Target(int *object)
{
    object[0x26] += 1;
    if (object[0x26] >= 1) {
        if (object[0x15] == 3) {
            FUN_00426CA0(object);
            return;
        }
        object[0x26] = 0;
        object[0x15] += 1;
    }
}
}
