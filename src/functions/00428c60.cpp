extern "C" unsigned int randomState_00463af0;
// Signed positivity selects feedback; unsigned arithmetic preserves 32-bit wraparound.
extern "C" unsigned int __cdecl UTL_ReallyRandom32_00428c60()
{
    if ((int)randomState_00463af0 > 0)
        randomState_00463af0 *= 2;
    else
        randomState_00463af0 = randomState_00463af0 * 2 ^ 0x1d872b41u;
    return randomState_00463af0;
}
