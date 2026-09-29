// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char _pad1[0x18];
    int gob_state;              /* 0x70 */
    unsigned char _pad2[0x10];
    int gob_maxxVel;            /* 0x84 */
    unsigned char _pad3[0x10];
    int gob_work0;              /* 0x98 */
    int gob_work1;              /* 0x9c */
    int gob_work2;              /* 0xa0 */
} GXObject;
extern "C" {
extern unsigned char gInputControllers_004a0280[];
extern void __cdecl GOB_ResetState_00420bc0(GXObject *);
extern void __cdecl PlayerWalk_004247b0(GXObject *);
void __cdecl PlayerStartWalkImpl_004248e0(GXObject *gob)
{
    GOB_ResetState_00420bc0(gob);
    gob->gob_state = 0x15;
    gob->gob_currentFrameIndex = 0;
    gob->gob_currentFrameGroup = 0x25;
    gob->gob_maxxVel = 0x60000;
    gob->gob_work0 = 2;
    gob->gob_work1 = 0;
    gob->gob_work2 = gInputControllers_004a0280[1];
    PlayerWalk_004247b0(gob);
}
}
