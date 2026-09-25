extern "C" int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int, int);

extern "C" int __cdecl GEX_Target(int param_1, int param_2)
{
    int iVar2 = 0;
    int iVar1 = 0;
    int SelectedTV = FUN_00429cb0_RemoteTVSelect_Unk1(0, *(int *)(param_1 + 0x9c) + 1);
    if (0 < *(int *)(param_1 + 0xb4)) {
        do {
            iVar1 = iVar1 + 1;
            if (SelectedTV == param_2) {
                return iVar1;
            }
            SelectedTV = FUN_00429cb0_RemoteTVSelect_Unk1((iVar2 = iVar2 + 1, SelectedTV), 1);
        } while (iVar2 < *(int *)(param_1 + 0xb4));
    }
    return 0;
}
