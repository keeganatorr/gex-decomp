typedef unsigned int uint;
extern "C" {
void __cdecl FUN_004208f0_ypos(int *object, int *source)
{
    object[0x1f] += 0x200000 - ((uint)source[8] & 0x1fffff);
}
}
