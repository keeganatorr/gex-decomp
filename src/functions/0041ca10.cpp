typedef struct ObjectList { void *head; int a; int b; } ObjectList;
extern "C" {
extern ObjectList gFreeCollisionObjects_00463728;
extern ObjectList gCollisionObjects_00463680;
extern ObjectList CollideObject_00463698[12];
extern void __cdecl LST_Init_0042cc50(ObjectList *);
extern void __cdecl LST_AddTail_0042cc00(ObjectList *, void *);
extern void * __cdecl MEM_AllocMem_004096c0(int);
void __cdecl CLD_InitCollides_0041ca10(void)
{
    char *entry;
    int n;
    ObjectList *list;
    LST_Init_0042cc50(&gFreeCollisionObjects_00463728);
    LST_Init_0042cc50(&gCollisionObjects_00463680);
    entry = (char *)MEM_AllocMem_004096c0(100 * 12);
    n = 100;
    do {
        LST_AddTail_0042cc00(&gFreeCollisionObjects_00463728, entry);
        entry += 12;
    } while (--n);
    for (list = CollideObject_00463698; list <= &CollideObject_00463698[11]; list++)
        LST_Init_0042cc50(list);
}
}
