extern "C" {
struct NodeType {
    struct NodeType *nd_next;
    struct NodeType *nd_prev;
};

struct GXObject {
    struct NodeType gob_node;
};

extern "C" GXObject **__cdecl FUN_0041A380(GXObject **);
extern "C" void __cdecl FUN_00434A20(GXObject **);

extern "C" void __cdecl ob121Init_0043d350(GXObject **param_1)
{
    GXObject *pGVar1;
    NodeType *pNVar2;
    GXObject *pGVar3;
    int bVar4;
    GXObject **ppGVar5;

    bVar4 = 0;
    pGVar1 = param_1[3];
    ppGVar5 = FUN_0041A380(param_1);
    if ((ppGVar5 != (GXObject **)0) && (((unsigned int)*ppGVar5 & 1) != 0)) {
        param_1[0x29] = ppGVar5[7];
    }
    pNVar2 = (pGVar1->gob_node).nd_prev;
    if (((pNVar2 != (NodeType *)0) && (pNVar2 = pNVar2->nd_next, pNVar2 != (NodeType *)0)) &&
        (pGVar3 = (GXObject *)pNVar2->nd_next, pGVar3 != (GXObject *)0)) {
        bVar4 = 1;
        param_1[4] = pGVar3;
        pGVar1 = (GXObject *)((pGVar1->gob_node).nd_prev)->nd_next->nd_prev;
        if (pGVar1 != (GXObject *)0) {
            param_1[0xc] = pGVar1;
        }
    }
    if (bVar4) {
        param_1[0x26] = (GXObject *)0;
    }
    else if (param_1[0x26] == (GXObject *)0) {
        param_1[0x26] = (GXObject *)0x4000;
    }
    FUN_00434A20(param_1);
}
}
