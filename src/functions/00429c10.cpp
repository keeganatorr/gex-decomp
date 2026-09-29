// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    struct GXObject *gob_next;  /* 0x00 gob_node.next */
    struct GXObject *gob_prev;  /* 0x04 */
    int gob_type;               /* 0x08 */
    unsigned char _pad0[0x90];
    unsigned int gob_work1;     /* 0x9c */
} GXObject;
typedef struct ObjectList { GXObject *head; int a; int b; } ObjectList;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern ObjectList ListType_ARRAY_004a28a0[10];
GXObject * __cdecl FUN_00429c10_Object_unk(unsigned int id)
{
    ObjectList *list;
    GXObject *gob;
    for (list = ListType_ARRAY_004a28a0; list < &ListType_ARRAY_004a28a0[10]; list++)
        for (gob = list->head; gob->gob_next; gob = gob->gob_next)
            if (gob->gob_type == 0x10e && (gob->gob_work1 >> 16) == id)
                return gob;
    return 0;
}
}
