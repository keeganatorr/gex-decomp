extern "C" int DAT_0049FB90;

extern "C" int __cdecl SCRIPT_GetCLIDObjType_00418790(int param_1, void** param_2)
{
    void* obj = param_2[0x5e];
    if (obj != 0) {
        DAT_0049FB90 = *(int*)((char*)obj + 8);
        return param_1;
    }
    DAT_0049FB90 = -1;
    return param_1;
}
