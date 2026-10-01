// Portable graph snapshots for the source replacement. Not a byte-match source.
#include "save_states.h"

extern "C" {
void __cdecl TXT_DrawPrintP_0043fa70(int, int, char *, int);
void __cdecl DRAW_CacheClear_0043e430(int);
void __cdecl DRAW_CacheInit_0043e350(void);
void __cdecl FUN_0043eb50_LoadTilePoss(void *, int);
int __cdecl M1_PlayLevel_0040a010(void *);
void __cdecl M1_GameLoop_0040ad40(void);
void __cdecl FUN_0040b2d0_InputProcessing(void);
void __cdecl GFX_Flush_00406c30(void);
void __cdecl BLOC_BlockLoader_0040b460(void);
void __cdecl M1_ExitLevel_0040a660(void *);
void __cdecl M1_FreeLevel_0040aa60(void);
void __cdecl GEX_SpriteViewerClose(void);
void __cdecl GEX_MainMenuClose(void);
int __cdecl GEX_SpriteViewerActive(void);
int GEX_StateFont[5];
}

static const SSWord MAX_BYTES = 32 * 1024 * 1024;
static const SSWord DYNAMIC = 0x80000000U;
static const SSWord FONT = 0x70000001U;
static const SSWord PIXELS = 0x70000002U;
static const int STATIC_COUNT = 12;
static const int HEAP_LIMIT = 40;
static const int ASSET_LIMIT = 512;
struct Chunk { SSWord id, size; unsigned char *data, *mask; };
struct Reference { SSWord source, at, kind, target, offset; };
struct Asset { char name[260]; SSWord size, crc; };
struct Resource { SSWord id, owner, at, size, asset, fileOffset; };
struct File { void *handle; char name[260]; SSWord offset; };
struct World {
    Chunk chunks[64]; SSWord count;
    Reference *refs; SSWord nrefs;
    Asset assets[ASSET_LIMIT]; SSWord nassets;
    File files[8]; SSWord nfiles;
    Resource resources[2048]; SSWord nresources;
    SSAudio *audio;
    SSWord level, sequenceOffset, paused, returnLevel;
    World() { memset(this, 0, sizeof(*this)); sequenceOffset=returnLevel=0xffffffffU; }
    ~World();
};
static Chunk heaps[HEAP_LIMIT], statics[STATIC_COUNT];
static int initialized, trackingError;
static unsigned char activeObjects[100];
static SSWord nextId = 1;
static Asset history[ASSET_LIMIT];
static SSWord historyCount;
static Resource resources[2048];
static SSWord resourceCount, nextResource=1;
static File opened[8];
static volatile unsigned readRequest, writeRequest;
static unsigned requests[32];
static volatile int busy;
static volatile long mutations, deferredActivation;
static volatile unsigned latestActivation=1;
static int selectedSlot;
static int deferred;
static int videoNotice;
static char message[192];
static unsigned long messageUntil;
static World *pending;
static SSWord sequenceOffset=0xffffffffU;
static int resumeSequence;
static SSWord returnLevel=0xffffffffU;
static SSFunction replacements[16];
static int replacementCount;

SSBuffer::SSBuffer() { data = 0; size = capacity = position = 0; good = 1; }
SSBuffer::~SSBuffer() { free(data); }
int SSBuffer::append(const void *p, SSWord n)
{
    if (!good || n > MAX_BYTES - size) return good = 0;
    if (size + n > capacity) {
        SSWord want = capacity ? capacity * 2 : 4096;
        if (want < size + n) want = size + n;
        if (want > MAX_BYTES) want = MAX_BYTES;
        unsigned char *next = (unsigned char *)malloc(want);
        if (!next) return good = 0;
        if (size) memcpy(next, data, size);
        free(data); data = next; capacity = want;
    }
    if (n) memcpy(data + size, p, n);
    size += n; return 1;
}
int SSBuffer::read(void *p, SSWord n)
{
    if (!good || position > size || n > size - position) return good = 0;
    if (n) memcpy(p, data + position, n);
    position += n; return 1;
}
int SSBuffer::word(SSWord v) { return append(&v, 4); }
SSWord SSBuffer::take() { SSWord v = 0; read(&v, 4); return v; }

