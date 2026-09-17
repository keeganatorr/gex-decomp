extern "C" {
extern int DAT_004a2844;
extern int DAT_004a2834;
extern void InitPlayerGoThruTube_00415b20(int *);
}

extern "C" void GEX_Target(int *param_1)
{
    switch (param_1[0x26]) {
    case 0:
        param_1[0x1e] = DAT_004a2844;
        param_1[0x1f] = DAT_004a2834;
        param_1[0x32] = 0xc000;
        param_1[0x33] = 0xc000;
        param_1[0x26]++;
        break;

    case 1:
        InitPlayerGoThruTube_00415b20(param_1);
        break;
    }
}
