typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IDirectSoundBufferVtbl {
    long (__stdcall *QueryInterface)(IDirectSoundBuffer *self, void *iid, void **object);
    unsigned long (__stdcall *AddRef)(IDirectSoundBuffer *self);
    unsigned long (__stdcall *Release)(IDirectSoundBuffer *self);
    long (__stdcall *GetCaps)(IDirectSoundBuffer *self, void *caps);
    long (__stdcall *GetCurrentPosition)(IDirectSoundBuffer *self, unsigned long *play, unsigned long *write);
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
extern "C" {
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *text);
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern int DAT_0048a038;
extern int DAT_0049a05c;
extern void *gMusicFile_0048a04c;
extern char s_DS_GetCurrentPosition_failed_00451678[];
void __cdecl FUN_004025b0_DS_Lock(int half);
void __cdecl GEX_Target(void)
{
    unsigned long play;
    unsigned long write;
    int crossed;
    if (!gMusicDirectSoundBuffer_0048a040)
        return;
    if (!gMusicDirectSoundBuffer_0048a040->lpVtbl->GetCurrentPosition(gMusicDirectSoundBuffer_0048a040, &play, &write)) {
        crossed = 0;
        if (DAT_0048a038) {
            if (play < 0x2b11)
                crossed = 1;
        } else if (play >= 0x2b11)
            crossed = 1;
        if (crossed) {
            if (!DAT_0049a05c && !gMusicFile_0048a04c) {
                gMusicDirectSoundBuffer_0048a040->lpVtbl->Release(gMusicDirectSoundBuffer_0048a040);
                gMusicDirectSoundBuffer_0048a040 = 0;
                return;
            }
            FUN_004025b0_DS_Lock(DAT_0048a038);
            DAT_0048a038 ^= 1;
        }
    } else
        OutputDebugStringA(s_DS_GetCurrentPosition_failed_00451678);
}
}
