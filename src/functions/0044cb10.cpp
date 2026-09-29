extern "C" int _ld12cvt(void *, void *, int *);
extern "C" int __ld12tod(void *ifp, void *d) {
    return _ld12cvt(ifp, d, (int *)0x461a00);
}