// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    struct GXObject *gob_next;  /* 0x00 gob_node.next */
    struct GXObject *gob_prev;  /* 0x04 */
    int gob_type;               /* 0x08 */
    unsigned char _pad0[0x98];
    unsigned int gob_work3;     /* 0xa4 */
} GXObject;
typedef struct ObjectList { GXObject *head; int a; int b; } ObjectList;
extern "C" {
extern ObjectList ListType_ARRAY_004a28a0[10];
GXObject * __cdecl GEX_Target(void)
{
    ObjectList *list;
    GXObject *gob;
    for (list = ListType_ARRAY_004a28a0; list < &ListType_ARRAY_004a28a0[10]; list++)
        for (gob = list->head; gob->gob_next; gob = gob->gob_next)
            if (gob->gob_type == 0xdc && (gob->gob_work3 & 0x80000000))
                return gob;
    return 0;
}
}
