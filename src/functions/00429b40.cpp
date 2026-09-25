extern "C" {

struct GXObject {
    GXObject *nd_next;
    GXObject *nd_prev;
    int gob_type;
    char pad[0x9c - 0xc];
    int gob_work1;
};

extern GXObject *ListType_ARRAY_004a28a0[];
extern GXObject *DAT_004a2918_LevelObjectsListEnd;

GXObject * __cdecl GEX_Target(int SelectedTV)
{
    GXObject *gOb_CurrentObject;
    GXObject ***gOb_List;
    gOb_List = (GXObject ***)&ListType_ARRAY_004a28a0;
    do {
        gOb_CurrentObject = (GXObject *)*gOb_List;
        while (gOb_CurrentObject->nd_next) {
            if (gOb_CurrentObject->gob_type == 0xdc && gOb_CurrentObject->gob_work1 == SelectedTV)
                return gOb_CurrentObject;
            gOb_CurrentObject = gOb_CurrentObject->nd_next;
        }
        gOb_List = gOb_List + 3;
    } while ((GXObject **)gOb_List < &DAT_004a2918_LevelObjectsListEnd);
    return 0;
}

}