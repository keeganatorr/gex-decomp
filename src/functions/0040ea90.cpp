struct GXObject {
    unsigned char unknown00[0x78];
    int gob_xpos;
    int gob_ypos;
    unsigned char unknown80[0x1c];
    char *gob_work1;
};

extern "C" {
void __cdecl MainMenuButtonDraw_0040c340(GXObject *gob);
extern char *STRING_Up_Down_00487ff0;
extern char *STRING_Enter_Password_00488000;
extern char *STRING_Enter_0048a010;
extern char *STRING_Use_Password_0048a018;
extern char *STRING_Esc_0048a01c;
extern char *STRING_Cancel_00487ffc;

void __cdecl GEX_Target(GXObject *gob)
{
    gob->gob_work1 = STRING_Up_Down_00487ff0;
    gob->gob_xpos = 0x1e0000;
    gob->gob_ypos = 0x780000;
    MainMenuButtonDraw_0040c340(gob);
    gob->gob_work1 = STRING_Enter_Password_00488000;
    gob->gob_xpos = 0x820000;
    gob->gob_ypos = 0x780000;
    MainMenuButtonDraw_0040c340(gob);
    gob->gob_work1 = STRING_Enter_0048a010;
    gob->gob_xpos = 0x1e0000;
    gob->gob_ypos = 0x910000;
    MainMenuButtonDraw_0040c340(gob);
    gob->gob_work1 = STRING_Use_Password_0048a018;
    gob->gob_xpos = 0x820000;
    gob->gob_ypos = 0x910000;
    MainMenuButtonDraw_0040c340(gob);
    gob->gob_work1 = STRING_Esc_0048a01c;
    gob->gob_xpos = 0x1e0000;
    gob->gob_ypos = 0xaa0000;
    MainMenuButtonDraw_0040c340(gob);
    gob->gob_work1 = STRING_Cancel_00487ffc;
    gob->gob_xpos = 0x820000;
    gob->gob_ypos = 0xaa0000;
    MainMenuButtonDraw_0040c340(gob);
}
}