extern "C" void *__cdecl SSAddress(SSWord id)
{
    for (int i = 0; i < 3; ++i)
        if (id >= SSImages[i].id && id - SSImages[i].id < SSImages[i].size)
            return SSImages[i].address + id - SSImages[i].id;
    return 0;
}
extern "C" void __cdecl GEX_StateRegisterCallback(unsigned int id,void *address)
{
    if(id<0x60000000 || id>=0x70000000 || !address) { trackingError=1; return; }
    for(int i=0;i<replacementCount;++i) if(replacements[i].id==id) {
        if(replacements[i].address!=address) trackingError=1;
        return;
    }
    if(replacementCount==16) { trackingError=1; return; }
    replacements[replacementCount].id=id; replacements[replacementCount++].address=address;
}
static SSWord functionId(SSWord value)
{
    for(int r=0;r<replacementCount;++r) if((SSWord)replacements[r].address==value) return replacements[r].id;
    for (SSWord i = 0; i < SSFunctionCount; ++i)
        if ((SSWord)SSFunctions[i].address == value) return SSFunctions[i].id;
    return 0;
}
extern "C" int __cdecl GEX_StateFunctionValid(void *p) { return functionId((SSWord)p)!=0; }
static void *functionAddress(SSWord id)
{
    for(int r=0;r<replacementCount;++r) if(replacements[r].id==id) return replacements[r].address;
    for (SSWord i = 0; i < SSFunctionCount; ++i)
        if (SSFunctions[i].id == id) return SSFunctions[i].address;
    return 0;
}
static void notice(const char *text)
{
    sprintf(message, "SLOT %d: %.160s", selectedSlot, text);
    messageUntil = GetTickCount() + 3000;
    OutputDebugStringA(message); OutputDebugStringA("\r\n");
    if(ssw(0x4a294c)==2) {
        char title[224]; sprintf(title,"GEX - %s",message);
        SetWindowTextA((void *)ssw(0x4875a0),title); videoNotice=1;
    }
}
static Chunk *containing(void *p)
{
    SSWord a = (SSWord)p;
    for (int i = 0; i < HEAP_LIMIT; ++i)
        if (heaps[i].data && a >= (SSWord)heaps[i].data && a - (SSWord)heaps[i].data < heaps[i].size) return heaps + i;
    for (i = 0; i < STATIC_COUNT; ++i)
        if (statics[i].data && a >= (SSWord)statics[i].data && a - (SSWord)statics[i].data < statics[i].size) return statics + i;
    return 0;
}
static void mark(void *p, unsigned char kind)
{
    Chunk *c = containing(p);
    if (c && c->mask) {
        SSWord off = (unsigned char *)p - c->data;
        if (off + (kind == 3 ? 2 : 4) <= c->size) c->mask[off] = kind;
        else trackingError = 1;
    }
}
static void initialize()
{
    if (initialized) return;
    initialized = 1;
    // Original-address IDs retain their ABI across replacement link layouts.
    const SSWord ranges[][2] = {
        {0x455b00, 0x461000}, {0x461180, 0x461184},
        {0x4626d0, 0x464e28}, {0x46a530, 0x46d000},
        {0x4a0200, 0x4a2b0c}, {0x47ef70, 0x47f004},
        {0x455998, 0x45599c}, {0x49f6b0,0x49fb14},
        {0x49fb54,0x49fb58}, {0x49fb90,0x4a0200}
    };
    for (int i = 0; i < 10; ++i) {
        statics[i].id = ranges[i][0];
        statics[i].size = ranges[i][1] - ranges[i][0];
        statics[i].data = (unsigned char *)SSAddress(ranges[i][0]);
        statics[i].mask = (unsigned char *)malloc(statics[i].size);
        if (!statics[i].data || !statics[i].mask) { trackingError = 1; continue; }
        memset(statics[i].mask, 0, statics[i].size);
    }
    statics[10].id = FONT; statics[10].size = sizeof(GEX_StateFont);
    statics[10].data = (unsigned char *)GEX_StateFont;
    statics[10].mask = (unsigned char *)malloc(statics[10].size);
    if (statics[10].mask) memset(statics[10].mask, 0, statics[10].size);
    else trackingError = 1;
    for (SSWord n = 0; n < SSInitialPointerCount; ++n)
        mark(SSAddress(SSInitialPointers[n]), 1);
}
extern "C" void __cdecl GEX_StateAllocated(void *p, unsigned int size)
{
    initialize();
    for (int i = 0; i < HEAP_LIMIT; ++i) if (!heaps[i].data) {
        heaps[i].id = DYNAMIC | nextId++; heaps[i].data = (unsigned char *)p;
        heaps[i].size = size; heaps[i].mask = (unsigned char *)malloc(size);
        if (!heaps[i].mask) trackingError = 1;
        else memset(heaps[i].mask, 0, size);
        return;
    }
    trackingError = 1;
}
extern "C" void __cdecl GEX_StateFreed(void *p)
{
    for (int i = 0; i < HEAP_LIMIT; ++i) if (heaps[i].data == p) {
        SSWord id=heaps[i].id;
        for(SSWord n=0;n<resourceCount;) {
            if(resources[n].owner==id) resources[n]=resources[--resourceCount]; else ++n;
        }
        free(heaps[i].mask); memset(heaps + i, 0, sizeof(Chunk)); return;
    }
}
extern "C" void __cdecl GEX_StatePointer(void *p) { initialize(); mark(p, 1); }
static unsigned char pointerKind(const void *p)
{
    Chunk *c=containing((void *)p);
    if(!c) return 0;
    SSWord offset=(const unsigned char *)p-c->data;
    unsigned char kind=c->mask[offset];
    if(kind==1 || kind==4) return 4;
    unsigned char *objects=(unsigned char *)ssw(0x4a27a0);
    if(objects && (SSWord)p>=(SSWord)objects && (SSWord)p-(SSWord)objects<100*0x204) {
        offset=((SSWord)p-(SSWord)objects)%0x204;
        const int fields[]={0xc,0x58,0x5c,0x60,0x64,0xc0,0x110,0x15c,0x160,0x164,0x16c,0x170,0x174,0x178,0x180,0x18c,0x190};
        for(int i=0;i<sizeof(fields)/sizeof(*fields);++i) if(offset==fields[i]) return 4;
        unsigned char *object=objects+(((SSWord)p-(SSWord)objects)/0x204)*0x204;
        for(i=0;i<4;++i) {
            SSWord callback=functionId(*(SSWord *)(object+0x58+i*4));
            for(SSWord n=0;n<SSObjectFieldCount;++n)
                if(SSObjectFields[n].callback==callback && SSObjectFields[n].offset==offset) return 4;
        }
    }
    return 0;
}
extern "C" void __cdecl GEX_StateCopyKind(void *dst,const void *src) { mark(dst,pointerKind(src)); }
extern "C" void __cdecl GEX_StateSwapKind(void *a,void *b)
{
    unsigned char ak=pointerKind(a),bk=pointerKind(b); mark(a,bk); mark(b,ak);
}
extern "C" void __cdecl GEX_StateHandle(void *p) { initialize(); mark(p, 2); }
extern "C" void __cdecl GEX_StateCacheSlot(void *p) { initialize(); mark(p, 3); }
extern "C" void __cdecl GEX_StateClear(void *p, unsigned int n)
{
    Chunk *c = containing(p);
    if (c && c->mask) {
        SSWord off = (unsigned char *)p - c->data;
        if (n <= c->size - off) {
            memset(c->mask + off, 0, n);
            if(n>=8192) for(SSWord i=0;i<resourceCount;) {
                Resource &r=resources[i];
                if(r.owner==c->id && r.at<off+n && off<r.at+r.size) r=resources[--resourceCount];
                else ++i;
            }
        }
    }
}
static int same(const char *a, const char *b)
{
    while (*a && *a == *b) { ++a; ++b; } return *a == *b;
}
static int safePath(const char *p)
{
    if (!*p || *p == '/' || *p == '\\') return 0;
    for (int n = 0; p[n]; ++n)
        if (n >= 259 || p[n] == ':' || (p[n] == '.' && p[n+1] == '.')) return 0;
    return 1;
}
static SSWord checksum(const unsigned char *data, SSWord n, SSWord crc = 0xffffffffU)
{
    while (n--) {
        crc ^= *data++;
        for (int bit = 0; bit < 8; ++bit) crc = (crc >> 1) ^ (0xedb88320U & (0U - (crc & 1)));
    }
    return crc;
}
extern "C" int __cdecl SSFileIdentity(const char *name, SSWord *size, SSWord *crc)
{
    if (!safePath(name)) return 0;
    void *h = CreateFileA(name, 0x80000000U, 1, 0, 3, 0x08000000U, 0);
    if (h == (void *)-1) return 0;
    unsigned char bytes[4096]; unsigned long read;
    SSWord sum = 0xffffffffU, total = 0;
    for (;;) {
        if (!ReadFile(h, bytes, sizeof(bytes), &read, 0)) { CloseHandle(h); return 0; }
        if (!read) break;
        sum = checksum(bytes, read, sum); total += read;
    }
    CloseHandle(h); *size = total; *crc = ~sum; return 1;
}
extern "C" void __cdecl GEX_StateFileOpened(void *h, const char *name)
{
    if (!safePath(name)) { trackingError = 1; return; }
    int i;
    for (i = 0; i < 8; ++i) if (!opened[i].handle) {
        opened[i].handle = h; sprintf(opened[i].name, "%s", name); break;
    }
    if (i == 8) trackingError = 1;
    for (SSWord n = 0; n < historyCount; ++n) if (same(name, history[n].name)) return;
    if (historyCount == ASSET_LIMIT) { trackingError = 1; return; }
    sprintf(history[historyCount++].name, "%s", name);
}
extern "C" void __cdecl GEX_StateFileClosed(void *h)
{
    for (int i = 0; i < 8; ++i) if (opened[i].handle == h) memset(opened + i, 0, sizeof(File));
}
static void resource(void *memory,SSWord bytes,SSWord asset,SSWord fileOffset)
{
    Chunk *c=containing(memory);
    if(!c || !bytes) return;
    SSWord at=(unsigned char *)memory-c->data;
    if(bytes>c->size-at) { trackingError=1; return; }
    for(SSWord i=0;i<resourceCount;) {
        Resource &r=resources[i];
        if(r.owner==c->id && r.at<at+bytes && at<r.at+r.size) r=resources[--resourceCount];
        else ++i;
    }
    if(resourceCount==2048) { trackingError=1; return; }
    Resource &r=resources[resourceCount++];
    r.id=nextResource++; r.owner=c->id; r.at=at; r.size=bytes; r.asset=asset; r.fileOffset=fileOffset;
}
extern "C" void __cdecl GEX_StateResourceRead(void *file,void *memory,unsigned int bytes)
{
    for(int i=0;i<8;++i) if(opened[i].handle==file) {
        SSWord end=SetFilePointer(file,0,0,1);
        if(end==0xffffffffU || bytes>end) { trackingError=1; return; }
        for(SSWord n=0;n<historyCount;++n) if(same(opened[i].name,history[n].name)) {
            resource(memory,bytes,n,end-bytes); return;
        }
    }
}
extern "C" void __cdecl GEX_StateResourceCopy(void *dest,const void *source,unsigned int bytes)
{
    Chunk *c=containing((void *)source);
    if(!c) return;
    SSWord offset=(const unsigned char *)source-c->data;
    for(SSWord i=0;i<resourceCount;++i) {
        Resource r=resources[i];
        if(r.owner==c->id && offset>=r.at && offset-r.at<r.size) {
            SSWord n=r.size-(offset-r.at); if(n>bytes) n=bytes;
            resource(dest,n,r.asset,r.fileOffset+offset-r.at); return;
        }
    }
}
static void flushActivation()
{
    if(InterlockedExchange((long *)&deferredActivation,0))
        PostMessageA((void *)ssw(0x4875a0),0x8002,0,0);
}
static void unblock() { busy=0; flushActivation(); }
extern "C" int __cdecl GEX_StateMutationBegin(void)
{
    InterlockedIncrement((long *)&mutations);
    if(busy) { InterlockedDecrement((long *)&mutations); return 0; }
    return 1;
}
extern "C" void __cdecl GEX_StateMutationEnd(void) { InterlockedDecrement((long *)&mutations); }
extern "C" void __cdecl GEX_StateActivation(unsigned int value) { latestActivation=value; }
extern "C" unsigned int __cdecl GEX_StateLatestActivation(void) { return latestActivation; }
extern "C" void __cdecl GEX_StateDeferActivation(void)
{
    InterlockedExchange((long *)&deferredActivation,1);
    if(!busy) flushActivation();
}
extern "C" int __cdecl GEX_StateBusy(void) { return busy; }
extern "C" int __cdecl GEX_StatePending(void) { return pending != 0; }
extern "C" int __cdecl GEX_StateKey(unsigned int key, long flags)
{
    if (key != 0x74 && key != 0x78 && (key < '0' || key > '9')) return 0;
    if (!(flags & 0x40000000) && writeRequest - readRequest < 32) {
        requests[writeRequest & 31] = key; ++writeRequest;
    }
    return 1;
}
extern "C" void __cdecl GEX_StateUITick(void)
{
    if(videoNotice && (long)(messageUntil-GetTickCount())<=0) {
        SetWindowTextA((void *)ssw(0x4875a0),"GEX"); videoNotice=0;
    }
}
extern "C" void __cdecl GEX_StateDraw(void)
{
    if ((long)(messageUntil - GetTickCount()) > 0)
        TXT_DrawPrintP_0043fa70(8 << 16, 8 << 16, message, 0);
}

