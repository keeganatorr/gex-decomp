extern "C" {
extern void __cdecl FUN_00411160(void *);
void __cdecl GEX_Target(int *object)
{
    object[0x26] += 1;
    if (object[0x26] >= 1) {
        if (object[0x15] == 4) {
            FUN_00411160(object);
            return;
        }
        object[0x26] = 0;
        object[0x15] += 1;
    }
}
}
