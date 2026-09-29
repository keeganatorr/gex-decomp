extern "C" void __cdecl FUN_00449aa0_fpMathInner(void);
extern "C" unsigned int __cdecl _ms_p5_mp_test_fdiv(void);
extern "C" void __cdecl __setdefaultprecision(void);
extern "C" unsigned int __cdecl _clearfp(void);

extern "C" void __cdecl __fpmath(int)
{
    FUN_00449aa0_fpMathInner();
    *(unsigned int *)0x0046115c = _ms_p5_mp_test_fdiv();
    __setdefaultprecision();
    _clearfp();
}
