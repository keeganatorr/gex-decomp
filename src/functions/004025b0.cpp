typedef unsigned long DWORD;
typedef long HRESULT;
typedef void (__stdcall *DSMethod)(void);
struct SoundBuffer { DSMethod *lpVtbl; };
typedef HRESULT (__stdcall *LockMethod)(SoundBuffer *, DWORD, DWORD, void **, DWORD *, void **, DWORD *, DWORD);
typedef HRESULT (__stdcall *UnlockMethod)(SoundBuffer *, void *, DWORD, void *, DWORD);

extern "C" {
extern SoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern DWORD DAT_0049a05c;
extern DWORD DAT_0049a060;
extern unsigned char lpBuffer_0048a050[];
extern const char s_DS_lock_failed_00451668[];
__declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
void * __cdecl memcpy(void *, const void *, unsigned int);
void * __cdecl memset(void *, int, unsigned int);
}

extern "C" void __cdecl GEX_Target(int which)
{
    void *region1;
    DWORD bytes2;
    void *region2;
    DWORD bytes1;
    HRESULT result;

    if (which) {
        result = ((LockMethod)gMusicDirectSoundBuffer_0048a040->lpVtbl[11])
            (gMusicDirectSoundBuffer_0048a040, 0x2b11UL, 0x2b11UL,
             &region1, &bytes1, &region2, &bytes2, 0);
    } else {
        result = ((LockMethod)gMusicDirectSoundBuffer_0048a040->lpVtbl[11])
            (gMusicDirectSoundBuffer_0048a040, 0, 0x2b11UL,
             &region1, &bytes1, &region2, &bytes2, 0);
    }

    if (result == 0) {
        unsigned char *destination;
        DWORD count;
        DWORD remaining;
        destination = (unsigned char *)region1;
        remaining = 0x2b11UL;
        do {
            count = remaining;
            DWORD available = DAT_0049a05c;
            if (available != 0) {
                const unsigned char *source = lpBuffer_0048a050 + DAT_0049a060;
                count = available < remaining ? available : remaining;
                if (DAT_0049a060 + count >= 0x10000UL) {
                    count = 0x10000UL - DAT_0049a060;
                    DAT_0049a060 = 0;
                } else {
                    DAT_0049a060 += count;
                }
                DAT_0049a05c -= count;
                memcpy(destination, source, count);
            } else {
                memset(destination, 0x80, count);
            }
            destination += count;
            remaining -= count;
        } while (remaining != 0);

        ((UnlockMethod)gMusicDirectSoundBuffer_0048a040->lpVtbl[19])
            (gMusicDirectSoundBuffer_0048a040, region1, bytes1, region2, bytes2);
    } else {
        OutputDebugStringA(s_DS_lock_failed_00451668);
    }
}
