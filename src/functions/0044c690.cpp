extern "C" void FUN_0044e7e0(void);
extern "C" char DAT_00461138;
extern "C" void __fcloseall(void);

extern "C" void FUN_0044C690(void)
{
    FUN_0044e7e0();
    char *p = &DAT_00461138;
    if (*p != 0) {
        __fcloseall();
    }
}
