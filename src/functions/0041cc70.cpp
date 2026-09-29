typedef struct AnglePoints {
    int unk0;
    int in[4][2];
    int out[4][2];
} AnglePoints;
extern "C" {
extern int gTrigTable_0045a5c8[];
void __cdecl CLD_ApplyAngleToPoints_0041cc70(AnglePoints *p, int dx, int dy, int ox, int oy, int angle, int sx, int sy)
{
    int s;
    int c;
    int i;
    int *in;
    int *out;
    int x;
    int y;
    s = ((angle >> 16) < 0 ? -((-(angle >> 16)) > 256 ? (((-(angle >> 16)) % 256) > 128 ? -((((-(angle >> 16)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(angle >> 16)) % 256) - 128)] : gTrigTable_0045a5c8[((-(angle >> 16)) % 256) - 128]) : ((((-(angle >> 16)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-(angle >> 16)) % 256))] : gTrigTable_0045a5c8[((-(angle >> 16)) % 256)])) : ((-(angle >> 16)) > 128 ? -(((-(angle >> 16)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(angle >> 16)) - 128)] : gTrigTable_0045a5c8[(-(angle >> 16)) - 128]) : ((-(angle >> 16)) > 64 ? gTrigTable_0045a5c8[128 - (-(angle >> 16))] : gTrigTable_0045a5c8[-(angle >> 16)]))) : ((angle >> 16) > 256 ? (((angle >> 16) % 256) > 128 ? -((((angle >> 16) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((angle >> 16) % 256) - 128)] : gTrigTable_0045a5c8[((angle >> 16) % 256) - 128]) : ((((angle >> 16) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((angle >> 16) % 256))] : gTrigTable_0045a5c8[((angle >> 16) % 256)])) : ((angle >> 16) > 128 ? -(((angle >> 16) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((angle >> 16) - 128)] : gTrigTable_0045a5c8[(angle >> 16) - 128]) : ((angle >> 16) > 64 ? gTrigTable_0045a5c8[128 - (angle >> 16)] : gTrigTable_0045a5c8[angle >> 16])))) >> 8;
    c = (((angle >> 16) + 64) < 0 ? -((-((angle >> 16) + 64)) > 256 ? (((-((angle >> 16) + 64)) % 256) > 128 ? -((((-((angle >> 16) + 64)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-((angle >> 16) + 64)) % 256) - 128)] : gTrigTable_0045a5c8[((-((angle >> 16) + 64)) % 256) - 128]) : ((((-((angle >> 16) + 64)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-((angle >> 16) + 64)) % 256))] : gTrigTable_0045a5c8[((-((angle >> 16) + 64)) % 256)])) : ((-((angle >> 16) + 64)) > 128 ? -(((-((angle >> 16) + 64)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-((angle >> 16) + 64)) - 128)] : gTrigTable_0045a5c8[(-((angle >> 16) + 64)) - 128]) : ((-((angle >> 16) + 64)) > 64 ? gTrigTable_0045a5c8[128 - (-((angle >> 16) + 64))] : gTrigTable_0045a5c8[-((angle >> 16) + 64)]))) : (((angle >> 16) + 64) > 256 ? ((((angle >> 16) + 64) % 256) > 128 ? -(((((angle >> 16) + 64) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((((angle >> 16) + 64) % 256) - 128)] : gTrigTable_0045a5c8[(((angle >> 16) + 64) % 256) - 128]) : (((((angle >> 16) + 64) % 256)) > 64 ? gTrigTable_0045a5c8[128 - ((((angle >> 16) + 64) % 256))] : gTrigTable_0045a5c8[(((angle >> 16) + 64) % 256)])) : (((angle >> 16) + 64) > 128 ? -((((angle >> 16) + 64) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((angle >> 16) + 64) - 128)] : gTrigTable_0045a5c8[((angle >> 16) + 64) - 128]) : (((angle >> 16) + 64) > 64 ? gTrigTable_0045a5c8[128 - ((angle >> 16) + 64)] : gTrigTable_0045a5c8[(angle >> 16) + 64])))) >> 8;
    in = p->in[0];
    out = p->out[0];
    for (i = 0; i < 4; i++) {
        x = (in[0] >> 8) * sx >> 8;
        y = (in[1] >> 8) * sy >> 8;
        out[0] = (x * c >> 8) - (y * s >> 8) + ox;
        out[1] = (y * c >> 8) + (x * s >> 8) + oy;
        in[0] += dx;
        in[1] += dy;
        in += 2;
        out += 2;
    }
}
}
