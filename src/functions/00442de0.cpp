// Adapted from pc_decomp_backup/src/functions/FUN_00442DE0.cpp
// Historical source SHA256: 42ed66ccb29f3919c912d77e79fe67c3825c24f179efefee45b9eccc42c6e272
extern "C" {
extern "C" int __cdecl GEX_Target(unsigned int param_1, unsigned int param_2)
{
    int s1 = (int)param_1 >> 31;
    int s2 = (int)param_2 >> 31;
    unsigned int a1 = (param_1 ^ s1) - s1;   
    unsigned int a2 = (param_2 ^ s2) - s2;   
    unsigned int a1_lo = a1 & 0xffff;
    unsigned int a2_lo = a2 & 0xffff;
    int a1_hi = (int)a1 >> 16;
    int a2_hi = (int)a2 >> 16;
    unsigned int a2_hicarry = a2 & 0xffff0000;
    int result = (int)((a2_hicarry + a2_lo) * a1_hi) + a2_hi * (int)a1_lo + (int)((a2_lo * a1_lo) >> 16);
    if (((int)param_2 > 0) != ((int)param_1 > 0)) {
        result = -result;
    }
    return result;
}
}
