// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    unsigned char _pad1[0x48];
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
    unsigned char _pad2[0x20];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern int DAT_0045ffe8[];
extern void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int);
void __cdecl ob271Init_0043b280(GXObject *gob)
{
    gob->gob_currentFrameGroup = (gob->gob_work1 & 1) == 0;
    gob->gob_angle = DAT_0045ffe8[((gob->gob_work1 & 1) ? 4 : 0) | gob->gob_work2];
    VSIT_PlayVoiceSituation_0041f8c0(0x49);
}
}
