extern "C" int DAT_0049FB90;

extern "C" int __cdecl GEX_Target(int value, int **objects)
{
    if (objects[87] != 0)
        DAT_0049FB90 = objects[87][21];
    else
        DAT_0049FB90 = -1;
    return value;
}
