// DirectSound resources are rebuilt from logical/PCM state, never COM pointers.
#include "save_states.h"
struct Buffer { void **vtable; };
typedef long (__stdcall *CapsMethod)(Buffer *, void *);
typedef long (__stdcall *PositionMethod)(Buffer *, unsigned long *, unsigned long *);
typedef long (__stdcall *FormatMethod)(Buffer *, void *, unsigned long, unsigned long *);
typedef long (__stdcall *GetMethod)(Buffer *, long *);
typedef long (__stdcall *SetMethod)(Buffer *, long);
typedef long (__stdcall *LockMethod)(Buffer *, unsigned long, unsigned long, void **, unsigned long *, void **, unsigned long *, unsigned long);
typedef long (__stdcall *UnlockMethod)(Buffer *, void *, unsigned long, void *, unsigned long);
typedef long (__stdcall *SimpleMethod)(Buffer *);
typedef long (__stdcall *PlayMethod)(Buffer *, unsigned long, unsigned long, unsigned long);
typedef long (__stdcall *CreateMethod)(void *, void *, Buffer **, void *);
struct AudioBuffer {
    SSWord present, bytes, cursor, status;
    long volume, pan, frequency;
    unsigned char format[20];
    unsigned char *pcm;
    Buffer *staged;
};
struct AudioAsset { char name[260]; SSWord size,crc,offset,bytes; };
static AudioAsset identities[10];
struct SSAudio {
    AudioAsset assets[12]; // ten buffers, pending voice and pending music
    AudioBuffer buffers[10]; // music, voice, eight overlapping SFX
    SSWord variables[14];
    unsigned char ring[65536];
    char music[260];
    SSWord fileOpen, fileOffset, assetSize, assetCRC;
    void *file;
    SSAudio() { memset(this,0,sizeof(*this)); }
};
static const SSWord bufferSlots[] = {0x48a040,0x49a068,0x49fb30,0x49fb34,0x49fb38,
    0x49fb3c,0x49fb40,0x49fb44,0x49fb48,0x49fb4c};
static const SSWord variables[] = {0x48a030,0x48a034,0x48a038,0x48a044,0x49a050,
    0x49a054,0x49a058,0x49a05c,0x49a060,0x49fb18,0x49fb20,0x49fb50,0x4514ac,0x4514b0};
