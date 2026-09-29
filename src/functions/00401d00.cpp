typedef struct IDirectSound IDirectSound;
typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IDirectSoundBufferVtbl {
    void *QueryInterface, *AddRef;
    unsigned long (__stdcall *Release)(IDirectSoundBuffer *self);
    void *GetCaps, *GetCurrentPosition, *GetFormat, *GetVolume, *GetPan, *GetFrequency;
    long (__stdcall *GetStatus)(IDirectSoundBuffer *self, unsigned long *status);
    void *Initialize, *Lock;
    long (__stdcall *Play)(IDirectSoundBuffer *self, unsigned long reserved, unsigned long priority, unsigned long flags);
    void *SetCurrentPosition, *SetFormat;
    long (__stdcall *SetVolume)(IDirectSoundBuffer *self, long volume);
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
extern "C" {
extern IDirectSound *gDirectSound_0049a070;
extern IDirectSoundBuffer *gPreviewSoundBuffer_0049fb28;
extern int DAT_0049a06c;
extern unsigned long gSndSizes_00451048[];
extern unsigned char *gSNDPointerArray_0049f6b0[];
int __cdecl SND_CreateDirectSoundBuffer_00401720(IDirectSound *sound, IDirectSoundBuffer **buffer, unsigned long bytes, unsigned long rate);
int __cdecl SND_FillDirectSoundBuffer_004017d0(IDirectSoundBuffer *buffer, unsigned long offset, unsigned char *data, unsigned long bytes);
void __cdecl SND_PlayPreviewSound_00401d00(int sound, long volume)
{
    unsigned long status;
    int index;
    index = sound - 0x40;
    if (!gDirectSound_0049a070)
        return;
    if (gPreviewSoundBuffer_0049fb28) {
        if (index == DAT_0049a06c) {
            gPreviewSoundBuffer_0049fb28->lpVtbl->GetStatus(gPreviewSoundBuffer_0049fb28, &status);
            if (status & 1) {
                gPreviewSoundBuffer_0049fb28->lpVtbl->SetVolume(gPreviewSoundBuffer_0049fb28, volume);
                return;
            }
        }
        gPreviewSoundBuffer_0049fb28->lpVtbl->Release(gPreviewSoundBuffer_0049fb28);
        gPreviewSoundBuffer_0049fb28 = 0;
    }
    DAT_0049a06c = index;
    if (SND_CreateDirectSoundBuffer_00401720(gDirectSound_0049a070, &gPreviewSoundBuffer_0049fb28, gSndSizes_00451048[index], 0x2b11)
        && SND_FillDirectSoundBuffer_004017d0(gPreviewSoundBuffer_0049fb28, 0, gSNDPointerArray_0049f6b0[index], gSndSizes_00451048[index])) {
        gPreviewSoundBuffer_0049fb28->lpVtbl->SetVolume(gPreviewSoundBuffer_0049fb28, volume);
        gPreviewSoundBuffer_0049fb28->lpVtbl->Play(gPreviewSoundBuffer_0049fb28, 0, 0, 0);
    }
}
}
