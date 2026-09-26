extern "C" {

struct GXObject {
    GXObject *nd_next;
    GXObject *nd_prev;
    int gob_type;
    char pad[0x9c - 0xc];
    int gob_work1;
};

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
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
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