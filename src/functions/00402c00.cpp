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
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
extern "C" {
__declspec(dllimport) unsigned long __stdcall GetTickCount(void);
__declspec(dllimport) void __stdcall Sleep(unsigned long ms);
extern int gIsPaused_00487f88;
extern volatile int DAT_0049a064_MusicUnk2;
extern int DAT_0048a048;
extern void *gDirectSound_0049a070;
extern volatile int gMusicToPlay_0048a034;
extern int gVFXToPlay_0049a054;
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern IDirectSoundBuffer *gVFXDirectSoundBuffer_0049a068;
extern int DAT_0048a030;
extern int DAT_0048a044;
extern volatile int DAT_0048a03c_MusicUnk1;
void __cdecl SoundThreadOpenMusic_00402a00(void);
void __cdecl SoundThreadCloseMusic_004026d0(void);
void __cdecl VFX_DoPlay_004019d0(void);
void __cdecl FUN_00402790_DS_Readfile(void);
unsigned long __stdcall SoundThread_00402c00(void *param)
{
    unsigned long status;
    unsigned long start;
    long delay;
    DAT_0049a064_MusicUnk2 = 1;
    while (!gIsPaused_00487f88) {
        if (DAT_0048a048)
            goto done;
        Sleep(0);
    }
    while (!DAT_0048a048) {
        start = GetTickCount();
        if (gDirectSound_0049a070) {
            if (gMusicToPlay_0048a034) {
                if (gMusicToPlay_0048a034 == -1 && gMusicDirectSoundBuffer_0048a040) {
                    gMusicDirectSoundBuffer_0048a040->lpVtbl->Release(gMusicDirectSoundBuffer_0048a040);
                    gMusicDirectSoundBuffer_0048a040 = 0;
                    gMusicToPlay_0048a034 = 0;
                } else {
                    SoundThreadOpenMusic_00402a00();
                    gMusicToPlay_0048a034 = 0;
                }
            } else if (gVFXToPlay_0049a054) {
                SoundThreadCloseMusic_004026d0();
                VFX_DoPlay_004019d0();
                gVFXToPlay_0049a054 = 0;
            } else {
                if (gVFXDirectSoundBuffer_0049a068) {
                    if (gVFXDirectSoundBuffer_0049a068->lpVtbl->GetStatus(gVFXDirectSoundBuffer_0049a068, &status) || !(status & 1)) {
                        gVFXDirectSoundBuffer_0049a068->lpVtbl->Release(gVFXDirectSoundBuffer_0049a068);
                        gVFXDirectSoundBuffer_0049a068 = 0;
                    }
                }
                SoundThreadCloseMusic_004026d0();
                FUN_00402790_DS_Readfile();
            }
            if (DAT_0048a044 != DAT_0048a030) {
                DAT_0048a044 = DAT_0048a030;
                if (gMusicDirectSoundBuffer_0048a040)
                    gMusicDirectSoundBuffer_0048a040->lpVtbl->SetVolume(gMusicDirectSoundBuffer_0048a040, DAT_0048a030);
            }
        } else {
            gMusicToPlay_0048a034 = 0;
            gVFXToPlay_0049a054 = 0;
        }
        if (DAT_0048a03c_MusicUnk1) {
            if (gMusicDirectSoundBuffer_0048a040)
                gMusicDirectSoundBuffer_0048a040->lpVtbl->Stop(gMusicDirectSoundBuffer_0048a040);
            if (gVFXDirectSoundBuffer_0049a068)
                gVFXDirectSoundBuffer_0049a068->lpVtbl->Stop(gVFXDirectSoundBuffer_0049a068);
            DAT_0049a064_MusicUnk2 = 0;
            while (DAT_0048a03c_MusicUnk1 && !DAT_0048a048)
                Sleep(0);
            DAT_0049a064_MusicUnk2 = 1;
            if (DAT_0048a048)
                break;
            if (gMusicDirectSoundBuffer_0048a040 && !gMusicToPlay_0048a034)
                gMusicDirectSoundBuffer_0048a040->lpVtbl->Play(gMusicDirectSoundBuffer_0048a040, 0, 0, 1);
            if (gVFXDirectSoundBuffer_0049a068)
                gVFXDirectSoundBuffer_0049a068->lpVtbl->Play(gVFXDirectSoundBuffer_0049a068, 0, 0, 0);
        } else {
            delay = start - GetTickCount() + 100;
            if (delay > 0)
                Sleep(delay);
        }
    }
done:
    if (gMusicDirectSoundBuffer_0048a040) {
        gMusicDirectSoundBuffer_0048a040->lpVtbl->Release(gMusicDirectSoundBuffer_0048a040);
        gMusicDirectSoundBuffer_0048a040 = 0;
    }
    if (gVFXDirectSoundBuffer_0049a068) {
        gVFXDirectSoundBuffer_0049a068->lpVtbl->Release(gVFXDirectSoundBuffer_0049a068);
        gVFXDirectSoundBuffer_0049a068 = 0;
    }
    gMusicToPlay_0048a034 = 0;
    gVFXToPlay_0049a054 = 0;
    DAT_0049a064_MusicUnk2 = 0;
    return 0;
}
}
