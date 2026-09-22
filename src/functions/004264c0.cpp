extern "C" {
extern int DAT_00463AA8;
extern int DAT_004A022C;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0282;
extern unsigned char DAT_004A0283;

void __cdecl FUN_00423800_pStateUnk(int *);
int __cdecl FUN_00423910(int *);
int __cdecl FUN_00423960(int *);
int __cdecl FUN_004239B0(int *);
int __cdecl FUN_00423A00(int *);
int __cdecl FUN_00423A50(int *);
void __cdecl FUN_004144E0(int *);
void __cdecl FUN_00426CA0(int *);

void __cdecl GEX_Target(int *state)
{
    FUN_00423800_pStateUnk(state);
    if (state[0x26] == 0) {
        if (DAT_004A0281 != 0)
            DAT_00463AA8 = 0x400000;
        else if (DAT_004A0280 != 0)
            DAT_00463AA8 = 0xc00000;
        else if (DAT_004A0283 != 0)
            DAT_00463AA8 = 0x800000;
        else if (DAT_004A0282 != 0)
            DAT_00463AA8 = 0;
    }

    int delta = DAT_00463AA8 - state[0x31];
    int sign = delta < 0 ? -1 : 0;
    int amount = (delta ^ sign) - sign;
    if (amount > 0x800000)
        delta = -delta;
    if (amount >= 0x100000)
        amount = 0x100000;
    if (delta > 0)
        state[0x31] += amount;
    else
        state[0x31] -= amount;
    state[0x31] &= 0xff0000;

    if (FUN_00423910(state) == 0)
        state[0x1e] += 0x40000;
    if (FUN_00423960(state) == 0)
        state[0x1e] -= 0x40000;
    if (FUN_004239B0(state) == 0)
        state[0x1f] += 0x40000;
    if (FUN_00423A00(state) == 0)
        state[0x1f] -= 0x40000;

    if ((state[0x31] & 0x3f0000) == 0) {
        if (FUN_00423A50(state) == 0)
            FUN_004144E0(state);
    }
    if (state[0x31] == DAT_00463AA8)
        FUN_00426CA0(state);
    DAT_004A022C = 1;
}
}
