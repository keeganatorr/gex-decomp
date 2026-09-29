typedef struct GXObject {
    unsigned char _pad0[8];
    int gob_type;               /* 0x08 */
    unsigned char _padc[0x6c - 0xc];
    unsigned int gob_flags;     /* 0x6c */
} GXObject;
typedef struct CLDNode CLDNode;
struct CLDNode {
    CLDNode *next;
    CLDNode *prev;
    GXObject *obj;
};
typedef struct CLDList {
    CLDNode *head;
    CLDNode *tail;
    CLDNode *tailPred;
} CLDList;
extern "C" {
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
extern int decl_pad_10;
extern CLDList gCollisionObjects_00463680;
extern CLDList CollideObject_00463698[12];
extern CLDList gFreeCollisionObjects_00463728;
extern int gNumCollideObjects_004a23c0;
extern int DAT_00463734;
extern int DAT_0046368c;
extern int DAT_00463690;
extern int DAT_00463738;
extern char s_Error_Object_on_MOVE_list_00459598[];
extern char s_Error_Object_Typ_00459528[];
extern char s_Error_Processing_collisions_00459568[];
void __cdecl CLD_ResetCollides_0041e700(void);
void __cdecl CLD_CallAllCollisions_0041e710(void);
void __cdecl CLD_CollideWithRest_0041e720(int type, CLDNode *node);
CLDNode *__cdecl LST_RemTail_0042cc20(CLDList *list);
void __cdecl LST_Remove_0042cbf0(CLDNode *node);
void __cdecl LST_AddTail_0042cc00(CLDList *list, CLDNode *node);
void __cdecl assertfail_00405350(const char *format, ...);
void __cdecl CLD_ProcessCollisions_0041e5c0(void)
{
    CLDNode *node;
    CLDNode *next;
    int i;
    CLDNode *cur;
    CLD_ResetCollides_0041e700();
    DAT_00463734 = 0;
    DAT_0046368c = 0;
    DAT_00463690 = 0;
    DAT_00463738 = 0;
    while ((node = LST_RemTail_0042cc20(&gCollisionObjects_00463680)) != 0) {
        if (!node->obj) {
            LST_Remove_0042cbf0(node);
            LST_AddTail_0042cc00(&gFreeCollisionObjects_00463728, node);
            gNumCollideObjects_004a23c0--;
        } else {
            if (node->obj->gob_flags & 0x100000)
                assertfail_00405350(s_Error_Object_on_MOVE_list_00459598, node->obj->gob_type);
            LST_AddTail_0042cc00(&CollideObject_00463698[(node->obj->gob_flags & 0xf00) >> 8], node);
        }
    }
    for (i = 0; i <= 11; i++) {
        cur = CollideObject_00463698[i].head;
        while (cur->next) {
            next = cur->next;
            if (!cur->obj) {
                LST_Remove_0042cbf0(cur);
                LST_AddTail_0042cc00(&gFreeCollisionObjects_00463728, cur);
                gNumCollideObjects_004a23c0--;
            } else {
                if (cur->obj->gob_flags & 0x100000)
                    assertfail_00405350(s_Error_Object_Typ_00459528, cur->obj->gob_type);
                CLD_CollideWithRest_0041e720(i, cur);
            }
            cur = next;
        }
        if (gFreeCollisionObjects_00463728.tailPred->next == cur)
            assertfail_00405350(s_Error_Processing_collisions_00459568, i);
    }
    CLD_CallAllCollisions_0041e710();
}
}
