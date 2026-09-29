extern "C" {
extern int DAT_0045F440[];

int __cdecl FUN_00439130_KFInner(int param_1, int param_2)
{
    int idx = ((param_2 >> 16) * 17) + (param_1 >> 16);
    int val = DAT_0045F440[idx];

    if ((val + 0x40) > 0xff) {
        return (val - 0xc0) << 16;
    }

    return (val + 0x40) << 16;
}
}
