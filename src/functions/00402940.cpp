// PCMWAVEFORMAT flattened: mmsystem.h packs WAVEFORMAT to 14 bytes, which a
// self-contained unit cannot request without a pack pragma.
typedef struct PCMWAVEFORMAT {
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
} PCMWAVEFORMAT;
typedef struct DSBUFFERDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    void *lpwfxFormat;
} DSBUFFERDESC;
typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IDirectSound IDirectSound;
typedef struct IDirectSoundVtbl {
    long (__stdcall *QueryInterface)(IDirectSound *self, void *iid, void **object);
    unsigned long (__stdcall *AddRef)(IDirectSound *self);
    unsigned long (__stdcall *Release)(IDirectSound *self);
    long (__stdcall *CreateSoundBuffer)(IDirectSound *self, DSBUFFERDESC *desc, IDirectSoundBuffer **buffer, void *outer);
} IDirectSoundVtbl;
struct IDirectSound { IDirectSoundVtbl *lpVtbl; };
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
extern IDirectSound *gDirectSound_0049a070;
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
void __cdecl FUN_004028b0_DS_Lock2(int half, unsigned long bytes);
int __cdecl GEX_Target(void)
{
    PCMWAVEFORMAT format;
    DSBUFFERDESC desc;
    memset(&format, 0, sizeof(format));
    format.wFormatTag = 1;
    format.nChannels = 1;
    format.nSamplesPerSec = 0x5622;
    format.nAvgBytesPerSec = 0x5622;
    format.nBlockAlign = 1;
    format.wBitsPerSample = 8;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0xe8;
    desc.dwBufferBytes = 0x5622;
    desc.lpwfxFormat = &format;
    if (gDirectSound_0049a070->lpVtbl->CreateSoundBuffer(gDirectSound_0049a070, &desc, &gMusicDirectSoundBuffer_0048a040, 0) == 0) {
        FUN_004028b0_DS_Lock2(0, 0x5622);
        return 1;
    }
    gMusicDirectSoundBuffer_0048a040 = 0;
    return 0;
}
}
