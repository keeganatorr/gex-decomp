// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;                 /* 0x78 */
    int gob_ypos;                 /* 0x7c */
    unsigned char _pad80[0xdc];
    struct GXObject *gob_parent;  /* 0x15c */
} GXObject;
extern "C" {
extern GXObject *DAT_0049fb94;
int __cdecl GOB_GetHotSpot_00419c00(GXObject *gob, int group, int index, int *x, int *y);
unsigned char *__cdecl SCRIPT_MoveToParentHotSpot_00418180(unsigned char *script, GXObject *gob)
{
    int x;
    int y;
    int group;
    int index;
    group = *script++;
    index = *script++;
    if (gob->gob_parent) {
        if (GOB_GetHotSpot_00419c00(gob->gob_parent, group, index, &x, &y)) {
            gob->gob_xpos = x;
            gob->gob_ypos = y;
        }
    } else if (GOB_GetHotSpot_00419c00(DAT_0049fb94, group, index, &x, &y)) {
        gob->gob_xpos += x;
        gob->gob_ypos += y;
    }
    return script;
}
}
