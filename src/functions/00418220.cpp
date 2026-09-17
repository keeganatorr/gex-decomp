extern "C" int DAT_0049fb90;
extern "C" int *DAT_004a27fc;

extern "C" int __cdecl GEX_Target(int param1, int *param2)
{
    int pGVar2;
    int pGVar1;

    pGVar2 = param2[0x57];
    if (pGVar2 == 0) {
        pGVar2 = param2[0x1e];
    } else {
        pGVar1 = *(int *)(pGVar2 + 0x15c);
        while (pGVar1 != 0) {
            pGVar2 = *(int *)(pGVar2 + 0x15c);
            pGVar1 = *(int *)(pGVar2 + 0x15c);
        }
        pGVar2 = *(int *)(pGVar2 + 0x78);
    }
    DAT_0049fb90 = DAT_004a27fc[0x1e] - pGVar2;
    return param1;
}
