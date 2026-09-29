extern "C" unsigned int randomState_00463aec;
// Nonzero bound is a caller precondition: original code also divides by zero for bound=0.
extern "C" int __cdecl UTL_ReallyRandom_00428c80(int bound)
{
    unsigned short bits;
    for (bits = (unsigned short)bound; bits; bits >>= 1)
    {
        if ((int)randomState_00463aec > 0)
            randomState_00463aec *= 2;
        else
            randomState_00463aec = randomState_00463aec * 2 ^ 0x1d872b41u;
    }
    return (int)(randomState_00463aec & 0x7fffffffu) % bound;
}
