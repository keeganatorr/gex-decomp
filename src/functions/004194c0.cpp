typedef struct ObjectList { void *head; int a; int b; } ObjectList;
extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern ObjectList GOB_FreeObjectsList_004a27b0;
extern ObjectList ListType_ARRAY_004a28a0[10];
extern void *GOB_ObjectsMem_004a27a0;
extern void __cdecl LST_Init_0042cc50(ObjectList *);
extern void __cdecl LST_AddTail_0042cc00(ObjectList *, void *);
extern void * __cdecl MEM_AllocMem_004096c0(int);
void __cdecl GEX_Target(void)
{
    int n;
    char *object;
    ObjectList *list;
    LST_Init_0042cc50(&GOB_FreeObjectsList_004a27b0);
    object = (char *)MEM_AllocMem_004096c0(100 * 0x204);
    GOB_ObjectsMem_004a27a0 = object;
    n = 100;
    do {
        LST_AddTail_0042cc00(&GOB_FreeObjectsList_004a27b0, object);
        object += 0x204;
    } while (--n);
    for (list = ListType_ARRAY_004a28a0; list < &ListType_ARRAY_004a28a0[10]; list++)
        LST_Init_0042cc50(list);
}
}
