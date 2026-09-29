typedef unsigned int uint;
extern "C" {
extern uint __cdecl FUN_00417F40(uint **cursor);
extern void __cdecl FUN_0041A360(uint, int);
uint *__cdecl SCRIPT_PlaySoundNoPosition_00418b80(uint *cursor)
{
    uint sound = FUN_00417F40(&cursor);
    int volume = *(unsigned char *)cursor;
    cursor = (uint *)((char *)cursor + 1);
    FUN_0041A360(sound, volume >> 1);
    return cursor;
}
}
