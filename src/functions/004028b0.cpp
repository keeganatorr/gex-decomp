typedef int HRESULT;
typedef unsigned long DWORD;
typedef void* LPVOID;
typedef DWORD* LPDWORD;

struct IDirectSoundBuffer;
struct IDirectSoundBufferVtbl {
    HRESULT (__stdcall *QueryInterface)(IDirectSoundBuffer*, const void*, void**);
    unsigned long (__stdcall *AddRef)(IDirectSoundBuffer*);
    unsigned long (__stdcall *Release)(IDirectSoundBuffer*);
    HRESULT (__stdcall *GetCaps)(IDirectSoundBuffer*, void*);
    HRESULT (__stdcall *GetCurrentPosition)(IDirectSoundBuffer*, DWORD*, DWORD*);
    HRESULT (__stdcall *GetFormat)(IDirectSoundBuffer*, void*, DWORD, DWORD*);
    HRESULT (__stdcall *GetVolume)(IDirectSoundBuffer*, long*);
    HRESULT (__stdcall *GetPan)(IDirectSoundBuffer*, long*);
    HRESULT (__stdcall *GetFrequency)(IDirectSoundBuffer*, DWORD*);
    HRESULT (__stdcall *GetStatus)(IDirectSoundBuffer*, DWORD*);
    HRESULT (__stdcall *Initialize)(IDirectSoundBuffer*, void*);
    HRESULT (__stdcall *Lock)(IDirectSoundBuffer*, DWORD, DWORD, LPVOID*, LPDWORD, LPVOID*, LPDWORD, DWORD);
    HRESULT (__stdcall *Play)(IDirectSoundBuffer*, DWORD, DWORD, DWORD);
    HRESULT (__stdcall *SetCurrentPosition)(IDirectSoundBuffer*, DWORD);
    HRESULT (__stdcall *SetFormat)(IDirectSoundBuffer*, const void*);
    HRESULT (__stdcall *SetVolume)(IDirectSoundBuffer*, long);
    HRESULT (__stdcall *SetPan)(IDirectSoundBuffer*, long);
    HRESULT (__stdcall *SetFrequency)(IDirectSoundBuffer*, DWORD);
    HRESULT (__stdcall *SetStatus)(IDirectSoundBuffer*, DWORD);
    HRESULT (__stdcall *Unlock)(IDirectSoundBuffer*, LPVOID, DWORD, LPVOID, DWORD);
};

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl *lpVtbl;
};

extern "C" IDirectSoundBuffer *gMusicDirectSoundBuffer_0048a040;
extern "C" const char s_DS_Lock_2_failed_004516ac[];
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char *);
extern "C" void * __cdecl memset(void *, int, unsigned int);

extern "C" void FUN_004028b0_DS_Lock2(DWORD param_1, DWORD param_2)
{
    HRESULT HVar1;
    LPVOID *ppvVar4;
    LPDWORD pDVar5;
    LPVOID *ppvVar6;
    LPDWORD pDVar7;
    LPVOID local_10;
    DWORD local_c;
    LPVOID local_8;
    DWORD local_4;

    pDVar7 = &local_c;
    ppvVar6 = &local_8;
    pDVar5 = &local_4;
    ppvVar4 = &local_10;
    HVar1 = gMusicDirectSoundBuffer_0048a040->lpVtbl->Lock(
        gMusicDirectSoundBuffer_0048a040,
        param_1,
        param_2,
        ppvVar4,
        pDVar5,
        ppvVar6,
        pDVar7,
        0);
    if (HVar1 == 0) {
        memset(local_10, 0x80, param_2);
        gMusicDirectSoundBuffer_0048a040->lpVtbl->Unlock(
            gMusicDirectSoundBuffer_0048a040,
            local_10,
            local_4,
            local_8,
            local_c);
        return;
    }
    OutputDebugStringA(s_DS_Lock_2_failed_004516ac);
}
