typedef unsigned long DWORD;
typedef void *HANDLE;

struct SoundBuffer {
    void **vtable;
};

typedef unsigned long (__stdcall *BufferRelease)(SoundBuffer *);
typedef long (__stdcall *BufferPlay)(SoundBuffer *, DWORD, DWORD, DWORD);
typedef long (__stdcall *BufferSetVolume)(SoundBuffer *, long);

extern "C" {
extern SoundBuffer *gVFXDirectSoundBuffer_0049a068;
extern int gVFXToPlay_0049a054;
extern void *gDirectSound_0049a070;
extern long gVFXVolume_0049fb50;
extern const char s_VFX_GEX__3d_VFX_004514b8[];

__declspec(dllimport) int __cdecl wsprintfA(char *, const char *, ...);
__declspec(dllimport) HANDLE __stdcall CreateFileA(const char *, DWORD, DWORD, void *, DWORD, DWORD, HANDLE);
__declspec(dllimport) DWORD __stdcall GetFileSize(HANDLE, DWORD *);
__declspec(dllimport) int __stdcall CloseHandle(HANDLE);

int __cdecl SND_CreateDirectSoundBuffer_00401720(void *, SoundBuffer **, DWORD, DWORD);
int __cdecl FUN_004018b0_LoadVFX(SoundBuffer *, HANDLE, DWORD);
}

extern "C" void VFX_DoPlay_004019d0(void)
{
    char filename[256];
    HANDLE hFile;
    DWORD fileSize;
    int result;

    if (gVFXDirectSoundBuffer_0049a068 != 0) {
        ((BufferRelease)gVFXDirectSoundBuffer_0049a068->vtable[2])(gVFXDirectSoundBuffer_0049a068);
        gVFXDirectSoundBuffer_0049a068 = 0;
    }

    wsprintfA(filename, s_VFX_GEX__3d_VFX_004514b8, gVFXToPlay_0049a054);
    hFile = CreateFileA(filename, 0x80000000UL, 1, 0, 3, 0x08000000UL, 0);
    if (hFile != (HANDLE)-1) {
        fileSize = GetFileSize(hFile, 0);
        result = SND_CreateDirectSoundBuffer_00401720(gDirectSound_0049a070, &gVFXDirectSoundBuffer_0049a068, fileSize, 0x5622);
        if (result != 0) {
            result = FUN_004018b0_LoadVFX(gVFXDirectSoundBuffer_0049a068, hFile, fileSize);
            if (result != 0) {
                CloseHandle(hFile);
                ((BufferSetVolume)gVFXDirectSoundBuffer_0049a068->vtable[15])(gVFXDirectSoundBuffer_0049a068, gVFXVolume_0049fb50);
                ((BufferPlay)gVFXDirectSoundBuffer_0049a068->vtable[12])(gVFXDirectSoundBuffer_0049a068, 0, 0, 0);
                return;
            }
            ((BufferRelease)gVFXDirectSoundBuffer_0049a068->vtable[2])(gVFXDirectSoundBuffer_0049a068);
        }
        gVFXDirectSoundBuffer_0049a068 = 0;
        CloseHandle(hFile);
    }
}
