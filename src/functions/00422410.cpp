// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x8];
    int gob_type;  /* 0x08 */
} GXObject;
extern "C" {
extern GXObject *gEatingObject_004a2888;
extern int DAT_004a0218_pState;
extern int DAT_004a0254_Collision;
extern int DAT_004a0224_EatenObjectType;
extern int DAT_00458c88;
extern void __cdecl GOB_Remove_00419a80(GXObject *);
void __cdecl GEX_Target(void)
{
    int *type;
    if (gEatingObject_004a2888) {
        DAT_004a0218_pState = 0x6d;
        type = &gEatingObject_004a2888->gob_type;
        if ((*type >= 0x39 && *type <= 0x42) || *type == 0x130 || *type == 0xea) {
            DAT_004a0254_Collision = 1;
            DAT_004a0224_EatenObjectType = *type - 0x39;
            GOB_Remove_00419a80(gEatingObject_004a2888);
        } else
            DAT_00458c88 = 1;
    }
}
}
