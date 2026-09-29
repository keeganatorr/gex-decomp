typedef unsigned long DWORD;
typedef int HRESULT;

typedef struct _DDCOLORKEY {
    DWORD dwColorSpaceLowValue;
    DWORD dwColorSpaceHighValue;
} DDCOLORKEY;

typedef struct _DDPIXELFORMAT {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwFourCC;
    DWORD dwRGBBitCount;
    DWORD dwRBitMask;
    DWORD dwGBitMask;
    DWORD dwBBitMask;
    DWORD dwRGBAlphaBitMask;
} DDPIXELFORMAT;

typedef struct _DDSURFACEDESC {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHeight;
    DWORD dwWidth;
    long lPitch;
    DWORD dwBackBufferCount;
    DWORD dwMipMapCount;
    DWORD dwAlphaBitDepth;
    DWORD dwReserved;
    void* lpSurface;
    DDCOLORKEY ddckCKDestOverlay;
    DDCOLORKEY ddckCKDestBlt;
    DDCOLORKEY ddckCKSrcOverlay;
    DDCOLORKEY ddckCKSrcBlt;
    DDPIXELFORMAT ddpfPixelFormat;
    DWORD dwTextureStage;
} DDSURFACEDESC;

struct _IDirectDraw;

typedef struct _IDirectDrawVtbl {
    void* QueryInterface;
    void* AddRef;
    void* Release;
    void* Compact;
    void* CreateClipper;
    void* CreatePalette;
    void* CreateSurface;
    void* DuplicateSurface;
    void* EnumDisplayModes;
    void* EnumSurfaces;
    void* FlipToGDISurface;
    void* GetCaps;
    HRESULT (__stdcall *GetDisplayMode)(struct _IDirectDraw*, DDSURFACEDESC*);
} IDirectDrawVtbl;

typedef struct _IDirectDraw {
    IDirectDrawVtbl* lpVtbl;
} IDirectDraw;

extern "C" IDirectDraw* gDirectDraw_00451030;

extern "C" int DDRAW_GetDisplayMode_00401000(void)
{
    int result = 0x555;
    DDSURFACEDESC desc;
    for (int i = 0; i < 27; i++) {
        ((unsigned long*)&desc)[i] = 0;
    }
    desc.dwSize = sizeof(desc);
    if (gDirectDraw_00451030->lpVtbl->GetDisplayMode(gDirectDraw_00451030, &desc) == 0) {
        if (desc.ddpfPixelFormat.dwFlags & 0x20)
            result = 8;
        if (desc.ddpfPixelFormat.dwFlags & 0x40) {
            if (desc.ddpfPixelFormat.dwRGBBitCount == 0x10) {
                if (desc.ddpfPixelFormat.dwRBitMask == 0xf800 &&
                    desc.ddpfPixelFormat.dwGBitMask == 0x7e0)
                    result = 0x565;
                if (desc.ddpfPixelFormat.dwRBitMask == 0x7c00 &&
                    desc.ddpfPixelFormat.dwGBitMask == 0x3e0)
                    result = 0x555;
            }
        }
    }
    return result;
}
