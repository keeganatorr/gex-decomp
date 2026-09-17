struct GXObjectNode {
    unsigned int nd_next;
};

struct GXObject {
    GXObjectNode gob_node;
};

extern "C" {
    extern GXObject *gPlayerObject_004a27fc;
    void PlayerDamage_00417b70(GXObject **param_1);

    void GEX_Target(GXObject **param_1, int *param_2) {
        if (*param_2 != 0) {
            unsigned int uVar2 = param_1[0x5c]->gob_node.nd_next & 0xffff;
            unsigned int uVar1 = param_1[0x5d]->gob_node.nd_next & 0xffff;
            if (param_1[0x5e] == gPlayerObject_004a27fc &&
                (uVar2 == 1 || uVar2 == 7 ||
                 ((uVar2 == 0 || uVar2 == 8) && (uVar1 == 0 || uVar1 == 8)))) {
                PlayerDamage_00417b70(param_1);
            }
        }
    }
}
