// Adapted from pc_decomp_backup/src/functions/FUN_0041E930.cpp
// Historical source SHA256: 86824e1aa9b9a6a62ed24d5b37c974b468c1031866d4d5cc2de0a185ff10e28d
extern "C" {
extern "C" void __cdecl FUN_0041E8B0(void***, int);
extern "C" void __cdecl GEX_Target(void)
{
    int list = 0;
    for (void*** head = (void***)0x00463698;
         head < (void***)0x0046371D;
         head += 3, ++list)
        FUN_0041E8B0(head, list);
    FUN_0041E8B0((void***)0x00463680, -1);
}
}
