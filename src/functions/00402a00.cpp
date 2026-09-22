typedef unsigned long DWORD;
typedef long HRESULT;
typedef int BOOL;
typedef void *HANDLE;
typedef void *LPVOID;
typedef char CHAR;

struct IDirectSoundBuffer;

struct IDirectSoundBufferVtbl {
    void *unused00[11];
    HRESULT (__stdcall *Lock)(IDirectSoundBuffer *, DWORD, DWORD, LPVOID *, DWORD *, LPVOID *, DWORD *, DWORD);
    HRESULT (__stdcall *Play)(IDirectSoundBuffer *, DWORD, DWORD, DWORD);
    HRESULT (__stdcall *SetCurrentPosition)(IDirectSoundBuffer *, DWORD);
    void *unused38;
    HRESULT (__stdcall *SetVolume)(IDirectSoundBuffer *, long);
    void *unused40;
    void *unused44;
    HRESULT (__stdcall *Stop)(IDirectSoundBuffer *);
    HRESULT (__stdcall *Unlock)(IDirectSoundBuffer *, LPVOID, DWORD, LPVOID, DWORD);
};

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl *lpVtbl;
};

struct SECURITY_ATTRIBUTES;
struct OVERLAPPED;

extern "C" {
__declspec(dllimport) BOOL __stdcall CloseHandle(HANDLE);
__declspec(dllimport) HANDLE __stdcall CreateFileA(const CHAR *, DWORD, DWORD, SECURITY_ATTRIBUTES *, DWORD, DWORD, HANDLE);
__declspec(dllimport) void __stdcall OutputDebugStringA(const CHAR *);
__declspec(dllimport) BOOL __stdcall ReadFile(HANDLE, LPVOID, DWORD, DWORD *, OVERLAPPED *);
__declspec(dllimport) int __cdecl wsprintfA(CHAR *, const CHAR *, ...);
void * __cdecl memcpy(void *, const void *, unsigned int);

int __cdecl FUN_00402940_LoadMusicInner(void);
extern IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern HANDLE gMusicFile_0048a04c;
extern DWORD gMusicToPlay_0048a034;
extern unsigned char lpBuffer_0048a050[];
extern const CHAR s_MUS_GEX__3d_MUS_00451700[];
extern const CHAR s_DS_FileOpen_failed__d_004516e8[];
extern const CHAR s_DS_Read_2_failed_004516d4[];
extern const CHAR s_DS_Lock_3_failed_004516c0[];
extern DWORD DAT_0049a058;
extern long DAT_0048a044;
extern DWORD DAT_0049a060;
extern DWORD DAT_0048a038;
extern DWORD DAT_0049a05c;
}

extern "C" void __cdecl GEX_Target(void)
{
    LPVOID audioPtr1;
    DWORD audioBytes2;
    LPVOID audioPtr2;
    DWORD audioBytes1;
    DWORD bytesRead;
    CHAR fileName[256];

    if (gMusicDirectSoundBuffer_0048a040 != 0 || FUN_00402940_LoadMusicInner() != 0) {
        if (gMusicFile_0048a04c != 0) {
            CloseHandle(gMusicFile_0048a04c);
            gMusicFile_0048a04c = 0;
        }

        gMusicDirectSoundBuffer_0048a040->lpVtbl->Stop(gMusicDirectSoundBuffer_0048a040);
        gMusicDirectSoundBuffer_0048a040->lpVtbl->SetCurrentPosition(gMusicDirectSoundBuffer_0048a040, 0);

        wsprintfA(fileName, s_MUS_GEX__3d_MUS_00451700, gMusicToPlay_0048a034);
        gMusicFile_0048a04c = CreateFileA(fileName, 0x80000000UL, 1, 0, 3, 0x08000000UL, 0);

        if (gMusicFile_0048a04c == (HANDLE)-1) {
            wsprintfA(fileName, s_DS_FileOpen_failed__d_004516e8, gMusicToPlay_0048a034);
            OutputDebugStringA(fileName);
            gMusicFile_0048a04c = 0;
            return;
        }

        if (ReadFile(gMusicFile_0048a04c, lpBuffer_0048a050, 0xe000, &bytesRead, 0) == 0) {
            OutputDebugStringA(s_DS_Read_2_failed_004516d4);
            CloseHandle(gMusicFile_0048a04c);
            gMusicFile_0048a04c = 0;
            return;
        }

        if (gMusicDirectSoundBuffer_0048a040->lpVtbl->Lock(
                gMusicDirectSoundBuffer_0048a040,
                0,
                0x2b11,
                &audioPtr1,
                &audioBytes1,
                &audioPtr2,
                &audioBytes2,
                0) != 0) {
            OutputDebugStringA(s_DS_Lock_3_failed_004516c0);
            CloseHandle(gMusicFile_0048a04c);
            gMusicFile_0048a04c = 0;
            return;
        }

        memcpy(audioPtr1, lpBuffer_0048a050, 0x2b11);

        gMusicDirectSoundBuffer_0048a040->lpVtbl->Unlock(
            gMusicDirectSoundBuffer_0048a040,
            audioPtr1,
            audioBytes1,
            audioPtr2,
            audioBytes2);

        DAT_0049a058 = 0xe000;
        DAT_0049a060 = 0x2b11;
        DAT_0048a038 = 1;
        DAT_0049a05c = 0xb4ef;

        gMusicDirectSoundBuffer_0048a040->lpVtbl->SetVolume(
            gMusicDirectSoundBuffer_0048a040,
            DAT_0048a044);
        gMusicDirectSoundBuffer_0048a040->lpVtbl->Play(
            gMusicDirectSoundBuffer_0048a040,
            0,
            0,
            1);
    }
}
