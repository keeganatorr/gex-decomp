struct NodeType {
    NodeType* nd_next;
    NodeType* nd_prev;
};

struct GXObject {
    NodeType gob_node;
};

extern "C" {
extern void** DAT_004A2990;
extern void FUN_0040B8C0(void*, int, int*, GXObject**);
extern void FUN_0040B940(void*);
extern GXObject* FUN_0040B390(int, unsigned int);
extern void* FUN_00420190(int, unsigned int);

void* GEX_Target(int param_1, int* param_2)
{
    GXObject* local_8;
    int local_4;
    GXObject* pGVar2;
    NodeType* pNVar1;

    FUN_0040B8C0(*DAT_004A2990, param_1, &local_4, &local_8);
    FUN_0040B940(&local_8);
    pGVar2 = FUN_0040B390(local_4, (unsigned int)local_8->gob_node.nd_next);
    *(GXObject* volatile*)&local_8 = pGVar2;
    pNVar1 = pGVar2->gob_node.nd_next;
    while (pNVar1 != 0) {
        local_8->gob_node.nd_next = (NodeType*)FUN_00420190(local_4, (unsigned int)local_8->gob_node.nd_next);
        local_8 = (GXObject*)((char*)local_8 + 4);
        pNVar1 = *(NodeType**)local_8;
    }
    *param_2 = local_4;
    return pGVar2;
}
}
