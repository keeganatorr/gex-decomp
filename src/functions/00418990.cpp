// Script field block of a GXObject (0x68 in Ghidra is gob_points; scripts index words from there).
typedef struct GXObject {
    unsigned char _pad0[0x68];
    int gob_fields[61];                 /* 0x68 */
    struct GXObject *gob_parent;        /* 0x15c */
} GXObject;
extern "C" {
extern int SCRIPT_WorkRegister_0049fb90;
extern GXObject *DAT_0049fb94;
unsigned char * __cdecl SCRIPT_SubFields_00418990(unsigned char *script, GXObject *gob)
{
    int *fields;
    int a = *script++;
    int b = *script++;
    fields = gob->gob_fields;
    SCRIPT_WorkRegister_0049fb90 = fields[a] - fields[b];
    return script;
}
}
