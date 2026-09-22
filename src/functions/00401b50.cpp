typedef void (__stdcall *SoundMethod)();
struct SoundBuffer {
    SoundMethod *lpVtbl;
};
typedef unsigned long (__stdcall *ReleaseMethod)(SoundBuffer *);
typedef long (__stdcall *ValueMethod)(SoundBuffer *, long);
typedef long (__stdcall *PlayMethod)(SoundBuffer *, unsigned long, unsigned long, unsigned long);

extern "C" {
extern int DAT_004514ac_Sound_Unk1;
extern int DAT_004514b0_Sound_Unk2;
extern int LEVELID_004a2a98;
extern char s_Snd__d_004514c8[];
extern int gSFXEnabled_00455c08;
extern void *gDirectSound_0049a070;
extern int DAT_0049fb20_Sound_Unk;
extern int DAT_0049fb18_DirectSound2;
extern SoundBuffer *PTR_ARRAY_0049fb30[];
extern unsigned int gSndSizes_00451048[];
extern void *gSNDPointerArray_0049f6b0[];
void __cdecl assertfail_00405350(const char *, ...);
int __cdecl SND_CreateDirectSoundBuffer_00401720(void *, SoundBuffer **, unsigned int, unsigned int);
int __cdecl SND_FillDirectSoundBuffer_004017d0(SoundBuffer *, unsigned int, void *, unsigned int);
}

extern "C" void __cdecl GEX_Target(int Sound, int Pan, int Unused, int Volume)
{
    SoundBuffer *buffer;
    unsigned int soundIndex;
    int adjustedVolume;

    if (Sound == 0xe7) {
        if (++DAT_004514ac_Sound_Unk1 != 5)
            return;
        DAT_004514ac_Sound_Unk1 = 0;
    }
    if (LEVELID_004a2a98 == 0x8a) {
        if (Sound == 0x46)
            return;
        if (Sound == 0x7a) {
            if (++DAT_004514b0_Sound_Unk2 != 3)
                return;
            DAT_004514b0_Sound_Unk2 = 0;
        }
    }

    soundIndex = Sound - 0x40;
    assertfail_00405350(s_Snd__d_004514c8, soundIndex);
    if (!gSFXEnabled_00455c08 || !gDirectSound_0049a070 || soundIndex >= 0x119)
        return;

    Volume = ((Volume - 128) * 2000) >> 7;
    adjustedVolume = DAT_0049fb20_Sound_Unk + Volume;
    if (adjustedVolume <= -5000)
        return;

    SoundBuffer *oldBuffer = PTR_ARRAY_0049fb30[DAT_0049fb18_DirectSound2];
    if (oldBuffer) {
        ((ReleaseMethod)oldBuffer->lpVtbl[2])(oldBuffer);
        PTR_ARRAY_0049fb30[DAT_0049fb18_DirectSound2] = 0;
    }

    if (SND_CreateDirectSoundBuffer_00401720(gDirectSound_0049a070, &buffer,
                                            gSndSizes_00451048[soundIndex], 0x2b11)) {
        if (SND_FillDirectSoundBuffer_004017d0(buffer, 0,
                                             gSNDPointerArray_0049f6b0[soundIndex],
                                             gSndSizes_00451048[soundIndex])) {
            int adjustedPan = (Pan * 2000) >> 7;
            ((ValueMethod)buffer->lpVtbl[15])(buffer, adjustedVolume);
            ((ValueMethod)buffer->lpVtbl[16])(buffer, adjustedPan);
            ((PlayMethod)buffer->lpVtbl[12])(buffer, 0, 0, 0);
        }
        SoundBuffer *savedBuffer = buffer;
        int nextSlot = DAT_0049fb18_DirectSound2 + 1;
        DAT_0049fb18_DirectSound2 = nextSlot;
        PTR_ARRAY_0049fb30[nextSlot - 1] = savedBuffer;
        if (nextSlot == 8)
            DAT_0049fb18_DirectSound2 = 0;
    }
}
