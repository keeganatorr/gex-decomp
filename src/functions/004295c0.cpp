// Adapted from pc_decomp_backup/src/functions/FUN_004295C0.cpp
// Historical source SHA256: ac77d10ee8dc613792ad5f955316a1364c4254f4774ad1f7dac5b658c32dfbb8
extern "C" {
extern "C" { extern const char DAT_0045ABD8[]; }

extern "C" int __cdecl GEX_Target(const char* param_1)
{
    int i;
    int v;
    int len;

    for (i = 0; i < 8; i++) {
        v = 0;
        while (v < 16 && DAT_0045ABD8[v] != param_1[i]) v++;
        if (v == 16) return 0;
    }

    len = 0;
    while (param_1[len] != 0) len++;
    if (len < 8) return 0;

    {
        int sum = 0;
        int pos;
        for (pos = 2; pos < len; pos++) {
            sum += (unsigned char)param_1[pos];
        }
        if (DAT_0045ABD8[sum & 0xf] == param_1[0] && 
            DAT_0045ABD8[(sum & 0xf0) >> 4] == param_1[1]) {
            return 1;
        }
    }
    return 0;
}
}
