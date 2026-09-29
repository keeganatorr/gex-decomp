typedef struct GXObject {
    char pad[0x6c];
    unsigned int flags;
} GXObject;

typedef struct ListType {
    GXObject *head;
    GXObject *tail;
    int count;
} ListType;

extern "C" {
    extern ListType ListType_ARRAY_004a28a0;
    extern ListType DAT_004a2918_LevelObjectsListEnd;
    extern ListType GOB_FreeObjectsList_004a27b0;
    extern volatile int gNumObjects_004a27a4;
    extern const char s_ERROR______FREEING_ALL_OBJECTS__L_00458f14[];

    GXObject *LST_RemTail_0042cc20(ListType *list);
    void LST_AddTail_0042cc00(ListType *list, GXObject *obj);
    void GOB_RemoveMapObject_00419840(GXObject *obj);
    void assertfail_00405350(const char *msg);
    void CLD_RemoveAllCollisionObjects_0041e970(void);
}

extern "C" void GOB_FreeAllObjects_00419aa0(void)
{
    ListType *p = &ListType_ARRAY_004a28a0;
    GXObject *gob;

    while (p < &DAT_004a2918_LevelObjectsListEnd) {
        while ((gob = LST_RemTail_0042cc20(p)) != 0) {
            if ((gob->flags & 0x100000) == 0) {
                GOB_RemoveMapObject_00419840(gob);
            }
            LST_AddTail_0042cc00(&GOB_FreeObjectsList_004a27b0, gob);
            gNumObjects_004a27a4--;
        }
        ++p;
    }

    if (gNumObjects_004a27a4 != 0) {
        assertfail_00405350(s_ERROR______FREEING_ALL_OBJECTS__L_00458f14);
    }

    gNumObjects_004a27a4 = 0;
    CLD_RemoveAllCollisionObjects_0041e970();
}
