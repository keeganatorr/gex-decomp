typedef struct GXObject {
    unsigned char _pad0[0x9c];
    char *gob_name;             /* 0x9c */
} GXObject;
typedef struct ButtonSlot {
    char name[4];
    int index;
    int unused;
} ButtonSlot;
extern "C" {
extern ButtonSlot DAT_004560f0[8];
extern char s_Trying_to_make_index_00456274[];
extern char s_Active_gob_00456260[];
extern char s_Found_button_0045624c[];
int __cdecl strcmp(const char *, const char *);
GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work0);
void __cdecl assertfail_00405350(const char *format, ...);
void __cdecl GEX_Target(int index, char *button)
{
    GXObject *gob;
    GXObject *other;
    char *old;
    int i;
    int j;
    int t;
    gob = GOB_FindWithWork0_0040c110(0x7b, index);
    old = gob->gob_name;
    assertfail_00405350(s_Trying_to_make_index_00456274, index, old, button);
    assertfail_00405350(s_Active_gob_00456260, gob);
    if (strcmp(old, button)) {
        gob->gob_name = button;
        for (i = 0; i < 8; i++)
            if (DAT_004560f0[i].index == index)
                break;
        for (j = 0; j < 8; j++)
            if (!strcmp(DAT_004560f0[j].name, button))
                break;
        if (DAT_004560f0[j].index != -1) {
            other = GOB_FindWithWork0_0040c110(0x7b, DAT_004560f0[j].index);
            assertfail_00405350(s_Found_button_0045624c, other->gob_name);
            other->gob_name = old;
        }
        t = DAT_004560f0[j].index;
        DAT_004560f0[j].index = DAT_004560f0[i].index;
        DAT_004560f0[i].index = t;
    }
}
}
