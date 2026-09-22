struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

struct tagPOINT {
    int x;
    int y;
};

struct tagWINDOWPLACEMENT {
    unsigned int length;
    unsigned int flags;
    unsigned int showCmd;
    tagPOINT ptMinPosition;
    tagPOINT ptMaxPosition;
    tagRECT rcNormalPosition;
};

extern "C" {
    extern int DAT_0045103C;
    extern void* DAT_004875A0;
    extern int DAT_00487768_ScreenWidth;

    void FUN_004013E0(int mode);
    void* __cdecl memset(void* destination, int value, unsigned int count);

    __declspec(dllimport) void __stdcall AdjustWindowRect(tagRECT* lpRect, unsigned long dwStyle, int bMenu);
    __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);
    __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl);
    __declspec(dllimport) int __stdcall SetWindowPlacement(void* hWnd, const tagWINDOWPLACEMENT* lpwndpl);

    void GEX_Target(int width, int height)
    {
        tagRECT rect;
        void* handle;
        int cx;
        int cy;
        int metric;

        if (DAT_0045103C != 0) {
            FUN_004013E0(0);
        }

        rect.left = 0;
        rect.top = 0;
        rect.right = width;
        rect.bottom = height;
        AdjustWindowRect(&rect, 0xcf0000, 1);

        cx = rect.right - rect.left;
        cy = rect.bottom - rect.top;

        tagWINDOWPLACEMENT wp;
        memset(&wp, 0, sizeof(wp));

        wp.length = 0x2c;
        GetWindowPlacement(DAT_004875A0, &wp);

        wp.rcNormalPosition.left = (GetSystemMetrics(0) - cx) / 2;
        wp.rcNormalPosition.left = ((wp.rcNormalPosition.left + 2) & 0xfffffffc) - DAT_00487768_ScreenWidth;

        metric = GetSystemMetrics(1);
        metric = (metric - cy) / 2;
        cx += wp.rcNormalPosition.left;
        cy += metric;

        SetWindowPlacement(
            (handle = *(void* volatile*)&DAT_004875A0,
             wp.rcNormalPosition.top = metric,
             wp.rcNormalPosition.right = cx,
             wp.showCmd = 1,
             wp.rcNormalPosition.bottom = cy,
             handle),
            &wp);
    }
}
