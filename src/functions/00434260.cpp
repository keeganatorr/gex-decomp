// Source translation of the pinned 00434260 path-motion routine. The object's
// path has a two-byte header followed by signed X/Y deltas per motion step.
extern "C" {
extern int *gPlayerObject_004a27fc;
extern int gPlayerPlatform_004a2864;
extern int PTR_004a2814;
extern int PTR_004a2874;
}

static unsigned short PathLength(const unsigned char *path)
{
    return (unsigned short)(path[0] | ((unsigned int)path[1] << 8));
}

extern "C" void __cdecl FUN_00434260(int *object)
{
    unsigned char *path = (unsigned char *)object[0x29];
    if (!path) return;

    unsigned int flags = (unsigned int)object[0x2d];
    if ((flags & 0x10) && !(flags & 0x80000000U)) {
        if (!gPlayerObject_004a27fc ||
            (gPlayerObject_004a27fc[0x44] != (int)object &&
             gPlayerPlatform_004a2864 != (int)object &&
             PTR_004a2814 != (int)object && PTR_004a2874 != (int)object))
            return;
    }
    if ((flags & 0x10) && (flags & 0x800))
        object[0x2d] = (int)(flags | 0x80000000U);

    flags = (unsigned int)object[0x2d];
    if (!(flags & 4)) {
        int speed = object[0x27] + object[0x28];
        if (object[0x2c] && object[0x2c] < speed) speed = object[0x2c];
        if (speed < 0) speed = 0;
        object[0x27] = speed;
    }

    int phase = object[0x2b] + object[0x27];
    int steps = phase >> 16;
    object[0x2b] = phase - (steps << 16);
    if (!steps) return;

    unsigned char *cursor = (unsigned char *)object[0x2a];
    do {
        int dx = (signed char)cursor[0];
        int dy = (signed char)cursor[1];
        flags = (unsigned int)object[0x2d];
        cursor += (flags & 8) ? -2 : 2;

        if (dx == -127) {
            object[0x38] |= 0x20;
            if (flags & 0x4000) object[0x2d] = (int)(flags ^ 8);
            flags = (unsigned int)object[0x2d];
            unsigned char *point = (flags & 8) ? path + PathLength(path) : path + 4;
            dx = (signed char)point[0];
            dy = (signed char)point[1];
            cursor = point + ((flags & 8) ? -2 : 2);
            if (flags & 1) {
                object[0x2a] = (int)point;
                object[0x1d] = object[0x1c] + 1;
                return;
            }
        }

        unsigned int motionX = (unsigned int)dx << 25;
        unsigned int motionY = (unsigned int)dy << 25;
        flags = (unsigned int)object[0x2d];
        if (flags & 8) {
            motionX = 0U - motionX;
            motionY = 0U - motionY;
        }
        object[0x25] = (int)motionX;
        if (flags & 4) {
            if ((int)motionY > 0) object[0x27] += object[0x28];
            if ((int)motionY < 0) object[0x27] -= object[0x28];
            if (object[0x2c] && object[0x2c] < object[0x27])
                object[0x27] = object[0x2c];
            if (object[0x27] <= 0) {
                object[0x27] = -object[0x27];
                flags ^= 8;
                object[0x2d] = (int)flags;
                ++steps;
                cursor += (flags & 8) ? -2 : 2;
            }
        }
        object[0x1e] += (int)motionX >> 9;
        object[0x1f] += (int)motionY >> 9;
    } while (--steps);
    object[0x2a] = (int)cursor;
}
