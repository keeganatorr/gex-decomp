extern "C" {
typedef int (__cdecl * _PNH)(unsigned int);
extern _PNH DAT_0047ef20;

int __cdecl GEX_Target(unsigned int _Size)
{
    _PNH pnh = DAT_0047ef20;
    if (pnh != 0) {
        if ((*pnh)(_Size)) {
            return 1;
        }
    }
    return 0;
}
}
