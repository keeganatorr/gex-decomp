typedef void *HWND;
typedef int BOOL;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef long LONG;

struct POINT {
    LONG x;
    LONG y;
};

struct RECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

struct PAINTSTRUCT {
    void *hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    unsigned char rgbReserved[32];
};

struct MINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
};

struct WINDOWPOS {
    HWND hwnd;
    HWND hwndInsertAfter;
    int x;
    int y;
    int cx;
    int cy;
    UINT flags;
};

extern "C" __declspec(dllimport) void * __stdcall BeginPaint(HWND, PAINTSTRUCT *);
extern "C" __declspec(dllimport) BOOL __stdcall EndPaint(HWND, const PAINTSTRUCT *);
extern "C" __declspec(dllimport) LRESULT __stdcall DefWindowProcA(HWND, UINT, WPARAM, LPARAM);
extern "C" __declspec(dllimport) BOOL __stdcall AdjustWindowRect(RECT *, unsigned long, BOOL);
extern "C" __declspec(dllimport) BOOL __stdcall GetClientRect(HWND, RECT *);
extern "C" __declspec(dllimport) BOOL __stdcall ScreenToClient(HWND, POINT *);
extern "C" __declspec(dllimport) BOOL __stdcall PtInRect(const RECT *, POINT);

extern "C" void VRAM_Hide_00405810(void);
extern "C" int DAT_00487F88;
extern "C" int DAT_00487768_ScreenWidth;
extern "C" HWND gDebugVRAMWindow_0048750c;

extern "C" __declspec(dllexport) LRESULT __stdcall DebugVramWndProc_00404230(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT paint;
    POINT point;
    RECT rect;

    switch (message) {
    case 0x000f:
        BeginPaint(hwnd, &paint);
        EndPaint(hwnd, &paint);
        return 0;

    case 0x0010:
        VRAM_Hide_00405810();
        return 0;

    case 0x0014:
        if (DAT_00487F88 != 0)
            return 1;
        break;

    case 0x0024:
        {
            MINMAXINFO *info = (MINMAXINFO *)lParam;
            rect.left = 0;
            rect.top = 0;
            rect.right = 0x400;
            rect.bottom = 0x200;
            AdjustWindowRect(&rect, 0x00cf0000UL, 0);
            info->ptMaxSize.x = rect.right - rect.left;
            info->ptMaxSize.y = rect.bottom - rect.top;
            info->ptMaxTrackSize.x = rect.right - rect.left;
            info->ptMaxTrackSize.y = rect.bottom - rect.top;
            return 1;
        }

    case 0x0046:
        {
            WINDOWPOS *position = (WINDOWPOS *)lParam;
            position->x = ((position->x + 4U) & 0xfffffff8U) - DAT_00487768_ScreenWidth;
            return 0;
        }

    case 0x0084:
        GetClientRect(gDebugVRAMWindow_0048750c, &rect);
        point.x = lParam & 0xffffL;
        point.y = (lParam >> 16) & 0xffffL;
        ScreenToClient(gDebugVRAMWindow_0048750c, &point);
        if (PtInRect(&rect, point) != 0)
            return 2;
        break;

    case 0x030f:
        return 0;

    case 0x0311:
        return 0;
    }

    return DefWindowProcA(hwnd, message, wParam, lParam);
}
