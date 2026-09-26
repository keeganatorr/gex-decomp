// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;  /* 0x78 */
    int gob_ypos;  /* 0x7c */
} GXObject;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern int SCRIPT_WorkRegister_0049fb90;
unsigned int __cdecl SCRIPT_GetUInt_00417f00(unsigned char **script);
unsigned short *__cdecl GOB_GetBlockAddress_00419fe0(void *level, int x, int y);
unsigned int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);
unsigned char *__cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    int dx;
    int dy;
    unsigned int id;
    dx = SCRIPT_GetUInt_00417f00(&script);
    dx <<= 16;
    dy = SCRIPT_GetUInt_00417f00(&script) << 16;
    id = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, gob->gob_xpos + dx, gob->gob_ypos + dy)[1];
    if (id & 0xfff) {
        if (!M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, id, (gob->gob_xpos + dx) & 0x1fffff))
            SCRIPT_WorkRegister_0049fb90 = 0;
        else
            SCRIPT_WorkRegister_0049fb90 = 1;
    } else
        SCRIPT_WorkRegister_0049fb90 = 0;
    return script;
}
}
