struct GXObject
{
    char _pad0[0x78];
    int gob_xpos;          /* 0x78 */
    int gob_ypos;          /* 0x7c */
    char _pad1[0x28];      /* 0x80..0xa7 */
    int gob_work4;         /* 0xa8 */
    char _pad2[0x0c];      /* 0xac..0xb7 */
    int gob_flashTime;     /* 0xb8 */
    unsigned int gob_pixc; /* 0xbc */
    char _pad3[0x08];      /* 0xc0..0xc7 */
    int gob_xScale;        /* 0xc8 */
    int gob_yScale;        /* 0xcc */
    char _pad4[0x130];     /* 0xd0..0x1ff */
};

extern "C" void __cdecl FUN_0042e850(GXObject*);
extern "C" void __cdecl FUN_00441150(GXObject*);
extern "C" void __cdecl FUN_0042f910_GRAPHICSDRAWING(GXObject*, unsigned int);
extern "C" int DAT_0045b128;

extern "C" void __cdecl GEX_Target(GXObject* param_1)
{
    int xpos;
    int ypos;
    int xscale;
    int yscale;
    int t;

    xpos = param_1->gob_xpos;      /* 0x78 */
    ypos = param_1->gob_ypos;      /* 0x7c */
    xscale = param_1->gob_xScale;  /* 0xc8 */
    yscale = param_1->gob_yScale;  /* 0xcc */

    FUN_0042e850(param_1);

    t = param_1->gob_flashTime - 1;
    param_1->gob_flashTime = t;

    if (t <= 0) {
        FUN_00441150(param_1);
    } else if (t % 2) {
        FUN_00441150(param_1);
    } else {
        unsigned int saved = param_1->gob_pixc;
        param_1->gob_pixc = 0x1d001d00;
        FUN_00441150(param_1);
        param_1->gob_pixc = saved;
    }

    param_1->gob_xpos = xpos;
    param_1->gob_ypos = ypos;
    param_1->gob_xScale = xscale;
    param_1->gob_yScale = yscale;

    if (DAT_0045b128 != 0) {
        FUN_0042f910_GRAPHICSDRAWING(param_1, (unsigned int)param_1->gob_work4);
    }
}
