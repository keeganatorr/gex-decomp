// Adapted from pc_decomp_backup/src/functions/FUN_00418390.cpp
// Historical source SHA256: a153be298593889317122f695d40b45047880ecd705a8f54d4e98aa8d4f49644
extern "C" {
extern "C" unsigned char * __cdecl GEX_Target(unsigned char *p, void **pp)
{
    unsigned int idx = p[0];
    unsigned char *rp = p + 1;
    void *v = ((void**)pp)[idx + 0x1a];
    void *nx = pp[0x57];
    void **cur = pp;
    int dc = 0;

    if (nx == 0) goto w;
    dc = 0;
    do {
        cur = (void **)nx;
        nx = cur[0x57];
    } while (nx != 0);
w:
    cur[idx + 0x1a] = v;
    return rp;
}
}
