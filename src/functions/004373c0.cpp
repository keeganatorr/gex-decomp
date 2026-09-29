extern "C" {
extern int DAT_0045C998;

int __cdecl FUN_004373c0_KFInner(int param_1)
{
    if (DAT_0045C998 == 1) {
        return ((200 - param_1) * param_1 * 4) / 1000;
    }
    if (DAT_0045C998 == 3) {
        return ((180 - param_1) * param_1) / 45 + ((param_1 - 150) * param_1 * 4) / 270;
    }
    if (DAT_0045C998 == 2) {
        int first = ((140 - param_1) * param_1) / 120;
        param_1 = (param_1 - 180) * param_1;
        param_1 /= 70;
        return param_1 + first;
    }
    if (DAT_0045C998 == 4) {
        int first = ((50 - param_1) * param_1 * 2) / 500;
        param_1 = (100 - param_1) * param_1;
        param_1 *= 6;
        param_1 /= 250;
        return param_1 + first;
    }
    return 0;
}
}
