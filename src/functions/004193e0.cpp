extern "C" int DAT_0049FB90;

extern "C" int __cdecl SCRIPT_GetParentIndex_004193e0(int value, int **objects)
{
    if (objects[87] != 0)
        DAT_0049FB90 = objects[87][21];
    else
        DAT_0049FB90 = -1;
    return value;
}
