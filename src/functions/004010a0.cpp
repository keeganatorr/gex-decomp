typedef unsigned long DWORD;
typedef long HRESULT;
typedef void* HWND;
typedef int BOOL;

struct IDirectDraw;

struct IDirectDrawVtbl {
    HRESULT (__stdcall *QueryInterface)(IDirectDraw*, const void*, void**);
    unsigned long (__stdcall *AddRef)(IDirectDraw*);
    unsigned long (__stdcall *Release)(IDirectDraw*);
    HRESULT (__stdcall *Compact)(IDirectDraw*);
    HRESULT (__stdcall *CreateClipper)(IDirectDraw*, DWORD, void**, void*);
    HRESULT (__stdcall *CreatePalette)(IDirectDraw*, DWORD, void*, void**, void*);
    HRESULT (__stdcall *CreateSurface)(IDirectDraw*, void*, void**, void*);
    HRESULT (__stdcall *DuplicateSurface)(IDirectDraw*, void*, void**);
    HRESULT (__stdcall *EnumDisplayModes)(IDirectDraw*, DWORD, void*, void*, void*);
    HRESULT (__stdcall *EnumSurfaces)(IDirectDraw*, DWORD, void*, void*, void*);
    HRESULT (__stdcall *FlipToGDISurface)(IDirectDraw*);
    HRESULT (__stdcall *GetCaps)(IDirectDraw*, void*, void*);
    HRESULT (__stdcall *GetDisplayMode)(IDirectDraw*, void*);
    HRESULT (__stdcall *GetFourCCCodes)(IDirectDraw*, DWORD*, DWORD*);
    HRESULT (__stdcall *GetGDISurface)(IDirectDraw*, void**);
    HRESULT (__stdcall *GetMonitorFrequency)(IDirectDraw*, DWORD*);
    HRESULT (__stdcall *GetScanLine)(IDirectDraw*, DWORD*);
    HRESULT (__stdcall *GetVerticalBlankStatus)(IDirectDraw*, BOOL*);
    HRESULT (__stdcall *Initialize)(IDirectDraw*, void*);
    HRESULT (__stdcall *RestoreDisplayMode)(IDirectDraw*);
    HRESULT (__stdcall *SetCooperativeLevel)(IDirectDraw*, HWND, DWORD);
};

struct IDirectDraw {
    IDirectDrawVtbl* lpVtbl;
};

extern "C" {
    extern IDirectDraw* gDirectDraw_00451030;
    extern HWND gMainWindow_004875a0;
    extern DWORD gScreenDisplayMode_00454fc8;
    extern DWORD DAT_0049fb8c_CurrentBPPType;
    HRESULT __stdcall DirectDrawCreate_00409876(void*, IDirectDraw**, void*);
    DWORD DDRAW_GetDisplayMode_00401000(void);

    int DDRAW_Create_004010a0(void)
    {
        HRESULT directDrawCreateResult;
        DWORD mode;
        directDrawCreateResult = DirectDrawCreate_00409876(0, &gDirectDraw_00451030, 0);
        if (directDrawCreateResult != 0) {
            return 0;
        }
        gDirectDraw_00451030->lpVtbl->SetCooperativeLevel(gDirectDraw_00451030, gMainWindow_004875a0, 8);
        mode = DDRAW_GetDisplayMode_00401000();
        gScreenDisplayMode_00454fc8 = mode;
        DAT_0049fb8c_CurrentBPPType = mode;
        return 1;
    }
}
