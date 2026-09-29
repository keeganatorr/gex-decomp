typedef struct _LDBL12 {
    unsigned int data[3];
} _LDBL12;

typedef double _CRT_DOUBLE;

extern "C" int __cdecl __strgtold12(_LDBL12 *, char **, const char *, int, int, int, int);
extern "C" int __cdecl _ld12tod(_LDBL12 *, _CRT_DOUBLE *);

extern "C" int __cdecl __atodbl_0044cb50(_CRT_DOUBLE *_Result, char *_Str)
{
    char *local_10;
    _LDBL12 local_c;
    __strgtold12(&local_c, &local_10, _Str, 0, 0, 0, 0);
    return _ld12tod(&local_c, _Result);
}
