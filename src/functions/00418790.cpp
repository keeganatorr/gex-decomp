// Adapted from pc_decomp_backup/src/functions/FUN_00418790.cpp
// Historical source SHA256: b96438cb7423910a6efbc291932723424618f4e98ba6a4ba8271436ce0613691
extern "C" {
extern "C" { extern int DAT_0049FB90; }

extern "C" int __cdecl GEX_Target(int param_1, void** param_2)
{
    void* obj = param_2[0x5e];
    if (obj) {
        DAT_0049FB90 = *(int*)obj;
    } else {
        DAT_0049FB90 = -1;
    }
    return param_1;
}
}
