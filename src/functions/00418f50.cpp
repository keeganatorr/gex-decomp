// Script field block of a GXObject (0x68 in Ghidra is gob_points; scripts index words from there).
typedef struct GXObject {
    unsigned char _pad0[0x68];
    int gob_fields[61];                 /* 0x68 */
    struct GXObject *gob_parent;        /* 0x15c */
} GXObject;
extern "C" {
extern int SCRIPT_WorkRegister_0049fb90;
extern GXObject *DAT_0049fb94;
extern unsigned int __cdecl SCRIPT_GetUInt_00417f00(unsigned char **);
unsigned char * __cdecl SCRIPT_SetLinkField_00418f50(unsigned char *script, GXObject *gob)
{
    int link = *script++;
    int field = *script++;
    unsigned int value = SCRIPT_GetUInt_00417f00(&script);
    ((GXObject *)gob->gob_fields[link])->gob_fields[field] = value;
    return script;
}
}
