// Field names from Ghidra's GXObject/GXLoadObject layouts (evidence, not proof).
typedef struct GXAniScript { unsigned char *as_script; unsigned char _pad4[0x1c]; } GXAniScript;
typedef struct GXLoadObject {
    void *gxlob_anims;
    unsigned char ***gxlob_scripts;
} GXLoadObject;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    GXLoadObject *gob_objectLoadData;  /* 0xc */
    GXAniScript gob_scripts[2];        /* 0x10 */
    unsigned char _pad50[0x48];
    int gob_work0;                     /* 0x98 */
} GXObject;
extern "C" {
void __cdecl EnemyInitPath_00434a20(GXObject *gob);
void __cdecl ob89Init_0043ce20(GXObject *gob)
{
    GXLoadObject *lob;
    int scripted;
    scripted = 0;
    lob = gob->gob_objectLoadData;
    if (lob->gxlob_scripts && *lob->gxlob_scripts && **lob->gxlob_scripts) {
        scripted = 1;
        gob->gob_scripts[0].as_script = **lob->gxlob_scripts;
        if ((*lob->gxlob_scripts)[1])
            gob->gob_scripts[1].as_script = (*lob->gxlob_scripts)[1];
    }
    if (scripted)
        gob->gob_work0 = 0;
    else if (gob->gob_work0 == 0)
        gob->gob_work0 = 0x4000;
    EnemyInitPath_00434a20(gob);
}
}
