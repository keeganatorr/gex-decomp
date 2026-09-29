extern "C" {
extern int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int, int);
int __cdecl FUN_0042a5d0_RemoteUnk(int *remote, int tv)
{
    int i, n = 0;
    int selected = FUN_00429cb0_RemoteTVSelect_Unk1(0, remote[0x9c / 4] + 1);
    for (i = 0; i < remote[0xb4 / 4]; i++) {
        n++;
        if (selected == tv)
            return n;
        selected = FUN_00429cb0_RemoteTVSelect_Unk1(selected, 1);
    }
    return 0;
}
}
