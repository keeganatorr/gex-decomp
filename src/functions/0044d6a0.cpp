struct _LDOUBLE {
    unsigned int low;
    unsigned int mid;
    unsigned int high;
};

struct _FLT {
    short exp;
    char sign;
    char pad;
    char digits[28];
};

struct _FLTOUT {
    int sign;
    int exp;
    int ndigits;
    char *digits;
};

struct _FLT_DATA {
    struct _FLT flt;
    struct _FLTOUT out;
};

extern "C" {
    void ___dtold(struct _LDOUBLE *pld, double *pd);
    int $I10_OUTPUT(struct _LDOUBLE ld, int ndigits, int flags, void *buf);
    extern struct _FLT_DATA DAT_0047eef0;

    void *GEX_Target(double x)
    {
        struct _LDOUBLE ld;
        ___dtold(&ld, &x);
        DAT_0047eef0.out.ndigits = $I10_OUTPUT(ld, 0x11, 0, &DAT_0047eef0.flt);
        DAT_0047eef0.out.digits = DAT_0047eef0.flt.digits;
        DAT_0047eef0.out.sign = DAT_0047eef0.flt.sign;
        DAT_0047eef0.out.exp = DAT_0047eef0.flt.exp;
        return &DAT_0047eef0.out;
    }
}
