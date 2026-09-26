// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;  /* 0x78 */
    int gob_ypos;  /* 0x7c */
} GXObject;
extern "C" {
extern int SCRIPT_WorkRegister_0049fb90;
void __cdecl PrintWithFont_0040bc70(int x, int y, int font, int a, int b, int c, char *text, GXObject *gob);
unsigned char *__cdecl GEX_Target(unsigned char *script, GXObject *gob)
{
    char text[4];
    int font;
    font = *script++;
    text[0] = (char)(SCRIPT_WorkRegister_0049fb90 / 100);
    if (text[0] == 0)
        text[0] = ' ';
    else
        text[0] += '0';
    text[1] = (char)(SCRIPT_WorkRegister_0049fb90 / 10 % 10);
    if (text[0] == ' ' && text[1] == 0)
        text[1] = ' ';
    else
        text[1] += '0';
    text[2] = (char)(SCRIPT_WorkRegister_0049fb90 % 10 + '0');
    text[3] = 0;
    PrintWithFont_0040bc70(gob->gob_xpos, gob->gob_ypos, font, 0, 0, -1, text, gob);
    return script;
}
}
