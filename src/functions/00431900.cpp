// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;   /* 0x78 */
    int gob_ypos;   /* 0x7c */
    int gob_xVel;   /* 0x80 */
    unsigned char _pad1[0x8];
    int gob_yVel;   /* 0x8c */
    unsigned char _pad2[0x10];
    int gob_work2;  /* 0xa0 */
} GXObject;
extern "C" {
extern int __cdecl FUN_0041a090(GXObject *);
extern void __cdecl FUN_00431830(GXObject *, int, int);
extern int DAT_0045b150;
extern int DAT_00463fe0;
int __cdecl GEX_Target(GXObject *gob)
{
    if (FUN_0041a090(gob))
        return 1;
    if (gob->gob_work2 > 0) {
        gob->gob_work2--;
        FUN_00431830(gob, gob->gob_xpos - gob->gob_xVel * DAT_0045b150, gob->gob_ypos - gob->gob_yVel * DAT_0045b150);
        if (DAT_00463fe0)
            return 1;
    }
    FUN_00431830(gob, gob->gob_xpos, gob->gob_ypos);
    return DAT_00463fe0 != 0;
}
}
