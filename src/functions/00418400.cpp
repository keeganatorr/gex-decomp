// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;   /* 0x78 */
    int gob_ypos;   /* 0x7c */
    unsigned char _pad1[0xdc];
    struct GXObject *gob_parent;   /* 0x15c */
    struct GXObject *gob_child;    /* 0x160 */
    struct GXObject *gob_sibling;  /* 0x164 */
} GXObject;
extern "C" {
extern void __cdecl TracePrintf_Debug_00405390(const char *, ...);
extern int DAT_00455c54_DebugVar;
extern char s_UNLINK_OBJECT_00458e3c[];
unsigned char * __cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    GXObject *o;
    int x;
    int y;
    if (gob->gob_parent) {
        x = 0;
        y = 0;
        o = gob->gob_parent->gob_child;
        if (DAT_00455c54_DebugVar > 1)
            TracePrintf_Debug_00405390(s_UNLINK_OBJECT_00458e3c);
        if (o == gob)
            gob->gob_parent->gob_child = gob->gob_sibling;
        else {
            while (o->gob_sibling != gob)
                o = o->gob_sibling;
            o->gob_sibling = gob->gob_sibling;
        }
        for (o = gob->gob_parent; o->gob_parent; o = o->gob_parent) {
            x += o->gob_xpos;
            y += o->gob_ypos;
        }
        gob->gob_xpos += o->gob_xpos + x;
        gob->gob_ypos += o->gob_ypos + y;
        gob->gob_parent = 0;
    }
    return script;
}
}
