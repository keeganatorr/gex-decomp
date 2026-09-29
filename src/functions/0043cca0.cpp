struct Node {
    Node *nd_next;
    Node *nd_prev;
};

struct GobNode {
    Node gob_node;
};

struct GXObject {
    char pad0[0xc];
    GobNode *field_c;
    Node *field_10;
    char pad1[0x30 - 0x14];
    Node *field_30;
    char pad2[0x98 - 0x34];
    int field_98;
};

extern "C" void ob1Init_0043cca0(GXObject *param_1)
{
    int bVar3 = 0;
    GobNode *gob = param_1->field_c;
    Node *pNVar1 = gob->gob_node.nd_prev;
    if (pNVar1 != 0) {
        Node *n1 = pNVar1->nd_next;
        if (n1 != 0) {
            Node *n2 = n1->nd_next;
            if (n2 != 0) {
                bVar3 = 1;
                param_1->field_10 = n2;
                Node *t = gob->gob_node.nd_prev->nd_next;
                Node *pGVar2 = t->nd_prev;
                if (pGVar2 != 0) {
                    param_1->field_30 = pGVar2;
                }
            }
        }
    }
    if (bVar3) {
        param_1->field_98 = 0;
        return;
    }
    if (param_1->field_98 == 0) {
        param_1->field_98 = 0x4000;
    }
}
