typedef struct IDirectSoundBuffer IDirectSoundBuffer;
typedef struct IDirectSoundBufferVtbl {
    void *QueryInterface, *AddRef, *Release, *GetCaps, *GetCurrentPosition, *GetFormat, *GetVolume, *GetPan,
        *GetFrequency, *GetStatus, *Initialize;
    long (__stdcall *Lock)(IDirectSoundBuffer *self, unsigned long offset, unsigned long bytes,
        void **ptr1, unsigned long *bytes1, void **ptr2, unsigned long *bytes2, unsigned long flags);
    void *Play, *SetCurrentPosition, *SetFormat, *SetVolume, *SetPan, *SetFrequency, *Stop;
    long (__stdcall *Unlock)(IDirectSoundBuffer *self, void *ptr1, unsigned long bytes1, void *ptr2, unsigned long bytes2);
    long (__stdcall *Restore)(IDirectSoundBuffer *self);
} IDirectSoundBufferVtbl;
struct IDirectSoundBuffer { IDirectSoundBufferVtbl *lpVtbl; };
extern "C" {
void *__cdecl memcpy(void *dst, const void *src, unsigned int count);
int __cdecl SND_FillDirectSoundBuffer_004017d0(IDirectSoundBuffer *buffer, unsigned long offset, unsigned char *data, unsigned long bytes)
{
    void *ptr2;
    unsigned long bytes1;
    unsigned long bytes2;
    void *ptr1;
    long result;
    result = buffer->lpVtbl->Lock(buffer, offset, bytes, &ptr1, &bytes1, &ptr2, &bytes2, 0);
    if (result == (long)0x88780096) {
        buffer->lpVtbl->Restore(buffer);
        result = buffer->lpVtbl->Lock(buffer, offset, bytes, &ptr1, &bytes1, &ptr2, &bytes2, 0);
    }
    if (result == 0) {
        memcpy(ptr1, data, bytes1);
        if (ptr2)
            memcpy(ptr2, data + bytes1, bytes2);
        if (buffer->lpVtbl->Unlock(buffer, ptr1, bytes1, ptr2, bytes2) == 0)
            return 1;
    }
    return 0;
}
}