// Declare runtime roots and intrusive-link layouts. Descriptors are based on
// loads/stores in the reconstructed sources, never on a numeric address scan.
static void schema()
{
    const SSWord roots[] = {0x455b7c,0x455b78,0x455b80,0x455b84,0x460e08,0x460f6c,
        0x626f8+0x400000,0x462704,0x462708,0x46270c,0x46271c,0x463a30,0x463a38,
        0x47f000,0x4a27a0,0x4a27dc,0x4a27fc,0x4a2934,0x4a2990,0x4a2a10,
        0x4a2a78,0x4a2ad4,0x4a2ad8,0x4a2adc,0x4a2ae0,0x4a2ae4,0x4a2ae8};
    for (int i = 0; i < sizeof(roots)/sizeof(*roots); ++i) mark(SSAddress(roots[i]),1);
    if(!statics[11].mask) {
        statics[11].id=PIXELS; statics[11].size=0x100000;
        statics[11].mask=(unsigned char *)malloc(statics[11].size);
        if(!statics[11].mask) trackingError=1;
        else memset(statics[11].mask,0,statics[11].size);
    }
    statics[11].data=(unsigned char *)ssw(0x4a33ac);
    mark(SSAddress(0x49fb94),1); mark(SSAddress(0x49fb98),1);
    mark(GEX_StateFont,1); mark(GEX_StateFont+1,1);
    for(i=0;i<281;++i) mark(SSAddress(0x49f6b0+i*4),1);
    // Allocation tracker contains pointers, including empty slots.
    for (i = 0; i < 32; ++i) mark(SSAddress(0x47ef80 + i*4),1);
    const SSWord lists[] = {0x4a27b0,0x4a28a0,0x463680,0x463698,0x463728};
    for (i = 0; i < 5; ++i) {
        int count = i == 1 ? 10 : i == 3 ? 12 : 1;
        for (int j = 0; j < count; ++j) {
            mark(SSAddress(lists[i] + j*12),1);
            mark(SSAddress(lists[i] + j*12+8),1);
        }
    }
    unsigned char *objects = (unsigned char *)ssw(0x4a27a0);
    memset(activeObjects,0,sizeof(activeObjects));
    if(objects) for(i=0;i<10;++i) {
        SSWord node=ssw(0x4a28a0+i*12);
        for(int n=0;n<100;++n) {
            if(node<(SSWord)objects || node-(SSWord)objects>=100*0x204 || (node-(SSWord)objects)%0x204) break;
            activeObjects[(node-(SSWord)objects)/0x204]=1;
            node=*(SSWord *)node;
        }
    }
    if (objects) for (i = 0; i < 100; ++i) {
        unsigned char *p = objects + i*0x204;
        // Free nodes retain garbage outside next/previous until memset on reuse.
        // Clear stale per-role metadata before adding the current callback schema.
        Chunk *owner=containing(p);
        if(owner) for(int b=0;b<0x204;++b) {
            unsigned char &kind=owner->mask[p-owner->data+b];
            if(kind!=4) kind=0;
        }
        mark(p,1); mark(p+4,1);
        if (!activeObjects[i]) continue;
        const int offsets[] = {0xc,0x58,0x5c,0x60,0x64,0xc0,0x110,0x15c,0x160,0x164,0x16c,
            0x170,0x174,0x178,0x180,0x18c,0x190};
        for (int j = 0; j < sizeof(offsets)/sizeof(*offsets); ++j) mark(p+offsets[j],1);
        for(j=0;j<2;++j) {
            unsigned char *state=p+0x10+j*0x20;
            mark(state,1);
            SSWord depth=*(SSWord *)(state+8);
            if(depth>4) { trackingError=1; break; }
            for(SSWord n=1;n<=depth;++n) mark(state+(n+3)*4,1);
        }
        for(j=0;j<12;++j) mark(p+0x198+j*8,1);
        for (j = 0; j < 4; ++j) {
            SSWord id = functionId(*(SSWord *)(p+0x58+j*4));
            for (SSWord k=0;k<SSObjectFieldCount;++k)
                if (SSObjectFields[k].callback == id) mark(p+SSObjectFields[k].offset,1);
        }
    }
    // Parallax draw callback consumes work2/work3 even after its init callback is cleared.
    if(objects) for(i=0;i<100;++i) if(activeObjects[i] && functionId(*(SSWord *)(objects+i*0x204+0x60))==0x41fec0) {
        mark(objects+i*0x204+0xa0,1); mark(objects+i*0x204+0xa4,1);
    }
    for(i=0;i<8;++i) { mark(SSAddress(0x463a40+i*12),1); mark(SSAddress(0x463a44+i*12),1); }
    // Identify collision allocation owners through their list roots, rather
    // than interpreting unrelated allocations of the same length as nodes.
    for(i=0;i<14;++i) {
        SSWord head=ssw(i==0?0x463728:i==1?0x463680:0x463698+(i-2)*12);
        Chunk *pool=containing((void *)head);
        if(pool && (pool->id&DYNAMIC) && pool->size==100*12)
            for(SSWord n=0;n<pool->size;n+=4) mark(pool->data+n,1);
    }
    SSWord trackerTable = ssw(0x4a2a78), count = ssw(0x4626fc);
    if (count < 1024 && trackerTable) for (SSWord n=0;n<count;++n) {
        mark((void *)(trackerTable+n*4),1);
        SSWord tracker = *(SSWord *)(trackerTable+n*4);
        if (tracker) { mark((void *)tracker,1); mark((void *)(tracker+4),1); }
    }
    SSWord table = ssw(0x46271c), blocks = ssw(0x462734);
    if (table && blocks < 16384) for (SSWord n=0;n<blocks+1;++n) mark((void *)(table+n*4),1);
    // Stable M1 records and input-playback buffer roots.
    for (i=0;i<2;++i) {
        SSWord p = ssw(0x455b80+i*4);
        const int offsets[] = {0,4,8,12,20,24,28,32};
        if (p) for (int j=0;j<8;++j) mark((void *)(p+offsets[j]),1);
    }
    if (ssw(0x4a27dc)) for (i=0;i<2;++i) mark((void *)(ssw(0x4a27dc)+i*0x24+0x14),1);
    // Tile tables have two pointers followed by a scalar pixel-control word.
    for (i=0;i<700;++i) { mark(SSAddress(0x4a02f0+i*12),1); mark(SSAddress(0x4a02f4+i*12),1); }
    for (i=0;i<64;++i) mark(SSAddress(0x463740+i*4),1);
    // Directory entries and logical subfiles carry operating-system handles.
    const SSWord dirs[] = {0x455b78,0x455b7c,0x455998};
    for (i=0;i<3;++i) {
        SSWord d=ssw(dirs[i]); if (d) { mark((void *)(d+4),1); mark((void *)(d+8),2); }
    }
    // Completed request records can contain dead stack destinations; they have
    // no remaining work at the capture boundary and are canonicalized on save.
}
World::~World()
{
    for (SSWord i=0;i<count;++i) {
        if (chunks[i].id & DYNAMIC) GlobalFree(chunks[i].data);
        else free(chunks[i].data);
        free(chunks[i].mask);
    }
    for (i=0;i<nfiles;++i) if (files[i].handle) CloseHandle(files[i].handle);
    free(refs); SSAudioDispose(audio);
}
static Chunk *chunk(World *w, SSWord id)
{
    for (SSWord i=0;i<w->count;++i) if (w->chunks[i].id==id) return w->chunks+i;
    return 0;
}
static int encode(World *w, Reference &r, SSWord value, int file)
{
    r.kind=0; r.target=value; r.offset=0;
    if (!value || value==0xffffffffU) return 1;
    if (file) {
        if (value<=2) return 1;
        for (SSWord i=0;i<w->nfiles;++i) if ((SSWord)opened[i].handle==value) {
            r.kind=4; r.target=i; return 1;
        }
        return 0;
    }
    r.target=functionId(value);
    if (r.target) { r.kind=2; return 1; }
    for(SSWord n=0;n<w->nresources;++n) {
        Resource &res=w->resources[n]; Chunk *live=0;
        for(int i=0;i<HEAP_LIMIT;++i) if(heaps[i].id==res.owner) live=heaps+i;
        for(i=0;i<STATIC_COUNT;++i) if(statics[i].id==res.owner) live=statics+i;
        if(live && value>=(SSWord)live->data+res.at && value-((SSWord)live->data+res.at)<res.size) {
            r.kind=5; r.target=res.id; r.offset=value-((SSWord)live->data+res.at); return 1;
        }
    }
    for (int k=0;k<HEAP_LIMIT+STATIC_COUNT;++k) {
        Chunk &c=k<HEAP_LIMIT?heaps[k]:statics[k-HEAP_LIMIT];
        if (c.data && value>=(SSWord)c.data && value-(SSWord)c.data<=c.size) {
            r.kind=1; r.target=c.id; r.offset=value-(SSWord)c.data; return 1;
        }
    }
    for (k=0;k<3;++k) if (value>=(SSWord)SSImages[k].address &&
        value-(SSWord)SSImages[k].address<SSImages[k].size) {
        r.kind=3; r.target=SSImages[k].id+value-(SSWord)SSImages[k].address; return 1;
    }
    // Explicit pointer fields also permit small sentinel/control values.
    if (value<65536) { r.kind=0; r.target=value; return 1; }
    return 0;
}
static int decode(World *w, Reference &r, SSWord &value)
{
    switch(r.kind) {
    case 0: value=r.target; return r.offset==0 && (value<65536 || value==0xffffffffU);
    case 1: { Chunk *c=chunk(w,r.target); if (!c || r.offset>c->size) return 0;
        value=(SSWord)c->data+r.offset; return 1; }
    case 2: value=(SSWord)functionAddress(r.target); return value!=0 && r.offset==0;
    case 3: value=(SSWord)SSAddress(r.target); return value!=0 && r.offset==0;
    case 5: {
        for(SSWord i=0;i<w->nresources;++i) if(w->resources[i].id==r.target) {
            Resource &res=w->resources[i]; Chunk *c=chunk(w,res.owner);
            if(!c || r.offset>=res.size) return 0;
            value=(SSWord)c->data+res.at+r.offset;
            if(!(res.owner&DYNAMIC)) {
                unsigned char *live=res.owner==FONT?(unsigned char *)GEX_StateFont:
                    res.owner==PIXELS?statics[11].data:(unsigned char *)SSAddress(res.owner);
                value=(SSWord)live+res.at+r.offset;
            }
            return 1;
        }
        return 0; }
    case 4: if (r.target>=w->nfiles || r.offset) return 0;
        value=(SSWord)w->files[r.target].handle; return value!=0;
    }
    return 0;
}
static World *capture()
{
    initialize(); schema();
    if(!statics[11].data) { notice("GRAPHICS RESOURCES ARE UNAVAILABLE"); return 0; }
    if (trackingError || ssw(0x462714) || ssw(0x462720)) {
        notice("RESOURCE TRACKING NOT READY"); return 0;
    }
    World *w=new World;
    if (!w) { notice("NOT ENOUGH MEMORY TO SAVE STATE"); return 0; }
    w->level=ssw(0x4a2964);
    w->paused=ssw(0x487f88)==0;
    w->sequenceOffset=ssw(0x455c3c)==4?sequenceOffset:0xffffffffU;
    w->returnLevel=ssw(0x455c3c)==5?returnLevel:0xffffffffU;
    w->nresources=resourceCount; memcpy(w->resources,resources,resourceCount*sizeof(Resource));
    SSWord refs=0;
    for (int k=0;k<HEAP_LIMIT+STATIC_COUNT;++k) {
        Chunk &live=k<HEAP_LIMIT?heaps[k]:statics[k-HEAP_LIMIT];
        if (!live.data) continue;
        Chunk &c=w->chunks[w->count++];
        c.id=live.id; c.size=live.size;
        c.data=(unsigned char *)((c.id&DYNAMIC)?GlobalAlloc(0x40,c.size):malloc(c.size));
        c.mask=(unsigned char *)malloc(c.size);
        if (!c.data || !c.mask) { notice("NOT ENOUGH MEMORY TO SAVE STATE"); delete w; return 0; }
        memcpy(c.data,live.data,c.size); memcpy(c.mask,live.mask,c.size);
        if(c.id==0x4626d0) {
            memset(c.data+0x70,0,9*88); memset(c.mask+0x70,0,9*88);
            memset(c.data+0x388,0,10*52); memset(c.mask+0x388,0,10*52);
        }
        if(live.data==(unsigned char *)ssw(0x4a27a0))
            for(int o=0;o<100;++o) {
                if(!activeObjects[o]) { memset(c.data+o*0x204+8,0,0x204-8); memset(c.mask+o*0x204+8,0,0x204-8); }
                else for(int s=0;s<2;++s) {
                    SSWord at=o*0x204+0x10+s*0x20, depth=*(SSWord *)(c.data+at+8);
                    // Inactive return slots are dead, and retain addresses from
                    // previous calls. They must not pollute portable traces.
                    for(SSWord n=depth;n<4;++n) {
                        memset(c.data+at+(n+4)*4,0,4);
                        memset(c.mask+at+(n+4)*4,0,4);
                    }
                }
            }
        for (SSWord n=0;n<c.size;++n) if (c.mask[n]==1 || c.mask[n]==2 || c.mask[n]==4) ++refs;
    }
    // Allocation slots retain saved IDs; reopening binds them to staged blocks.
    for (k=0;k<8;++k) if (opened[k].handle) {
        w->files[w->nfiles]=opened[k];
        w->files[w->nfiles].handle=0;
        w->files[w->nfiles].offset=SetFilePointer(opened[k].handle,0,0,1);
        ++w->nfiles;
    }
    // Compact a corresponding handle list for encode(), without changing live bookkeeping.
    File original[8]; memcpy(original,opened,sizeof(opened));
    memset(opened,0,sizeof(opened)); int index=0;
    for (k=0;k<8;++k) if(original[k].handle) opened[index++]=original[k];
    w->refs=(Reference *)malloc(refs*sizeof(Reference));
    if (refs && !w->refs) { notice("NOT ENOUGH MEMORY TO SAVE STATE"); memcpy(opened,original,sizeof(opened)); delete w; return 0; }
    for (SSWord i=0;i<w->count;++i) {
        Chunk &c=w->chunks[i];
        for (SSWord n=0;n<c.size;++n) if (c.mask[n]) {
            if (c.mask[n]==3) { *(short *)(c.data+n)=-1; continue; }
            Reference &r=w->refs[w->nrefs++]; r.source=c.id; r.at=n;
            SSWord value=*(SSWord *)(c.data+n);
            if (!encode(w,r,value,c.mask[n]==2)) {
                char text[160]; sprintf(text,"UNRESOLVED FIELD %08X+%X (%08X)",c.id,n,value);
                notice(text); memcpy(opened,original,sizeof(opened)); delete w; return 0;
            }
            *(SSWord *)(c.data+n)=0;
        }
    }
    memcpy(opened,original,sizeof(opened));
    w->nassets=historyCount;
    for (i=0;i<historyCount;++i) {
        w->assets[i]=history[i];
        if (!SSFileIdentity(w->assets[i].name,&w->assets[i].size,&w->assets[i].crc)) {
            notice("CANNOT FINGERPRINT GAME ASSETS"); delete w; return 0;
        }
    }
    w->audio=SSAudioCapture();
    if (!w->audio) { notice(SSAudioError()?SSAudioError():"AUDIO CAPTURE FAILED"); delete w; return 0; }
    return w;
}
static int filename(char *path, int temporary)
{
    char base[512]; unsigned long n=GetEnvironmentVariableA("LOCALAPPDATA",base,sizeof(base));
    if (!n || n>=sizeof(base)-64) return 0;
    sprintf(path,"%s\\GexSource",base); CreateDirectoryA(path,0);
    sprintf(path,"%s\\GexSource\\states",base); CreateDirectoryA(path,0);
    sprintf(path,"%s\\GexSource\\states\\slot-%d.gxs%s",base,selectedSlot,temporary?".tmp":""); return 1;
}
static SSWord executableHash()
{
    // CRC32 is diagnostic only. Compatibility is determined by schema/asset IDs.
    char path[512]; unsigned long n=GetModuleFileNameA(0,path,sizeof(path));
    if(!n || n>=sizeof(path)) return 0;
    void *h=CreateFileA(path,0x80000000U,1,0,3,0,0);
    if(h==(void *)-1) return 0;
    unsigned char data[4096]; unsigned long bytes; SSWord crc=0xffffffffU;
    while(ReadFile(h,data,sizeof(data),&bytes,0) && bytes) crc=checksum(data,bytes,crc);
    CloseHandle(h); return ~crc;
}
static int writeWorld(World *w)
{
    SSBuffer b;
    b.word(0x32535847); b.word(5); b.word(1); // magic, wire version, world ABI
    b.word(w->level); b.word(w->count); b.word(w->nrefs); b.word(w->nassets); b.word(w->nfiles); b.word(w->nresources);
    for (SSWord i=0;i<w->count;++i) {
        Chunk &c=w->chunks[i]; b.word(c.id); b.word(c.size);
        b.append(c.mask,c.size); b.append(c.data,c.size);
    }
    b.append(w->resources,w->nresources*sizeof(Resource));
    b.append(w->refs,w->nrefs*sizeof(Reference));
    b.append(w->assets,w->nassets*sizeof(Asset));
    for(i=0;i<w->nfiles;++i) { b.append(w->files[i].name,260); b.word(w->files[i].offset); }
    if (!SSAudioWrite(w->audio,b)) return 0;
    b.word(0x4c544552); b.word(4); b.word(w->returnLevel);
    b.word(0x53554150); b.word(4); b.word(w->paused);
    b.word(0x51534553); b.word(4); b.word(w->sequenceOffset);
    b.word(0x45584543); b.word(4); b.word(executableHash()); // diagnostic TLV
    b.word(~checksum(b.data,b.size));
    if (!b.good) return 0;
    char path[576], temp[576];
    if (!filename(path,0) || !filename(temp,1)) return 0;
    void *h=CreateFileA(temp,0x40000000U,0,0,2,0,0);
    if(h==(void *)-1) return 0;
    unsigned long written;
    int good=WriteFile(h,b.data,b.size,&written,0) && written==b.size && FlushFileBuffers(h);
    CloseHandle(h);
    if(good) good=MoveFileExA(temp,path,9); // replace existing + write through
    if(!good) DeleteFileA(temp);
    return good;
}
static World *readWorld()
{
    if(!statics[11].data) { notice("GRAPHICS RESOURCES ARE UNAVAILABLE"); return 0; }
    char path[576]; if(!filename(path,0)) { notice("LOCALAPPDATA IS UNAVAILABLE"); return 0; }
    void *h=CreateFileA(path,0x80000000U,1,0,3,0,0);
    if(h==(void *)-1) { notice("EMPTY SLOT OR UNREADABLE FILE"); return 0; }
    SSWord length=GetFileSize(h,0);
    SSBuffer b; unsigned long read;
    if(length<36 || length>MAX_BYTES) { CloseHandle(h); notice("INVALID STATE FILE"); return 0; }
    b.data=(unsigned char *)malloc(length); b.size=b.capacity=length;
    if(!b.data) { CloseHandle(h); notice("NOT ENOUGH MEMORY"); return 0; }
    int ok=ReadFile(h,b.data,length,&read,0) && read==length; CloseHandle(h);
    if(!ok || *(SSWord *)(b.data+length-4)!=~checksum(b.data,length-4)) { notice("STATE CHECKSUM FAILED"); return 0; }
    b.size-=4;
    SSWord magic=b.take(), version=b.take(), abi=b.take();
    if(magic!=0x32535847 || version<1 || version>5 || abi!=1) { notice("UNSUPPORTED STATE VERSION"); return 0; }
    World *w=new World;
    if(!w) { notice("NOT ENOUGH MEMORY"); return 0; }
    w->level=b.take(); SSWord count=b.take(); w->nrefs=b.take(); w->nassets=b.take(); w->nfiles=b.take();
    if(version>=4) w->nresources=b.take();
    if(w->level>=140 || (count<STATIC_COUNT || count>HEAP_LIMIT+STATIC_COUNT) || w->nrefs>MAX_BYTES/sizeof(Reference) || w->nassets>ASSET_LIMIT || w->nfiles>8 || w->nresources>2048) { w->nfiles=0; notice("INVALID STATE TABLE COUNTS"); delete w; return 0; }
    const char *stage="chunks";
    const char *failure=0;
    SSWord total=0, ndynamic=0, nstatic=0;
    for(SSWord i=0;i<count && b.good;++i) {
        Chunk &c=w->chunks[w->count++]; c.id=b.take(); c.size=b.take();
        if(!c.size || c.size>MAX_BYTES-total || chunk(w,c.id)!=&c || c.id==DYNAMIC) { b.good=0; break; }
        total+=c.size;
        if(c.id&DYNAMIC) {
            if(++ndynamic>HEAP_LIMIT) { b.good=0; break; }
            c.data=(unsigned char *)GlobalAlloc(0x40,c.size);
        } else {
            int found=0;
            for(int j=0;j<STATIC_COUNT;++j) if(statics[j].id==c.id && statics[j].size==c.size) found=1;
            if(!found) { b.good=0; break; }
            ++nstatic; c.data=(unsigned char *)malloc(c.size);
        }
        c.mask=(unsigned char *)malloc(c.size);
        if(!c.data || !c.mask) { failure="NOT ENOUGH MEMORY TO LOAD STATE"; b.good=0; break; }
        if(!b.read(c.mask,c.size) || !b.read(c.data,c.size)) { b.good=0; break; }
        for(SSWord n=0;n<c.size;++n) if(c.mask[n]>4 || (c.mask[n] && n+(c.mask[n]==3?2:4)>c.size)) b.good=0;
    }
    if(nstatic!=STATIC_COUNT) b.good=0;
    SSWord descriptors=0;
    for(i=0;i<w->count && b.good;++i) for(SSWord n=0;n<w->chunks[i].size;++n) {
        unsigned char kind=w->chunks[i].mask[n];
        if(kind) {
            SSWord width=kind==3?2:4;
            for(SSWord j=1;j<width;++j) if(w->chunks[i].mask[n+j]) b.good=0;
            if(kind!=3) ++descriptors;
        }
    }
    if(descriptors!=w->nrefs) b.good=0;
    if(b.good) stage="resource table";
    if(b.good) b.read(w->resources,w->nresources*sizeof(Resource));
    for(i=0;i<w->nresources && b.good;++i) {
        Resource &r=w->resources[i]; Chunk *c=chunk(w,r.owner);
        if(!r.id || !c || !r.size || r.at>c->size || r.size>c->size-r.at || r.asset>=w->nassets) b.good=0;
        for(SSWord j=0;j<i;++j) if(w->resources[j].id==r.id) b.good=0;
    }
    if(b.good) {
        w->refs=(Reference *)malloc(w->nrefs*sizeof(Reference));
        if((w->nrefs && !w->refs) || !b.read(w->refs,w->nrefs*sizeof(Reference))) b.good=0;
    }
    if(b.good) stage="asset table";
    if(b.good) b.read(w->assets,w->nassets*sizeof(Asset));
    for(i=0;i<w->nassets && b.good;++i) {
        Asset &a=w->assets[i]; SSWord bytes,crc;
        if(a.name[259] || !SSFileIdentity(a.name,&bytes,&crc) || bytes!=a.size || crc!=a.crc) { failure="GAME ASSETS DIFFER OR ARE MISSING"; b.good=0; }
    }
    for(i=0;i<w->nresources && b.good;++i) {
        Resource &r=w->resources[i]; Asset &a=w->assets[r.asset];
        if(r.fileOffset>a.size || r.size>a.size-r.fileOffset) b.good=0;
    }
    if(b.good) stage="files";
    for(i=0;i<w->nfiles && b.good;++i) {
        File &f=w->files[i]; b.read(f.name,260); f.offset=b.take();
        if(!b.good || f.name[259] || !safePath(f.name)) { b.good=0; break; }
        f.handle=CreateFileA(f.name,0x80000000U,1,0,3,0x08000000U,0);
        if(f.handle==(void *)-1) { f.handle=0; failure="CANNOT REOPEN GAME FILES"; b.good=0; break; }
        if(SetFilePointer(f.handle,f.offset,0,0)==0xffffffffU) b.good=0;
    }
    if(b.good) stage="references";
    for(i=0;i<w->nrefs && b.good;++i) {
        Reference &r=w->refs[i]; Chunk *c=chunk(w,r.source); SSWord value;
        if(!c || r.at>c->size-4 || (c->mask[r.at]!=1 && c->mask[r.at]!=2 && c->mask[r.at]!=4) ||
           (c->mask[r.at]==2 && r.kind!=0 && r.kind!=4) ||
           (c->mask[r.at]!=2 && r.kind==4) || !decode(w,r,value)) {
            char diagnostic[128]; sprintf(diagnostic,"State reference failed: %x/%x kind %u target %x offset %x\r\n",r.source,r.at,r.kind,r.target,r.offset);
            OutputDebugStringA(diagnostic); b.good=0; break;
        }
        // Globals are staged at malloc addresses; references must target the
        // live image location, while dynamic allocations remain staged.
        if(r.kind==1 && !(r.target&DYNAMIC)) {
            if(r.target==FONT) value=(SSWord)GEX_StateFont+r.offset;
            else if(r.target==PIXELS) value=(SSWord)statics[11].data+r.offset;
            else value=(SSWord)SSAddress(r.target)+r.offset;
        }
        *(SSWord *)(c->data+r.at)=value;
        c->mask[r.at]|=0x80;
    }
    for(i=0;i<w->count;++i) for(SSWord n=0;n<w->chunks[i].size && w->chunks[i].mask;++n) {
        unsigned char &kind=w->chunks[i].mask[n];
        if(kind==1 || kind==2 || kind==4) b.good=0;
        kind&=0x7f;
    }
    if(b.good) stage="audio";
    if(b.good) w->audio=SSAudioRead(b,version);
    int audioIdentities=0, pauseMetadata=0;
    if(b.good && w->audio && version>=3) while(b.position<b.size) {
        SSWord tag=b.take(), bytes=b.take();
        if(!b.good || bytes>b.size-b.position) { b.good=0; break; }
        if((tag==0x45584543 || tag==0x51534553 || tag==0x53554150 || tag==0x4c544552) && bytes!=4) { b.good=0; break; }
        if(tag==0x44495541) {
            if(audioIdentities || !SSAudioReadIdentities(w->audio,b.data+b.position,bytes)) {
                failure=SSAudioError(); b.good=0; break;
            }
            audioIdentities=1;
        }
        if(tag==0x4c544552 && bytes==4) w->returnLevel=*(SSWord *)(b.data+b.position);
        if(tag==0x53554150 && bytes==4) { pauseMetadata=1; w->paused=*(SSWord *)(b.data+b.position); if(w->paused>1) b.good=0; }
        if(tag==0x51534553 && bytes==4) w->sequenceOffset=*(SSWord *)(b.data+b.position);
        b.position+=bytes; // diagnostic/unknown optional metadata is not a gate
    }
    if(version>=5 && w->audio && !audioIdentities) b.good=0;
    if(b.good && w->audio) {
        if(!pauseMetadata) w->paused=*(SSWord *)(chunk(w,0x4a0200)->data+0x274c)==2;
        Chunk *globals=chunk(w,0x455b00);
        if(*(SSWord *)(globals->data+0x13c)==5 && w->returnLevel>=140) { failure="STATE LACKS CUTSCENE RETURN LEVEL"; b.good=0; }
        if(*(SSWord *)(globals->data+0x13c)==4) {
            // Older wire versions did not retain this native loop local.
            if(w->sequenceOffset==0xffffffffU) {
                for(SSWord n=0;n<140;++n) if(globals->data[0x168+n]==w->level) { w->sequenceOffset=n; break; }
            }
            if(w->sequenceOffset>=140) b.good=0;
        }
    }
    if(!b.good || !w->audio || b.position!=b.size) {
        char detail[128]; sprintf(detail,"State validation failed at %s offset %u/%u\r\n",stage,b.position,b.size); OutputDebugStringA(detail);
        notice(failure?failure:b.good && !w->audio && SSAudioError()?SSAudioError():"INVALID OR UNSUPPORTED STATE DATA");
        delete w; return 0;
    }
    return w;
}
extern "C" void __cdecl GEX_StateReturnLevel(unsigned int level) { returnLevel=level; }
extern "C" void __cdecl GEX_StateSequence(unsigned int offset) { sequenceOffset=offset; }
extern "C" int __cdecl GEX_StateSequenceResume(int *offset)
{
    if(!resumeSequence) return 0;
    resumeSequence=0; *offset=sequenceOffset; return 1;
}
extern "C" int __cdecl GEX_StateRand(void)
{
    ssw(0x461180)=ssw(0x461180)*214013U+2531011U;
    return (ssw(0x461180)>>16)&32767;
}
extern "C" int __cdecl GEX_StatePoll(int gameplay)
{
    if(pending) { ssw(0x455c3c)=6; return 1; }
    if(readRequest==writeRequest) return 0;
    initialize();
    unsigned request=requests[readRequest++ & 31];
    if(request>='0' && request<='9') { selectedSlot=request-'0'; notice("SELECTED"); return 0; }
    if(gameplay<0) {
        notice(request==0x74?"SAVE UNAVAILABLE DURING VIDEO":"LOAD UNAVAILABLE DURING VIDEO");
        char title[224]; sprintf(title,"GEX - %s",message);
        SetWindowTextA((void *)ssw(0x4875a0),title); videoNotice=1; return 0;
    }
    if(request==0x74 && (!gameplay || ssw(0x4a2964)==63 || ssw(0x4a2a0c) || GEX_SpriteViewerActive())) {
        notice("SAVE UNAVAILABLE IN THIS MODE"); return 0;
    }
    if(ssw(0x462718) && !ssw(0x4a2958) && (ssw(0x462714) || ssw(0x462720))) BLOC_BlockLoader_0040b460();
    if(ssw(0x4a2958) || ssw(0x462714) || ssw(0x462720)) {
        if(!deferred) notice("WAITING FOR LEVEL TRANSITION");
        deferred=1; --readRequest; return 0;
    }
    deferred=0;
    busy=1;
    if(mutations) { --readRequest; unblock(); return 0; }
    if(!SSAudioHold()) { unblock(); notice("AUDIO WORKER DID NOT PAUSE"); return 0; }
    schema();
    if(request==0x74) {
        World *w=capture();
        if(w) {
            int good=writeWorld(w); SSAudioResume(w->audio); delete w;
            notice(good?"SAVED":"SAVE FAILED; PREVIOUS FILE KEPT");
        }
    } else {
        if(!SSAudioStopHardware()) { SSAudioRelease(); unblock(); notice("AUDIO PAUSE FAILED"); return 0; }
        pending=readWorld();
        if(!pending) SSAudioContinueHardware();
        if(pending) ssw(0x455c3c)=6;
    }
    if(!pending) { SSAudioRelease(); unblock(); }
    return pending!=0;
}
extern "C" void __cdecl GEX_StateDispatch(void)
{
    if(!pending) { ssw(0x455c3c)=1; return; }
    busy=1;
    if(!SSAudioHold()) { unblock(); return; }
    World *w=pending;
    // All file/allocation/audio preparation succeeded without touching the live world.
    if(!SSAudioCommit(w->audio)) { delete pending; pending=0; ssw(0x455c3c)=1; unblock(); SSAudioContinueHardware(); SSAudioRelease(); notice("AUDIO RESTORE FAILED"); return; }
    DRAW_CacheClear_0043e430(1);
    for(int i=0;i<HEAP_LIMIT;++i) if(heaps[i].data) { GlobalFree(heaps[i].data); free(heaps[i].mask); }
    memset(heaps,0,sizeof(heaps));
    for(i=0;i<8;++i) if(opened[i].handle) CloseHandle(opened[i].handle);
    memset(opened,0,sizeof(opened));
    SSWord heapIndex=0;
    for(SSWord n=0;n<w->count;++n) {
        Chunk &c=w->chunks[n];
        if(c.id&DYNAMIC) {
            heaps[heapIndex++]=c;
            if((c.id&~DYNAMIC)>=nextId) nextId=(c.id&~DYNAMIC)+1;
            c.data=c.mask=0;
        } else {
            for(i=0;i<STATIC_COUNT;++i) if(statics[i].id==c.id) {
                memcpy(statics[i].data,c.data,c.size);
                memcpy(statics[i].mask,c.mask,c.size);
            }
        }
    }
    for(n=0;n<w->nfiles;++n) { opened[n]=w->files[n]; w->files[n].handle=0; }
    // The original CDIO table belongs to the runtime, not the portable graph.
    memset(SSAddress(0x47f010),0,8*4); ssw(0x47f004)=w->nfiles;
    for(n=0;n<w->nfiles;++n) *(void **)((char *)SSAddress(0x47f010)+n*4)=opened[n].handle;
    historyCount=w->nassets; memcpy(history,w->assets,historyCount*sizeof(Asset));
    resourceCount=w->nresources; memcpy(resources,w->resources,resourceCount*sizeof(Resource));
    for(n=0;n<resourceCount;++n) if(resources[n].id>=nextResource) nextResource=resources[n].id+1;
    memset(SSAddress(0x462740),0,9*88); memset(SSAddress(0x462a58),0,10*52);
    ssw(0x462714)=ssw(0x462720)=0;
    ssw(0x462724)=ssw(0x462728)=ssw(0x462730)=0;
    ssw(0x46272c)=ssw(0x462738)=0;
    memset(SSAddress(0x4a0280),0,2*0x24); ssw(0x4517e8)=0;
    ssw(0x48800c)=ssw(0x487fd4)=ssw(0x487ff8)=ssw(0x4a02c8)=ssw(0x4a02cc)=0;
    SSWord mode=(ssw(0x455c3c)==4 || ssw(0x455c3c)==5)?ssw(0x455c3c):1;
    SSWord returnTo=w->returnLevel;
    returnLevel=returnTo;
    sequenceOffset=w->sequenceOffset;
    int paused=w->paused;
    ssw(0x487f88)=paused?0:1; ssw(0x48a03c)=paused?1:0;
    ssw(0x4a294c)=paused?2:0; ssw(0x455c3c)=mode; ssw(0x4626f0)=mode;
    DRAW_CacheInit_0043e350();
    if(GEX_StateFont[1]) {
        short reserve[4]={0x3f0,0x180,0,0};
        reserve[2]=*(short *)(GEX_StateFont[1]+0x324)>>2;
        reserve[3]=*(short *)(GEX_StateFont[1]+0x326);
        FUN_0043eb50_LoadTilePoss(reserve,1);
    }
    GEX_SpriteViewerClose(); GEX_MainMenuClose(); pending=0; notice("LOADED");
    SSAudioResume(w->audio); delete w; SSAudioRelease(); unblock();
    if(paused) {
        // Present the restored pause backing before waiting for input. The
        // previous display may still contain a menu, another level or viewer.
        GFX_Flush_00406c30();
        FUN_0040b2d0_InputProcessing(); if(pending) return;
    }
    if(mode==4) { resumeSequence=1; M1_GameLoop_0040ad40(); return; }
    void *level=(void *)ssw(0x455b80);
    while(M1_PlayLevel_0040a010(level) && !ssw(0x4a2a80)) ;
    if(!pending) {
        M1_ExitLevel_0040a660(level); M1_FreeLevel_0040aa60();
        if(mode==5) { ssw(0x4a2964)=returnTo; ssw(0x455c3c)=1; }
    }
}