static volatile int holding, held;
static char musicPath[260];
static SSWord stoppedStatus[10];
static int stopped;
static const char *audioError;
const char *SSAudioError() { return audioError; }
extern "C" void __cdecl GEX_StateMusicOpened(const char *name) { sprintf(musicPath,"%.259s",name); }
extern "C" void __cdecl GEX_StateAudioAsset(unsigned int slot,const char *name,unsigned int offset,unsigned int bytes)
{
    if(slot>=10) return;
    memset(identities+slot,0,sizeof(AudioAsset));
    sprintf(identities[slot].name,"%.259s",name);
    identities[slot].offset=offset; identities[slot].bytes=bytes;
}
extern "C" void __cdecl GEX_StateSFXAsset(unsigned int slot,unsigned int sample)
{
    if(slot>=8 || sample>=281) return;
    SSWord source=ssw(0x49f6b0+sample*4), base=ssw(0x49fb54);
    GEX_StateAudioAsset(slot+2,(const char *)SSAddress(0x4514f8),source-base,ssw(0x451048+sample*4));
}
extern "C" void __cdecl GEX_StateAudioWorker(void)
{
    if(!holding) return;
    held=1;
    while(holding) Sleep(1);
    held=0;
}
int SSAudioHold()
{
    holding=1;
    unsigned long until=GetTickCount()+2000;
    while(!held && (long)(until-GetTickCount())>0) Sleep(1);
    if(!held) { holding=0; return 0; }
    return 1;
}
void SSAudioRelease()
{
    holding=0;
    unsigned long until=GetTickCount()+2000;
    while(held && (long)(until-GetTickCount())>0) Sleep(1);
}
void SSAudioDispose(SSAudio *a)
{
    if(!a) return;
    for(int i=0;i<10;++i) {
        free(a->buffers[i].pcm);
        if(a->buffers[i].staged) ((SimpleMethod)a->buffers[i].staged->vtable[2])(a->buffers[i].staged);
    }
    if(a->file) CloseHandle(a->file);
    delete a;
}
static int copyPCM(Buffer *buffer, unsigned char *pcm, SSWord bytes, int put)
{
    void *p1=0,*p2=0; unsigned long n1=0,n2=0;
    if(((LockMethod)buffer->vtable[11])(buffer,0,bytes,&p1,&n1,&p2,&n2,0)) return 0;
    int good=n1<=bytes && n2==bytes-n1;
    if(good) {
        if(put) { memcpy(p1,pcm,n1); if(n2) memcpy(p2,pcm+n1,n2); }
        else { memcpy(pcm,p1,n1); if(n2) memcpy(pcm+n1,p2,n2); }
    }
    if(((UnlockMethod)buffer->vtable[19])(buffer,p1,n1,p2,n2)) good=0;
    return good;
}
int SSAudioStopHardware()
{
    stopped=1;
    for(int i=0;i<10;++i) {
        stoppedStatus[i]=0;
        Buffer *b=(Buffer *)ssw(bufferSlots[i]);
        if(!b) continue;
        if(((GetMethod)b->vtable[9])(b,(long *)&stoppedStatus[i]) ||
           ((SimpleMethod)b->vtable[18])(b)) { SSAudioContinueHardware(); return 0; }
    }
    return 1;
}
void SSAudioContinueHardware()
{
    if(!stopped) return;
    for(int i=0;i<10;++i) {
        Buffer *b=(Buffer *)ssw(bufferSlots[i]);
        if(b && (stoppedStatus[i]&1)) ((PlayMethod)b->vtable[12])(b,0,0,stoppedStatus[i]&4?1:0);
    }
    stopped=0;
}
SSAudio *SSAudioCapture()
{
    audioError="AUDIO CAPTURE FAILED";
    SSAudio *a=new SSAudio;
    if(!a) return 0;
    for(int i=0;i<14;++i) a->variables[i]=ssw(variables[i]);
    memcpy(a->ring,SSAddress(0x48a050),sizeof(a->ring));
    sprintf(a->music,"%s",musicPath);
    void *file=(void *)ssw(0x48a04c);
    if(*a->music && !SSFileIdentity(a->music,&a->assetSize,&a->assetCRC)) { audioError="MUSIC ASSET DIFFERS OR IS MISSING"; SSAudioDispose(a); return 0; }
    if(file) { a->fileOpen=1; a->fileOffset=SetFilePointer(file,0,0,1); }
    memcpy(a->assets,identities,sizeof(identities));
    memset(a->assets,0,sizeof(AudioAsset));
    if(*a->music) sprintf(a->assets[0].name,"%s",a->music);
    if((long)a->variables[5]>0) sprintf(a->assets[10].name,(const char *)SSAddress(0x4514b8),a->variables[5]);
    if((long)a->variables[1]>0) sprintf(a->assets[11].name,(const char *)SSAddress(0x451700),a->variables[1]);
    for(i=0;i<12;++i) {
        AudioAsset &asset=a->assets[i];
        if(i<10 && !ssw(bufferSlots[i])) { memset(&asset,0,sizeof(asset)); continue; }
        if(*asset.name && (!SSFileIdentity(asset.name,&asset.size,&asset.crc) ||
            asset.offset>asset.size || asset.bytes>asset.size-asset.offset)) { audioError="AUDIO ASSETS DIFFER OR ARE MISSING"; goto failed; }
    }
    for(i=0;i<10;++i) {
        Buffer *buffer=(Buffer *)ssw(bufferSlots[i]);
        if(!buffer) continue;
        AudioBuffer &b=a->buffers[i]; b.present=1;
        SSWord caps[5]={20,0,0,0,0}; unsigned long ignored;
        if(((CapsMethod)buffer->vtable[3])(buffer,caps) || !caps[2] || caps[2]>8*1024*1024 ||
            ((PositionMethod)buffer->vtable[4])(buffer,(unsigned long *)&b.cursor,&ignored) ||
            ((GetMethod)buffer->vtable[9])(buffer,(long *)&b.status)) goto failed;
        // Stop before reading PCM/ring so hardware cannot advance during capture.
        if(((SimpleMethod)buffer->vtable[18])(buffer)) goto failed;
        b.bytes=caps[2]; b.pcm=(unsigned char *)malloc(b.bytes);
        if(!b.pcm || ((FormatMethod)buffer->vtable[5])(buffer,b.format,18,&ignored) ||
            ((GetMethod)buffer->vtable[6])(buffer,&b.volume) ||
            ((GetMethod)buffer->vtable[7])(buffer,&b.pan) ||
            ((GetMethod)buffer->vtable[8])(buffer,&b.frequency) ||
            !copyPCM(buffer,b.pcm,b.bytes,0)) goto failed;
    }
    return a;
failed:
    SSAudioResume(a); SSAudioDispose(a); return 0;
}
void SSAudioResume(SSAudio *a)
{
    if(!a) return;
    for(int i=0;i<10;++i) {
        AudioBuffer &b=a->buffers[i]; Buffer *buffer=(Buffer *)ssw(bufferSlots[i]);
        if(b.present && buffer && (b.status&1))
            ((PlayMethod)buffer->vtable[12])(buffer,0,0,b.status&4?1:0);
    }
}
int SSAudioWrite(SSAudio *a, SSBuffer &out)
{
    if(!a) return 0;
    out.append(a->variables,sizeof(a->variables)); out.append(a->ring,sizeof(a->ring));
    out.append(a->music,260); out.word(a->fileOpen); out.word(a->fileOffset);
    out.word(a->assetSize); out.word(a->assetCRC);
    for(int i=0;i<10;++i) {
        AudioBuffer &b=a->buffers[i]; out.word(b.present);
        if(b.present) {
            out.word(b.bytes); out.word(b.cursor); out.word(b.status);
            out.word(b.volume); out.word(b.pan); out.word(b.frequency);
            out.append(b.format,18); out.append(b.pcm,b.bytes);
        }
    }
    out.word(0x44495541); out.word(sizeof(a->assets)); out.append(a->assets,sizeof(a->assets));
    return out.good;
}
int SSAudioReadIdentities(SSAudio *a,const void *data,SSWord bytes)
{
    if(bytes!=sizeof(a->assets)) { audioError="INVALID AUDIO ASSET TABLE"; return 0; }
    memcpy(a->assets,data,bytes);
    for(int i=0;i<12;++i) {
        AudioAsset &asset=a->assets[i]; SSWord size,crc;
        if(asset.name[259]) { audioError="INVALID AUDIO ASSET TABLE"; return 0; }
        if(!*asset.name) continue;
        if(!SSFileIdentity(asset.name,&size,&crc) || size!=asset.size || crc!=asset.crc ||
            asset.offset>size || asset.bytes>size-asset.offset) {
            audioError="AUDIO ASSETS DIFFER OR ARE MISSING"; return 0;
        }
    }
    return 1;
}
static int prepare(AudioBuffer &b)
{
    struct Desc { SSWord size, flags, bytes, reserved; void *format; } desc;
    if(!ssw(0x49a070)) return 0;
    desc.size=sizeof(desc); desc.flags=0xe8; desc.bytes=b.bytes; desc.reserved=0; desc.format=b.format;
    void *device=(void *)ssw(0x49a070);
    if(((CreateMethod)(*(void ***)device)[3])(device,&desc,&b.staged,0)) return 0;
    return copyPCM(b.staged,b.pcm,b.bytes,1) &&
        !((SetMethod)b.staged->vtable[13])(b.staged,b.cursor) &&
        !((SetMethod)b.staged->vtable[15])(b.staged,b.volume) &&
        !((SetMethod)b.staged->vtable[16])(b.staged,b.pan) &&
        !((SetMethod)b.staged->vtable[17])(b.staged,b.frequency);
}
SSAudio *SSAudioRead(SSBuffer &in, SSWord version)
{
    audioError="INVALID AUDIO STATE";
    SSAudio *a=new SSAudio;
    if(!a) return 0;
    in.read(a->variables,sizeof(a->variables)); in.read(a->ring,sizeof(a->ring));
    in.read(a->music,260); a->fileOpen=in.take(); a->fileOffset=in.take();
    a->assetSize=in.take(); a->assetCRC=in.take();
    SSWord size,crc; int i;
    if(!in.good || a->music[259] || a->fileOpen>1) goto failed;
    if(*a->music && (!SSFileIdentity(a->music,&size,&crc) || size!=a->assetSize || crc!=a->assetCRC)) {
        audioError="MUSIC ASSET DIFFERS OR IS MISSING"; goto failed;
    }
    if(a->fileOpen) {
        a->file=CreateFileA(a->music,0x80000000U,1,0,3,0x08000000U,0);
        if(a->file==(void *)-1) { a->file=0; goto failed; }
        if(a->fileOffset>a->assetSize || SetFilePointer(a->file,a->fileOffset,0,0)==0xffffffffU) goto failed;
    }
    for(i=0;i<10;++i) {
        AudioBuffer &b=a->buffers[i]; b.present=in.take();
        if(b.present>1) goto failed;
        if(!b.present) continue;
        b.bytes=in.take(); b.cursor=in.take(); b.status=in.take();
        b.volume=in.take(); b.pan=in.take(); b.frequency=in.take(); in.read(b.format,18);
        if(!in.good || !b.bytes || b.bytes>8*1024*1024) goto failed;
        // Wire v1 stored PCM frame indexes; v2 stores byte cursors. The field
        // identity and migration do not depend on compiler/link addresses.
        SSWord align=*(unsigned short *)(b.format+12);
        SSWord channels=*(unsigned short *)(b.format+2), bits=*(unsigned short *)(b.format+14);
        SSWord rate=*(SSWord *)(b.format+4), average=*(SSWord *)(b.format+8);
        if((channels!=1 && channels!=2) || (bits!=8 && bits!=16) || !rate || rate>200000 ||
           align!=channels*(bits/8) || average!=rate*align || b.bytes%align || *(unsigned short *)(b.format+16)) goto failed;
        if(version==1) {
            if(b.cursor>=b.bytes/align) goto failed;
            b.cursor*=align;
        }
        if(b.cursor>=b.bytes || *(unsigned short *)b.format!=1 ||
            b.volume>0 || b.volume<-10000 || b.pan<-10000 || b.pan>10000 ||
            b.frequency<100 || b.frequency>200000) goto failed;
        b.pcm=(unsigned char *)malloc(b.bytes);
        if(!b.pcm || !in.read(b.pcm,b.bytes)) goto failed;
        if(!prepare(b)) { audioError="AUDIO RESOURCE ALLOCATION FAILED"; goto failed; }
    }
    return a;
failed:
    SSAudioDispose(a); return 0;
}
int SSAudioCommit(SSAudio *a)
{
    stopped=0;
    memcpy(identities,a->assets,sizeof(identities));
    Buffer *preview=(Buffer *)ssw(0x49fb28);
    if(preview) { ((SimpleMethod)preview->vtable[18])(preview); ((SimpleMethod)preview->vtable[2])(preview); ssw(0x49fb28)=0; }
    // prepare() already created, filled, and configured every replacement buffer.
    for(int i=0;i<10;++i) {
        Buffer *old=(Buffer *)ssw(bufferSlots[i]);
        if(old) { ((SimpleMethod)old->vtable[18])(old); ((SimpleMethod)old->vtable[2])(old); }
        ssw(bufferSlots[i])=(SSWord)a->buffers[i].staged; a->buffers[i].staged=0;
    }
    if(ssw(0x48a04c)) CloseHandle((void *)ssw(0x48a04c));
    ssw(0x48a04c)=(SSWord)a->file; a->file=0;
    for(i=0;i<14;++i) ssw(variables[i])=a->variables[i];
    memcpy(SSAddress(0x48a050),a->ring,sizeof(a->ring));
    sprintf(musicPath,"%s",a->music);
    return 1;
}
