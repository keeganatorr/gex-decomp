// Field names from Ghidra's GXObject/CollideObject layouts (evidence, not proof).
typedef struct GXObject GXObject;
typedef void (__cdecl *CheckClidFunc)(GXObject *gob, GXObject *with);
struct GXObject {
    unsigned char _pad0[0x16c];
    CheckClidFunc gob_pCheckClidFunc;  /* 0x16c */
};
typedef struct NodeType { struct NodeType *nd_next; struct NodeType *nd_prev; } NodeType;
typedef struct CollideObject {
    NodeType clo_node;       /* 0x0 */
    GXObject *clo_pgobThis;  /* 0x8 */
} CollideObject;
extern "C" {
extern unsigned int DAT_004594F8[12];
extern CollideObject CollideObject_00463698[12];
void __cdecl CLD_CheckCollisionNormal_0041e190(GXObject *gob, GXObject *with);
void __cdecl GEX_Target(int priority, CollideObject *self)
{
    GXObject *other;
    GXObject *gob;
    CollideObject *clo;
    CheckClidFunc check;
    unsigned int bit;
    gob = self->clo_pgobThis;
    bit = 1 << priority;
    clo = (CollideObject *)self->clo_node.nd_next;
    while (priority <= 11) {
        if (DAT_004594F8[priority] & bit) {
            while (clo->clo_node.nd_next) {
                other = clo->clo_pgobThis;
                clo = (CollideObject *)clo->clo_node.nd_next;
                if (other && gob != other) {
                    check = other->gob_pCheckClidFunc;
                    if (check != CLD_CheckCollisionNormal_0041e190) {
                        if (check)
                            check(other, gob);
                    } else {
                        check = gob->gob_pCheckClidFunc;
                        if (check)
                            check(gob, other);
                    }
                }
            }
        }
        if (++priority <= 11)
            clo = (CollideObject *)CollideObject_00463698[priority].clo_node.nd_next;
    }
}
}
