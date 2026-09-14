typedef unsigned short ushort;
typedef unsigned int uint;
extern "C" {
extern uint __cdecl FUN_00417F40(uint **cursor);
extern void __cdecl FUN_0041A320(void *, uint, int);
ushort *__cdecl GEX_Target(ushort *cursor, void *object)
{
    uint sound = FUN_00417F40((uint **)&cursor);
    ushort volume = *cursor;
    cursor = (ushort *)((char *)cursor + 1);
    FUN_0041A320(object, sound, (int)(unsigned char)volume >> 1);
    return cursor;
}
}
