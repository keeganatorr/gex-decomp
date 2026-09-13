// Adapted from pc_decomp_backup/src/functions/FUN_0041FBA0.cpp
// Historical source SHA256: 17191045b767d2c99f3ea431b025bbb3ba9f4958988fa2456512cd28b7abe716
extern "C" {
extern "C" { extern unsigned int DAT_004639DC; }
extern "C" { extern unsigned int DAT_004A02D0; }

extern "C" unsigned int __cdecl GEX_Target()
{
    unsigned int a, b, result;
    a = DAT_004639DC;
    b = DAT_004A02D0;
    result = (a == b) ? 1 : 0;
    return result;
}
}
