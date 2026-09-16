extern "C" int _ld12cvt(void *, void *, int *);
extern "C" int GEX_Target(void *ifp, void *d) {
    return _ld12cvt(ifp, d, (int *)0x461a00);
}