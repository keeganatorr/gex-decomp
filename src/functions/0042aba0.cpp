// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x54];
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad58[0x40];
    unsigned int gob_work0;     /* 0x98: low word switch id, high word remote */
    unsigned int gob_work1;     /* 0x9c */
    unsigned int gob_work2;     /* 0xa0 */
    unsigned int gob_work3;     /* 0xa4 */
} GXObject;
extern "C" {
extern unsigned char BYTE_ARRAY_004a2540[];
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, unsigned int work0);
void __cdecl RezInObject_004372f0(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob)
{
    GXObject *source;
    unsigned int remote;
    unsigned int flags;
    if (gob->gob_work1 & 2) {
        source = GOB_FindWithWork0_0040c110(0xdc, gob->gob_work0 & 0xffff);
        remote = source->gob_work1;
        flags = source->gob_work3;
        if ((flags & 0x200) && (flags & 0x400) && (BYTE_ARRAY_004a2540[remote] & 3) != 3) {
            gob->gob_work1 |= 1;
            if (gob->gob_work2 & 2)
                gob->gob_currentFrameIndex = 0;
            else
                gob->gob_currentFrameIndex = -1;
        } else if ((flags & 0x200) && !(flags & 0x400) && (gob->gob_work2 & 2))
            gob->gob_currentFrameIndex = -1;
        gob->gob_work0 = (gob->gob_work0 & 0xffff) | (remote << 16);
        gob->gob_work1 &= ~2;
    } else if ((gob->gob_work1 & 1) && (BYTE_ARRAY_004a2540[gob->gob_work0 >> 16] & 1)) {
        if (gob->gob_work2 & 2)
            gob->gob_currentFrameIndex = -1;
        else {
            gob->gob_currentFrameIndex = 0;
            if (!(gob->gob_work2 & 1))
                RezInObject_004372f0(gob);
        }
        gob->gob_work1 &= ~1;
    }
}
}
