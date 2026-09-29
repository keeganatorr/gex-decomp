typedef struct { float f; } _CRT_FLOAT;
typedef struct { unsigned char b[12]; } _LDBL12;

extern "C" {
int __cdecl __strgtold12(_LDBL12 *pld, char **pEndPtr, char *str, int a, int b, int c, int d);
int __cdecl _ld12tof(_LDBL12 *pld, _CRT_FLOAT *pResult);
}

extern "C" int __cdecl __atodbl_0044cb90(_CRT_FLOAT *_Result, char *_Str)
{
    char *local_10;
    _LDBL12 local_c;

    __strgtold12(&local_c, &local_10, _Str, 0, 0, 0, 0);
    return _ld12tof(&local_c, _Result);
}
