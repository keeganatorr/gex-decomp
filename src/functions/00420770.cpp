// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;  /* 0x6c */
    unsigned char _pad70[8];
    int gob_xpos;            /* 0x78 */
    int gob_ypos;            /* 0x7c */
} GXObject;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
int __cdecl VFX_Play_0041fa80(int voice);
void __cdecl FUN_00420770_Movement_unk(GXObject *gob, int voice)
{
    int dx;
    int dy;
    if (gPlayerObject_004a27fc) {
        dx = gob->gob_xpos - gPlayerObject_004a27fc->gob_xpos;
        if ((dx < 0 ? -dx : dx) < 0x3c0000) {
            dy = gob->gob_ypos - gPlayerObject_004a27fc->gob_ypos;
            if (dy > -0x280000 && dy < 0x280000) {
                if ((dx > 0 && !(gob->gob_flags & 0x80000000)) || (dx < 0 && (gob->gob_flags & 0x80000000)))
                    VFX_Play_0041fa80(voice);
            }
        }
    }
}
}
