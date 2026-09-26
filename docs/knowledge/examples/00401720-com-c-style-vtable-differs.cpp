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
struct IDirectSoundBuffer;
struct IDirectSound {
    virtual long __stdcall QueryInterface(void *iid, void **object) = 0;
    virtual unsigned long __stdcall AddRef(void) = 0;
    virtual unsigned long __stdcall Release(void) = 0;
    virtual long __stdcall CreateSoundBuffer(DSBUFFERDESC *desc, IDirectSoundBuffer **buffer, void *outer) = 0;
};
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
extern IDirectSound *gDirectSound_0049a070;
int __cdecl GEX_Target(int unused, IDirectSoundBuffer **buffer, unsigned long bytes, unsigned long rate)
{
    PCMWAVEFORMAT format;
    DSBUFFERDESC desc;
    memset(&format, 0, sizeof(format));
    format.wFormatTag = 1;
    format.nChannels = 1;
    format.nSamplesPerSec = rate;
    format.nAvgBytesPerSec = rate;
    format.nBlockAlign = 1;
    format.wBitsPerSample = 8;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0xe8;
    desc.dwBufferBytes = bytes;
    desc.lpwfxFormat = &format;
    if (gDirectSound_0049a070->CreateSoundBuffer(&desc, buffer, 0) == 0)
        return 1;
    *buffer = 0;
    return 0;
}
}
