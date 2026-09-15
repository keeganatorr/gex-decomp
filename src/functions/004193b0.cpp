extern "C" int DAT_0049FB90;

extern "C" int __cdecl GEX_Target(int value, int **objects)
{
    int *group = objects[87];
    if (group != 0) {
        DAT_0049FB90 = group[20];
        return value;
    }
    DAT_0049FB90 = -1;
    return value;
}
