typedef long (__stdcall *DDrawEntry)();
struct DirectDraw {
    DDrawEntry *lpVtbl;
};
typedef long (__stdcall *RestoreModeFn)(DirectDraw *);
typedef long (__stdcall *CooperativeLevelFn)(DirectDraw *, void *, unsigned long);
typedef long (__stdcall *DisplayModeFn)(DirectDraw *, unsigned long, unsigned long, unsigned long);

extern "C" {
__declspec(dllimport) void * __stdcall SelectObject(void *, void *);
int __cdecl DDRAW_GetDisplayMode_00401000(void);
extern int DAT_0049fb8c_CurrentBPPType;
extern void *HGDIOBJ_004870d0;
extern void *ghDC_0047f0c8;
extern void *HBITMAP_004870d4;
extern void *ghDIBSection_0047f0c4;
extern void *HBITMAP_00487508;
extern void *gMainWindow_004875a0;
extern DirectDraw *gDirectDraw_00451030;
extern int gScreenDisplayMode_00454fc8;
extern int gScreenResolution_00451038;
}

extern "C" int __cdecl DDRAW_SetResolution_00401100(int resolutionCode, int isFullscreen)
{
    long result;
    int previousBpp;

    if (((unsigned int)resolutionCode - (unsigned int)gScreenResolution_00451038) == 0) {
        if (isFullscreen == 0 && gScreenDisplayMode_00454fc8 == 8)
            return 1;
        if (isFullscreen != 0 && gScreenDisplayMode_00454fc8 > 8)
            return 1;
    }

    result = ((CooperativeLevelFn)gDirectDraw_00451030->lpVtbl[20])
        (gDirectDraw_00451030, gMainWindow_004875a0, 0x13);
    if (result == 0) {
        if (isFullscreen != 0) {
            if (resolutionCode == 0x320240 &&
                ((unsigned int)resolutionCode - (unsigned int)gScreenResolution_00451038) != 0) {
                result = ((DisplayModeFn)gDirectDraw_00451030->lpVtbl[21])
                    (gDirectDraw_00451030, 320, 240, 16);
                if (result != 0)
                    resolutionCode = 0x640480;
            }
            if (resolutionCode == 0x640480) {
                result = ((DisplayModeFn)gDirectDraw_00451030->lpVtbl[21])
                    (gDirectDraw_00451030, 640, 480, 16);
            }
        } else {
            if (resolutionCode == 0x640480 || resolutionCode == 0x320240) {
                resolutionCode = 0x640480;
                result = ((DisplayModeFn)gDirectDraw_00451030->lpVtbl[21])
                    (gDirectDraw_00451030, 640, 480, 8);
            }
        }

        if (resolutionCode == 0) {
            result = ((RestoreModeFn)gDirectDraw_00451030->lpVtbl[19])
                (gDirectDraw_00451030);
        }

        ((CooperativeLevelFn)gDirectDraw_00451030->lpVtbl[20])
            (gDirectDraw_00451030, gMainWindow_004875a0, 8);

        previousBpp = gScreenDisplayMode_00454fc8;
        gScreenDisplayMode_00454fc8 = DDRAW_GetDisplayMode_00401000();
        if (((unsigned int)gScreenDisplayMode_00454fc8 - (unsigned int)previousBpp) != 0) {
            if (gScreenDisplayMode_00454fc8 == 0x565)
                HGDIOBJ_004870d0 = SelectObject(ghDC_0047f0c8, HBITMAP_00487508);
            else if (gScreenDisplayMode_00454fc8 == 8)
                HGDIOBJ_004870d0 = SelectObject(ghDC_0047f0c8, ghDIBSection_0047f0c4);
            else
                HGDIOBJ_004870d0 = SelectObject(ghDC_0047f0c8, HBITMAP_004870d4);
        }

        if (resolutionCode == 0)
            DAT_0049fb8c_CurrentBPPType = gScreenDisplayMode_00454fc8;

        if (result == 0) {
            gScreenResolution_00451038 = resolutionCode;
            return 1;
        }
    }
    return 0;
}
