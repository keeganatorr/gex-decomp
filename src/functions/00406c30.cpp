// Palette conversion and presentation from GFX_Flush_00406c30.
// This source follows the recovered display-mode paths; no exact proof claimed.
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef void *HANDLE;

extern "C" {
__declspec(dllimport) int __stdcall BitBlt(HANDLE, int, int, int, int,
                                           HANDLE, int, int, DWORD);
__declspec(dllimport) int __stdcall GdiFlush(void);
__declspec(dllimport) int __stdcall TextOutA(HANDLE, int, int, const char *, int);
__declspec(dllimport) int __stdcall StretchBlt(HANDLE, int, int, int, int,
                                               HANDLE, int, int, int, int, DWORD);
__declspec(dllimport) int __stdcall GetSystemMetrics(int);
void __cdecl FUN_00406c00_IfFreeGameNotEquals1_Unk_WHAT_DOES_THIS_DO_CONTAINS_PPVBITS(void);
}

static unsigned &flushWord(unsigned long address) { return *(unsigned *)address; }
static void *&flushPointer(unsigned long address) { return *(void **)address; }

extern "C" void __cdecl GFX_Flush_00406c30(void)
{
    if (flushWord(0x00451040)) return;
    ++flushWord(0x00487a90);
    unsigned char *pixels = (unsigned char *)flushPointer(0x00487f70);
    unsigned char *frame = pixels + 0x4000;
    if (flushWord(0x004a294c) == 2) {
        unsigned char *pauseFrame = pixels + 0x7c000;
        for (unsigned row = 0; row != 224; ++row) {
            unsigned *destination = (unsigned *)(frame + row * 0x800);
            const unsigned *source = (const unsigned *)(pauseFrame + row * 0x800);
            for (unsigned column = 0; column != 160; ++column)
                destination[column] = source[column];
        }
    }

    HANDLE sourceDC = flushPointer(0x0047f0c8);
    HANDLE vramDC = flushPointer(0x00487510);
    if (vramDC && sourceDC && flushWord(0x00487bc0) && !flushWord(0x00454fb8)) {
        BitBlt(vramDC, 0, 0, 1024, 512, sourceDC, 0, 0, 0xcc0020);
        GdiFlush();
    }
    HANDLE destinationDC = flushPointer(0x00487f7c);
    if (!destinationDC || !sourceDC) return;
    unsigned mode = flushWord(0x00454fc8);
    if (mode == 8) {
        const unsigned char *lookup = (const unsigned char *)0x0047f0d0;
        for (unsigned row8 = 0; row8 != 224; ++row8) {
            unsigned *source8 = (unsigned *)(frame + row8 * 0x800);
            unsigned char *destination8 = frame + row8 * 0x800;
            for (unsigned column8 = 0; column8 != 160; ++column8) {
                unsigned pair = source8[column8];
                destination8[column8 * 2] = lookup[pair & 0x7fff];
                destination8[column8 * 2 + 1] = lookup[(pair >> 16) & 0x7fff];
            }
        }
    }
    if (mode == 0x555 || mode == 0x565) {
        for (unsigned row16 = 0; row16 != 224; ++row16) {
            unsigned *line = (unsigned *)(frame + row16 * 0x800);
            for (unsigned column16 = 0; column16 != 160; ++column16) {
                unsigned pair16 = line[column16];
                if (mode == 0x555)
                    line[column16] = (pair16 & 0x03e003e0) |
                                     ((pair16 & 0x7c007c00) >> 10) |
                                     ((pair16 & 0x001f001f) << 10);
                else
                    line[column16] = ((pair16 << 1) & 0x07c007c0) |
                                     ((pair16 & 0x7c007c00) >> 10) |
                                     ((pair16 & 0x001f001f) << 11);
            }
        }
    }
    if (flushWord(0x00487ee4))
        TextOutA(sourceDC, 0x91, 4, (const char *)0x00454fa8,
                 flushWord(0x00454fb4));

    int targetWidth;
    int targetHeight;
    int sourceY;
    int sourceHeight;
    unsigned fullscreen = flushWord(0x0045103c);
    unsigned resolution = flushWord(0x00451038);
    if (fullscreen == 2) {
        targetWidth = resolution == 0x320240 ? 320 : 640;
        targetHeight = resolution == 0x320240 ? 240 : 480;
        sourceY = 0;
        sourceHeight = 240;
    } else if (fullscreen == 1) {
        int menuHeight = GetSystemMetrics(15);
        int doubled = (menuHeight + 1) & ~1;
        if (resolution == 0x320240) {
            targetWidth = 320;
            targetHeight = 240 - doubled;
            sourceY = doubled;
            sourceHeight = targetHeight;
        } else {
            targetWidth = 640;
            targetHeight = 480 - doubled;
            sourceY = doubled / 2;
            sourceHeight = 240 - sourceY;
        }
    } else {
        targetWidth = flushWord(0x00487a04);
        targetHeight = flushWord(0x00487a08);
        sourceY = 8;
        sourceHeight = 224;
    }
    StretchBlt(destinationDC, 0, 0, targetWidth, targetHeight, sourceDC,
               0, sourceY, 320, sourceHeight, 0xcc0020);
    GdiFlush();
    FUN_00406c00_IfFreeGameNotEquals1_Unk_WHAT_DOES_THIS_DO_CONTAINS_PPVBITS();
}
