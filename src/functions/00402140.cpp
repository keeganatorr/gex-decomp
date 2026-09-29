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
typedef struct IDirectSoundBufferVtbl {
    long (__stdcall *QueryInterface)(IDirectSoundBuffer *self, void *iid, void **object);
    unsigned long (__stdcall *AddRef)(IDirectSoundBuffer *self);
    unsigned long (__stdcall *Release)(IDirectSoundBuffer *self);
    long (__stdcall *GetCaps)(IDirectSoundBuffer *self, void *caps);
    long (__stdcall *GetCurrentPosition)(IDirectSoundBuffer *self, unsigned long *play, unsigned long *write);
    long (__stdcall *GetFormat)(IDirectSoundBuffer *self, void *format, unsigned long size, unsigned long *written);
    long (__stdcall *GetVolume)(IDirectSoundBuffer *self, long *volume);
    long (__stdcall *GetPan)(IDirectSoundBuffer *self, long *pan);
    long (__stdcall *GetFrequency)(IDirectSoundBuffer *self, unsigned long *frequency);
    long (__stdcall *GetStatus)(IDirectSoundBuffer *self, unsigned long *status);
    long (__stdcall *Initialize)(IDirectSoundBuffer *self, void *ds, void *desc);
    long (__stdcall *Lock)(IDirectSoundBuffer *self, unsigned long offset, unsigned long bytes, void **p1, unsigned long *n1, void **p2, unsigned long *n2, unsigned long flags);
    long (__stdcall *Play)(IDirectSoundBuffer *self, unsigned long reserved, unsigned long priority, unsigned long flags);
    long (__stdcall *SetCurrentPosition)(IDirectSoundBuffer *self, unsigned long position);
    long (__stdcall *SetFormat)(IDirectSoundBuffer *self, void *format);
    long (__stdcall *SetVolume)(IDirectSoundBuffer *self, long volume);
    long (__stdcall *SetPan)(IDirectSoundBuffer *self, long pan);
    long (__stdcall *SetFrequency)(IDirectSoundBuffer *self, unsigned long frequency);
    long (__stdcall *Stop)(IDirectSoundBuffer *self);
    long (__stdcall *Unlock)(IDirectSoundBuffer *self, void *p1, unsigned long n1, void *p2, unsigned long n2);
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
typedef struct IDirectSound IDirectSound;
typedef struct IDirectSoundVtbl {
    long (__stdcall *QueryInterface)(IDirectSound *self, void *iid, void **object);
    unsigned long (__stdcall *AddRef)(IDirectSound *self);
    unsigned long (__stdcall *Release)(IDirectSound *self);
    long (__stdcall *CreateSoundBuffer)(IDirectSound *self, DSBUFFERDESC *desc, IDirectSoundBuffer **buffer, void *outer);
    long (__stdcall *GetCaps)(IDirectSound *self, void *caps);
    long (__stdcall *DuplicateSoundBuffer)(IDirectSound *self, IDirectSoundBuffer *in, IDirectSoundBuffer **out);
    long (__stdcall *SetCooperativeLevel)(IDirectSound *self, void *window, unsigned long level);
} IDirectSoundVtbl;
struct IDirectSound { IDirectSoundVtbl *lpVtbl; };
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
void *__cdecl memcpy(void *dst, const void *src, unsigned int count);
__declspec(dllimport) int __stdcall sndPlaySoundA(const char *sound, unsigned int flags);
__declspec(dllimport) void __stdcall Sleep(unsigned long ms);
__declspec(dllimport) int __stdcall MessageBoxA(void *window, const char *text, const char *caption, unsigned int type);
long __stdcall DirectSoundCreate_00409870(void *guid, IDirectSound **ds, void *outer);
extern int DAT_004514b4;
extern int DAT_0049fb1c;
extern int DAT_0049fb24;
extern IDirectSound *gDirectSound_0049a070;
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern IDirectSoundBuffer *gVFXDirectSoundBuffer_0049a068;
extern IDirectSoundBuffer *gPreviewSoundBuffer_0049fb28;
extern IDirectSoundBuffer *PTR_ARRAY_0049fb30[8];
extern unsigned char BYTE_ARRAY_0049a080[];
extern unsigned long DAT_0049fb14_DS_pDSCaps;
extern long DAT_0048a044;
extern void *gMainWindow_004875a0;
extern char DAT_00487630_SoundDeviceAccessErrorString[];
extern char WindowTitle_GEX[];

void __cdecl FUN_00402140_Sound(int enable)
{
    unsigned long n1;
    void *p1;
    PCMWAVEFORMAT format;
    unsigned long n2;
    void *p2;
    DSBUFFERDESC desc;
    unsigned long write;

    if (!DAT_004514b4) {
        DAT_004514b4++;
        if (enable) {
            if (DAT_0049fb1c) {
                do {
                    sndPlaySoundA(0, 0);
                    Sleep(500);
                    if (!DirectSoundCreate_00409870(0, &gDirectSound_0049a070, 0))
                        break;
                    if (gDirectSound_0049a070) {
                        gDirectSound_0049a070->lpVtbl->Release(gDirectSound_0049a070);
                        gDirectSound_0049a070 = 0;
                    }
                } while (MessageBoxA(0, DAT_00487630_SoundDeviceAccessErrorString, WindowTitle_GEX, 0x2035) != 2);
                if (gDirectSound_0049a070) {
                    gDirectSound_0049a070->lpVtbl->SetCooperativeLevel(gDirectSound_0049a070, gMainWindow_004875a0, 1);
                    if (DAT_0049fb24) {
                        memset(&format, 0, sizeof(format));
                        format.wFormatTag = 1;
                        format.nChannels = 1;
                        format.nSamplesPerSec = 0x5622;
                        format.nAvgBytesPerSec = 0x5622;
                        format.nBlockAlign = 1;
                        format.wBitsPerSample = 8;
                        memset(&desc, 0, sizeof(desc));
                        desc.dwSize = 0x14;
                        desc.dwFlags = 0xe8;
                        desc.dwBufferBytes = 0x5622;
                        desc.lpwfxFormat = &format;
                        if (!gDirectSound_0049a070->lpVtbl->CreateSoundBuffer(gDirectSound_0049a070, &desc, &gMusicDirectSoundBuffer_0048a040, 0)
                            && !gMusicDirectSoundBuffer_0048a040->lpVtbl->Lock(gMusicDirectSoundBuffer_0048a040, 0, 0x5622, &p1, &n1, &p2, &n2, 0)) {
                            memcpy(p1, BYTE_ARRAY_0049a080, 0x5622);
                            gMusicDirectSoundBuffer_0048a040->lpVtbl->Unlock(gMusicDirectSoundBuffer_0048a040, p1, n1, p2, n2);
                            gMusicDirectSoundBuffer_0048a040->lpVtbl->SetCurrentPosition(gMusicDirectSoundBuffer_0048a040, DAT_0049fb14_DS_pDSCaps);
                            gMusicDirectSoundBuffer_0048a040->lpVtbl->SetVolume(gMusicDirectSoundBuffer_0048a040, DAT_0048a044);
                        }
                    }
                }
            }
        } else {
            DAT_0049fb1c = 0;
            DAT_0049fb24 = 0;
            if (gDirectSound_0049a070) {
                DAT_0049fb1c = 1;
                if (gMusicDirectSoundBuffer_0048a040) {
                    DAT_0049fb24 = 1;
                    gMusicDirectSoundBuffer_0048a040->lpVtbl->GetCurrentPosition(gMusicDirectSoundBuffer_0048a040, &DAT_0049fb14_DS_pDSCaps, &write);
                }
                for (n1 = 0; n1 < 8; n1++) {
                    if (PTR_ARRAY_0049fb30[n1]) {
                        PTR_ARRAY_0049fb30[n1]->lpVtbl->Release(PTR_ARRAY_0049fb30[n1]);
                        PTR_ARRAY_0049fb30[n1] = 0;
                    }
                }
                if (gVFXDirectSoundBuffer_0049a068) {
                    gVFXDirectSoundBuffer_0049a068->lpVtbl->Release(gVFXDirectSoundBuffer_0049a068);
                    gVFXDirectSoundBuffer_0049a068 = 0;
                }
                if (gMusicDirectSoundBuffer_0048a040) {
                    gMusicDirectSoundBuffer_0048a040->lpVtbl->Release(gMusicDirectSoundBuffer_0048a040);
                    gMusicDirectSoundBuffer_0048a040 = 0;
                }
                if (gPreviewSoundBuffer_0049fb28) {
                    gPreviewSoundBuffer_0049fb28->lpVtbl->Release(gPreviewSoundBuffer_0049fb28);
                    gPreviewSoundBuffer_0049fb28 = 0;
                }
                gDirectSound_0049a070->lpVtbl->Release(gDirectSound_0049a070);
                gDirectSound_0049a070 = 0;
            }
        }
        DAT_004514b4 = 0;
    }
}
}
