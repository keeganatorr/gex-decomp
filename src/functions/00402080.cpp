struct IDirectSoundBuffer {
    virtual long __stdcall QueryInterface(void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct IDirectSound {
    virtual long __stdcall QueryInterface(void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

extern IDirectSoundBuffer *gVFXDirectSoundBuffer_0049a068;
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern IDirectSound *gPreviewSoundBuffer_0049fb28;
extern IDirectSound *gDirectSound_0049a070;
extern void *gMusicFile_0048a04c;
extern int PTR_ARRAY_0049fb30;
extern int gVFXVolume_0049fb50;

extern "C" void FUN_00402e30_MusicUnk(void);
extern "C" void FUN_00402e60_ReleaseMusicInner(void);
extern "C" __declspec(dllimport) void __stdcall CloseHandle(void*);

extern "C" void SND_DeInit_00402080(void)
{
    if (gDirectSound_0049a070 != 0) {
        int *piVar2 = &PTR_ARRAY_0049fb30;
        FUN_00402e30_MusicUnk();
        do {
            int *piVar1 = (int*)*piVar2;
            if (piVar1 != 0) {
                (*(void (__stdcall **)(int*))(*piVar1 + 8))(piVar1);
                *piVar2 = 0;
            }
            piVar2++;
        } while (piVar2 < &gVFXVolume_0049fb50);

        if (gVFXDirectSoundBuffer_0049a068 != 0) {
            gVFXDirectSoundBuffer_0049a068->Release();
            gVFXDirectSoundBuffer_0049a068 = 0;
        }
        if (gMusicDirectSoundBuffer_0048a040 != 0) {
            gMusicDirectSoundBuffer_0048a040->Release();
            gMusicDirectSoundBuffer_0048a040 = 0;
        }
        if (gMusicFile_0048a04c != 0) {
            CloseHandle(gMusicFile_0048a04c);
            gMusicFile_0048a04c = 0;
        }
        if (gPreviewSoundBuffer_0049fb28 != 0) {
            gPreviewSoundBuffer_0049fb28->Release();
            gPreviewSoundBuffer_0049fb28 = 0;
        }
        gDirectSound_0049a070->Release();
        gDirectSound_0049a070 = 0;
        FUN_00402e60_ReleaseMusicInner();
    }
}