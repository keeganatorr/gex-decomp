extern "C" {
extern int DAT_00464278;
extern void** DAT_004642A0;
void __cdecl FUN_00405390(const char*, ...);
void* __cdecl FUN_00435D90(void**, void*, void*);
extern const char* DAT_0045B57C[];
extern const char DAT_0045B5F0[];

void* __cdecl GEX_Target(void** param_1, void* param_2, void* PointerToScript, int eventNumber)
{
    if (DAT_00464278 == 0)
        goto tail;
    if (param_1[2] != (void*)DAT_004642A0)
        goto tail;
    FUN_00405390(DAT_0045B5F0, DAT_0045B57C[eventNumber], PointerToScript);
tail:
    return FUN_00435D90(param_1, param_2, PointerToScript);
}
}
