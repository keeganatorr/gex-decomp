// Field names from Ghidra's GXObject layout (evidence, not proof). gob_work7
// holds a 24-bit value with a signed 8-bit direction above it.
typedef struct Work7 { unsigned int value:24; int direction:8; } Work7;
typedef struct GXObject {
    unsigned char _pad0[0xac];
    int gob_work5;     /* 0xac */
    int gob_work6;     /* 0xb0 */
    Work7 gob_work7;   /* 0xb4 */
} GXObject;
extern "C" {
void __cdecl GEX_Target(GXObject *gob)
{
    int diff;
    int distance;
    if (gob->gob_work5 == gob->gob_work6) {
        gob->gob_work7.direction = 0;
        return;
    }
    diff = gob->gob_work6 - gob->gob_work5;
    distance = diff < 0 ? -diff : diff;
    if (distance > 4) {
        distance = 4 - distance % 4;
        diff = diff > 0 ? -distance : distance;
    }
    if (diff < 0)
        gob->gob_work7.direction = -1;
    else
        gob->gob_work7.direction = 1;
}
}
