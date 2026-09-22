extern "C" int DAT_004a2824;
extern "C" int DAT_004a2834;
extern "C" int DAT_004a2844;
extern "C" int DAT_004a285c;
extern "C" unsigned int DAT_00457210[];
extern "C" int __cdecl abs(int);

extern "C" void __cdecl GEX_Target(int *param_1)
{
    int *base = param_1;
    int pGVar1;
    int pGVar2;
    int distance;
    int divisor;
    int correction;

    if (DAT_004a2824 != 0) {
        distance = abs(DAT_004a2844 - base[0x1e]) - 0xa0000;
        if (distance <= 0) {
            distance = 0;
        }

        pGVar1 = base[0x1f];
        divisor = DAT_004a2834 - pGVar1;
        if (divisor < 0) {
            divisor -= distance;
            if (divisor >= -1) {
                divisor = -1;
            }
        } else {
            divisor += distance;
            if (divisor <= 1) {
                divisor = 1;
            }
        }

        if (divisor >= 0x300000) {
            divisor = 0x300000;
        }
        if (divisor <= -0x300000) {
            divisor = -0x300000;
        }

        divisor >>= 16;
        if (divisor == 0) {
            divisor = 1;
        }

        pGVar2 = base[0x23];
        if ((pGVar2 >= 0x40000) || ((correction = 0), (pGVar2 <= 0))) {
            correction = ((int)((unsigned int)pGVar2 & 0xffffff0fU)) >> 4;
        }

        if (DAT_004a285c != 0) {
            if ((DAT_00457210[base[0x1c]] & 0x20U) != 0) {
                base[0x23] = pGVar2 + (0x280000 / divisor + correction);
                return;
            }
            base[0x1f] = pGVar1 + 0x280000 / divisor;
            return;
        }

        if ((DAT_00457210[base[0x1c]] & 0x20U) != 0) {
            base[0x23] = pGVar2 + (-0x280000 / divisor - correction);
            return;
        }
        base[0x1f] = pGVar1 + -0x280000 / divisor;
    }
}
