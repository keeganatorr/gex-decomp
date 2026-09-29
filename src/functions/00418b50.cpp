typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned int uint;

extern "C" {
extern uint __cdecl FUN_00417F40(uint **cursor);
extern void __cdecl FUN_0041A320(void *, uint, int);

ushort *__cdecl SCRIPT_PlaySoundWithVolume_00418b50(ushort *cursor, void *object)
{
    uint sound = FUN_00417F40((uint **)&cursor);
    int volume = *(uchar *)cursor;
    cursor = (ushort *)((char *)cursor + 1);
    FUN_0041A320(object, sound, volume >> 1);
    return cursor;
}
}
