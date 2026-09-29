extern "C" void __cdecl FUN_0041E8B0(void***, int);

extern "C" void __cdecl CLD_RemoveAllCldObjsFromList_0041e930(void)
{
    int list = 0;
    void*** head = (void***)0x00463698;
    for (; head <= (void***)0x0046371C; head += 3, ++list)
        FUN_0041E8B0(head, list);
    FUN_0041E8B0((void***)0x00463680, -1);
}