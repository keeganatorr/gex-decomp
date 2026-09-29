extern "C" {
void __cdecl EnemyInitPath_00434a20(int *object)
{
    if (object[0x29] != 0) {
        object[0x2a] = object[0x29] + 4;
        object[0x2d] &= 0xfffffff7;
    }
}
}
