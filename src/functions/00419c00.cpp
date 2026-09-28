typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;    /* 0x6c */
    unsigned char _pad70[0x54];
    int gob_angle;             /* 0xc4 */
    int gob_scaleX;            /* 0xc8 */
    int gob_scaleY;            /* 0xcc */
} GXObject;
typedef struct HotSpots {
    int count;
    int **spots;
} HotSpots;
typedef struct Frame {
    int unk0[5];
    HotSpots *hotspots;
} Frame;
extern "C" {
extern int gTrigTable_0045a5c8[];
Frame *__cdecl GOB_GetCurrentFrameWithDefault_0041a380(GXObject *gob);
int __cdecl GEX_Target(GXObject *gob, int set, int index, int *outX, int *outY)
{
    Frame *frame;
    HotSpots *hotspots;
    int *spot;
    int c;
    int x;
    int y;
    int s;

    frame = GOB_GetCurrentFrameWithDefault_0041a380(gob);
    if (!frame)
        return 0;
    hotspots = frame->hotspots;
    if (hotspots && hotspots->count >= set && (spot = hotspots->spots[set]) != 0 && spot[0] > index) {
        index = index * 2 + 1;
        x = spot[index];
        y = spot[index + 1];
        if (gob->gob_flags & 0x80000000)
            x = -x;
        if (gob->gob_flags & 0x40000000)
            y = -y;
        if (gob->gob_scaleX != 0x10000)
            x = (x >> 16) * gob->gob_scaleX;
        if (gob->gob_scaleY != 0x10000)
            y = (y >> 16) * gob->gob_scaleY;
        if (gob->gob_angle) {
            s = ((gob->gob_angle >> 16) < 0 ? -((-(gob->gob_angle >> 16)) > 256 ? (((-(gob->gob_angle >> 16)) % 256) > 128 ? -((((-(gob->gob_angle >> 16)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(gob->gob_angle >> 16)) % 256) - 128)] : gTrigTable_0045a5c8[((-(gob->gob_angle >> 16)) % 256) - 128]) : ((((-(gob->gob_angle >> 16)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-(gob->gob_angle >> 16)) % 256))] : gTrigTable_0045a5c8[((-(gob->gob_angle >> 16)) % 256)])) : ((-(gob->gob_angle >> 16)) > 128 ? -(((-(gob->gob_angle >> 16)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(gob->gob_angle >> 16)) - 128)] : gTrigTable_0045a5c8[(-(gob->gob_angle >> 16)) - 128]) : ((-(gob->gob_angle >> 16)) > 64 ? gTrigTable_0045a5c8[128 - (-(gob->gob_angle >> 16))] : gTrigTable_0045a5c8[-(gob->gob_angle >> 16)]))) : ((gob->gob_angle >> 16) > 256 ? (((gob->gob_angle >> 16) % 256) > 128 ? -((((gob->gob_angle >> 16) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((gob->gob_angle >> 16) % 256) - 128)] : gTrigTable_0045a5c8[((gob->gob_angle >> 16) % 256) - 128]) : ((((gob->gob_angle >> 16) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((gob->gob_angle >> 16) % 256))] : gTrigTable_0045a5c8[((gob->gob_angle >> 16) % 256)])) : ((gob->gob_angle >> 16) > 128 ? -(((gob->gob_angle >> 16) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((gob->gob_angle >> 16) - 128)] : gTrigTable_0045a5c8[(gob->gob_angle >> 16) - 128]) : ((gob->gob_angle >> 16) > 64 ? gTrigTable_0045a5c8[128 - (gob->gob_angle >> 16)] : gTrigTable_0045a5c8[gob->gob_angle >> 16]))));
            c = (((gob->gob_angle >> 16) + 64) < 0 ? -((-((gob->gob_angle >> 16) + 64)) > 256 ? (((-((gob->gob_angle >> 16) + 64)) % 256) > 128 ? -((((-((gob->gob_angle >> 16) + 64)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-((gob->gob_angle >> 16) + 64)) % 256) - 128)] : gTrigTable_0045a5c8[((-((gob->gob_angle >> 16) + 64)) % 256) - 128]) : ((((-((gob->gob_angle >> 16) + 64)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-((gob->gob_angle >> 16) + 64)) % 256))] : gTrigTable_0045a5c8[((-((gob->gob_angle >> 16) + 64)) % 256)])) : ((-((gob->gob_angle >> 16) + 64)) > 128 ? -(((-((gob->gob_angle >> 16) + 64)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-((gob->gob_angle >> 16) + 64)) - 128)] : gTrigTable_0045a5c8[(-((gob->gob_angle >> 16) + 64)) - 128]) : ((-((gob->gob_angle >> 16) + 64)) > 64 ? gTrigTable_0045a5c8[128 - (-((gob->gob_angle >> 16) + 64))] : gTrigTable_0045a5c8[-((gob->gob_angle >> 16) + 64)]))) : (((gob->gob_angle >> 16) + 64) > 256 ? ((((gob->gob_angle >> 16) + 64) % 256) > 128 ? -(((((gob->gob_angle >> 16) + 64) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((((gob->gob_angle >> 16) + 64) % 256) - 128)] : gTrigTable_0045a5c8[(((gob->gob_angle >> 16) + 64) % 256) - 128]) : (((((gob->gob_angle >> 16) + 64) % 256)) > 64 ? gTrigTable_0045a5c8[128 - ((((gob->gob_angle >> 16) + 64) % 256))] : gTrigTable_0045a5c8[(((gob->gob_angle >> 16) + 64) % 256)])) : (((gob->gob_angle >> 16) + 64) > 128 ? -((((gob->gob_angle >> 16) + 64) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((gob->gob_angle >> 16) + 64) - 128)] : gTrigTable_0045a5c8[((gob->gob_angle >> 16) + 64) - 128]) : (((gob->gob_angle >> 16) + 64) > 64 ? gTrigTable_0045a5c8[128 - ((gob->gob_angle >> 16) + 64)] : gTrigTable_0045a5c8[(gob->gob_angle >> 16) + 64]))));
            x >>= 16;
            y >>= 16;
            *outX = x * c - y * s;
            *outY = x * s + y * c;
            return 1;
        }
        *outX = x;
        *outY = y;
        return 1;
    }
    return 0;
}
}
