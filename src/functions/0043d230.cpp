extern "C" int __cdecl FUN_0040FCE0(int*);
extern "C" void __cdecl FUN_00434260(int*);

extern "C" void __cdecl ob120DoIt_0043d230(int* p)
{
    p[0x35] = p[0x1e];
    p[0x36] = p[0x1f];
    p[0x3f] = p[0x1b];
    p[0x3d] = p[0x14];
    p[0x3e] = p[0x15];
    p[0x39] = 0;
    p[0x3a] = 0;
    p[0x3b] = 0;
    p[0x3c] = 0;
    p[0x38] = (((unsigned int)p[0x38] * 2 ^ (unsigned int)p[0x38]) & 0x200) ^ (unsigned int)p[0x38];
    p[0x38] &= 0xfffffeff;

    if (FUN_0040FCE0(p) == 0) {
        if (p[0x29] != 0)
            FUN_00434260(p);
        if (p[0x26] != 0) {
            int value = p[0x26] + p[0x23];
            p[0x23] = value;
            if (value >= 0x10000) {
                p[0x23] = value - 0x10000;
                p[0x15] = p[0x15] + 1;
            }
        }
    }
    if (p[0x45] == -1)
        p[0x44] = 0;
    p[0x45] = -1;
}
