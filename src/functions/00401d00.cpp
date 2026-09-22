struct IDirectSoundBuffer {
    virtual long __stdcall QueryInterface(void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* lpDSBufferDesc) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* lpdwPlayCursor, unsigned long* lpdwWriteCursor) = 0;
    virtual long __stdcall GetFormat(void* lpwfxFormat, unsigned long dwSizeAllocated, unsigned long* lpdwSizeWritten) = 0;
    virtual long __stdcall GetVolume(long* lplVolume) = 0;
    virtual long __stdcall GetPan(long* lplPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* lpdwFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* lpdwStatus) = 0;
    virtual long __stdcall Initialize(void* lpDirectSound, const void* lpcDSBufferDesc) = 0;
    virtual long __stdcall Lock(unsigned long dwOffset, unsigned long dwBytes, void** ppvAudioPtr1, unsigned long* pdwAudioBytes1, void** ppvAudioPtr2, unsigned long* pdwAudioBytes2, unsigned long dwFlags) = 0;
    virtual long __stdcall Play(unsigned long dwReserved1, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long dwNewPosition) = 0;
    virtual long __stdcall SetFormat(const void* lpcfxFormat) = 0;
    virtual long __stdcall SetVolume(long lVolume) = 0;
};

extern "C" {

extern void* gDirectSound_0049a070;
extern IDirectSoundBuffer* gPreviewSoundBuffer_0049fb28;
extern int DAT_0049a06c;
extern int gSndSizes_00451048[];
extern void* gSNDPointerArray_0049f6b0[];

int SND_CreateDirectSoundBuffer_00401720(void* ds, void** ppBuffer, int size, int flags);
int SND_FillDirectSoundBuffer_004017d0(void* buffer, int offset, void* data, int size);

void _GEX_Target(int param_1, int param_2)
{
    int iVar2 = param_1 - 0x40;
    if (gDirectSound_0049a070 == 0) {
        return;
    }
    if (gPreviewSoundBuffer_0049fb28 != 0) {
        if (DAT_0049a06c == iVar2) {
            unsigned long local_4;
            gPreviewSoundBuffer_0049fb28->GetStatus(&local_4);
            if ((local_4 & 1) != 0) {
                gPreviewSoundBuffer_0049fb28->SetVolume(param_2);
                return;
            }
        }
        gPreviewSoundBuffer_0049fb28->Release();
        gPreviewSoundBuffer_0049fb28 = 0;
    }
    DAT_0049a06c = iVar2;
    if (SND_CreateDirectSoundBuffer_00401720(gDirectSound_0049a070, (void**)&gPreviewSoundBuffer_0049fb28, gSndSizes_00451048[iVar2], 0x2b11) != 0) {
        if (SND_FillDirectSoundBuffer_004017d0(gPreviewSoundBuffer_0049fb28, 0, gSNDPointerArray_0049f6b0[iVar2], gSndSizes_00451048[iVar2]) != 0) {
            gPreviewSoundBuffer_0049fb28->SetVolume(param_2);
            gPreviewSoundBuffer_0049fb28->Play(0, 0, 0);
        }
    }
}

}
