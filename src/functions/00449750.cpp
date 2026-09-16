extern "C" void (__cdecl *PTR___fpmath_00461160)(void);
extern "C" int __cdecl __initterm(void**, void**);

extern "C" int __cdecl GEX_Target(int)
{
    if (PTR___fpmath_00461160 != 0) {
        PTR___fpmath_00461160();
    }
    __initterm((void**)0x451008, (void**)0x451010);
    return __initterm((void**)0x451000, (void**)0x451004);
}
