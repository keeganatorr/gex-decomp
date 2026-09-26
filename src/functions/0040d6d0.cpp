// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct LoadData { int a, b, count8, countc; int *state; } LoadData;
typedef struct GroupEntry { LoadData *data; int b; } GroupEntry;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    LoadData *gob_objectLoadData;   /* 0x0c */
    unsigned char _pad1[0x74];
    LoadData *gob_maxxVel;          /* 0x84 */
    unsigned char _pad2[0x30];
    unsigned int gob_flashTime;     /* 0xb8 */
} GXObject;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern GroupEntry *FirstObjectGroup_004a2934;
void __cdecl GEX_Target(GXObject *gob)
{
    int ok = 0;
    LoadData *data = gob->gob_objectLoadData;
    if (data && data->count8 && data->countc > 0 && *data->state == 1)
        ok = 1;
    if (gob->gob_flashTime && ok) {
        gob->gob_maxxVel = data;
        gob->gob_flashTime = (unsigned int)FirstObjectGroup_004a2934[(gob->gob_flashTime & 0xffff) - 1].data;
    } else
        gob->gob_flashTime = (unsigned int)data;
    gob->gob_objectLoadData = (LoadData *)gob->gob_flashTime;
}
}
