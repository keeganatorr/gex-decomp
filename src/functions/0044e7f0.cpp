// Flush all active VC4 FILE slots. The flag field is at offset 12 in this CRT.
extern "C" int __cdecl fflush(void *);

extern "C" int __cdecl _flsall(int mode)
{
    int count = *(int *)0x004a43c0;
    void **streams = *(void ***)0x004a33b0;
    int flushed = 0;
    int failure = 0;
    for (int slot = 0; slot < count; ++slot) {
        void *stream = streams[slot];
        if (!stream) continue;
        unsigned flags = *(unsigned *)((char *)stream + 12);
        if (!(flags & 0x83)) continue;
        if (mode == 1) {
            if (fflush(stream) != -1) ++flushed;
        } else if (mode == 0 && (flags & 2) && fflush(stream) == -1) {
            failure = -1;
        }
    }
    return mode == 1 ? flushed : failure;
}
