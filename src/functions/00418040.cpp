// Script field block of a GXObject (0x68 in Ghidra is gob_points; scripts index words from there).
typedef struct GXObject {
    unsigned char _pad0[0x68];
    int gob_fields[61];                 /* 0x68 */
    struct GXObject *gob_parent;        /* 0x15c */
} GXObject;
extern "C" {
extern int SCRIPT_WorkRegister_0049fb90;
extern GXObject *DAT_0049fb94;
unsigned char * __cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    int field = *script++;
    int *fields;
    if (gob->gob_parent)
        fields = gob->gob_parent->gob_fields;
    else if (DAT_0049fb94)
        fields = DAT_0049fb94->gob_fields;
    else {
        SCRIPT_WorkRegister_0049fb90 = -1;
        return script;
    }
    SCRIPT_WorkRegister_0049fb90 = fields[field];
    return script;
}
}
