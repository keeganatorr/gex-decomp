typedef unsigned int uint;
extern "C" {
extern uint __cdecl FUN_00417F40(uint **cursor);
extern void __cdecl FUN_0041A360(uint, int);
uint *__cdecl GEX_Target(uint *cursor)
{
    uint sound = FUN_00417F40(&cursor);
    uint volume = *cursor;
    cursor = (uint *)((char *)cursor + 1);
    FUN_0041A360(sound, (int)(unsigned char)volume >> 1);
    return cursor;
}
}
