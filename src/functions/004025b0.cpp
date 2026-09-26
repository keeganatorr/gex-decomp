typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IDirectSoundBufferVtbl {
    void *QueryInterface, *AddRef, *Release, *GetCaps, *GetCurrentPosition, *GetFormat, *GetVolume, *GetPan,
        *GetFrequency, *GetStatus, *Initialize;
    long (__stdcall *Lock)(IDirectSoundBuffer *self, unsigned long offset, unsigned long bytes,
        void **ptr1, unsigned long *bytes1, void **ptr2, unsigned long *bytes2, unsigned long flags);
    void *Play, *SetCurrentPosition, *SetFormat, *SetVolume, *SetPan, *SetFrequency, *Stop;
    long (__stdcall *Unlock)(IDirectSoundBuffer *self, void *ptr1, unsigned long bytes1, void *ptr2, unsigned long bytes2);
    long (__stdcall *Restore)(IDirectSoundBuffer *self);
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *text);
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern unsigned int DAT_0049a05c;
void *__cdecl memcpy(void *dst, const void *src, unsigned int count);
extern unsigned int DAT_0049a060;
extern unsigned char lpBuffer_0048a050[];
extern char s_DS_lock_failed_00451668[];
void __cdecl GEX_Target(int half)
{
    void *ptr1;
    unsigned long bytes2;
    void *ptr2;
    unsigned long bytes1;
    unsigned char *dest;
    unsigned char *source;
    long result;
    unsigned int chunk;
    unsigned int left;
    if (half)
        result = gMusicDirectSoundBuffer_0048a040->lpVtbl->Lock(gMusicDirectSoundBuffer_0048a040, 0x2b11, 0x2b11,
            &ptr1, &bytes1, &ptr2, &bytes2, 0);
    else
        result = gMusicDirectSoundBuffer_0048a040->lpVtbl->Lock(gMusicDirectSoundBuffer_0048a040, 0, 0x2b11,
            &ptr1, &bytes1, &ptr2, &bytes2, 0);
    if (result == 0) {
        dest = (unsigned char *)ptr1;
        left = 0x2b11;
        do {
            chunk = left;
            if (DAT_0049a05c) {
                source = lpBuffer_0048a050 + DAT_0049a060;
                if (left > DAT_0049a05c)
                    chunk = DAT_0049a05c;
                if (DAT_0049a060 + chunk >= 0x10000) {
                    chunk = 0x10000 - DAT_0049a060;
                    DAT_0049a060 = 0;
                } else
                    DAT_0049a060 += chunk;
                DAT_0049a05c -= chunk;
                memcpy(dest, source, chunk);
            } else
                memset(dest, 0x80, left);
            dest += chunk;
            left -= chunk;
        } while (left);
        gMusicDirectSoundBuffer_0048a040->lpVtbl->Unlock(gMusicDirectSoundBuffer_0048a040, ptr1, bytes1, ptr2, bytes2);
    } else
        OutputDebugStringA(s_DS_lock_failed_00451668);
}
}
