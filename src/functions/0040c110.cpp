typedef struct GXObject GXObject;
struct GXObject {
    GXObject *gob_next;         /* 0x00 */
    int unk4;
    int gob_type;               /* 0x08 */
    unsigned char padc[0x98 - 0xc];
    int gob_work0;              /* 0x98 */
};
typedef struct ObjectList {
    GXObject *head;
    int a;
    int b;
} ObjectList;

extern "C" {
extern ObjectList ListType_ARRAY_004a28a0[10];

GXObject *__cdecl GOB_FindWithWork0_0040c110(int type, int work0)
{
    int i;
    GXObject *gob;
    int found;

    found = 0;
    for (i = 0; i < 10; i++) {
        for (gob = ListType_ARRAY_004a28a0[i].head; gob->gob_next; gob = gob->gob_next)
            if (gob->gob_type == type && gob->gob_work0 == work0) {
                found = 1;
                break;
            }
        if (found)
            break;
    }
    return found ? gob : 0;
}
}
