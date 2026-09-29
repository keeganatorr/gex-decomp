// Script field block of a GXObject (0x68 in Ghidra is gob_points; scripts index words from there).
typedef struct GXObject {
    unsigned char _pad0[0x68];
    int gob_fields[61];                 /* 0x68 */
} GXObject;
extern "C" {
extern int DAT_0049fb94;
unsigned char * __cdecl SCRIPT_LinkObject2_00418bb0(unsigned char *script, GXObject *gob)
{
    int *fields;
    int field = *script++;
    fields = gob->gob_fields;
    fields[field] = DAT_0049fb94;
    return script;
}
}
