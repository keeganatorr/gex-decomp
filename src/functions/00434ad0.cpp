// FUN_00434ad0
extern "C" void __cdecl FUN_00434a60(void** param_1, void* param_2);
extern "C" void __cdecl GOB_KeepOutOfTiles_00420960(void* param_2);
extern "C" void __cdecl PlayerKill_00417ca0(void** param_1);

extern "C" void __cdecl GEX_Target(void** param_1, void* param_2)
{
    if (((unsigned int)param_1[0x2d] & 0x10000u) != 0) {
        FUN_00434a60(param_1, param_2);
        return;
    }
    GOB_KeepOutOfTiles_00420960(param_2);
    PlayerKill_00417ca0(param_1);
}
