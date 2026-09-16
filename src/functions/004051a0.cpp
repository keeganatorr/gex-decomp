extern "C" {
    __declspec(dllimport) int __stdcall GetUpdateRect(void* hWnd, void* lpRect, int bErase);
    __declspec(dllimport) int __stdcall UpdateWindow(void* hWnd);
    extern void* DAT_004875A0;
    void FUN_00405450(void);
    void FUN_00406C30(void);
}

extern "C" void GEX_Target(void)
{
    if (GetUpdateRect(DAT_004875A0, 0, 0)) {
        UpdateWindow(DAT_004875A0);
        FUN_00405450();
        FUN_00406C30();
    }
}
