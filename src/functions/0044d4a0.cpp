extern "C" unsigned int __cdecl _control87(unsigned int, unsigned int);

extern "C" unsigned int __cdecl __controlfp(unsigned int newValue, unsigned int mask)
{
    return _control87(newValue, mask & 0xfff7ffff);
}
