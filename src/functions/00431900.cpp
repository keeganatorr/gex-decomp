extern "C" int FUN_0041a090(void*);
extern "C" void FUN_00431830(void*, int, int);
extern "C" int DAT_0045b150;
extern "C" int DAT_00463fe0;

extern "C" int __cdecl GEX_Target(void* pv)
{
    if (FUN_0041a090(pv) != 0)
        return 1;

    int* p = (int*)pv;
    if (p[0x28] > 0) {
        int c = p[0x28] - 1;
        int yv = ((volatile int*)p)[0x23];
        p[0x28] = c;
        FUN_00431830(p,
            p[0x1e] - p[0x20] * DAT_0045b150,
            p[0x1f] - yv * DAT_0045b150);
        if (DAT_00463fe0 != 0)
            return 1;
    }

    FUN_00431830(p, p[0x1e], p[0x1f]);
    return DAT_00463fe0 != 0;
}
