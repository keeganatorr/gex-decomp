typedef struct GXObject GXObject;
typedef void (__cdecl *GXDoItFunc)(GXObject *);

struct GXObject {
    GXObject *next;                    /* 0x00 */
    unsigned char pad_04[0x5c - 0x04]; /* 0x04 */
    GXDoItFunc doit;                   /* 0x5c */
    unsigned char pad_60[0x6c - 0x60]; /* 0x60 */
    unsigned int flags;                /* 0x6c */
};

typedef struct GexObjectList {
    GXObject *head;
    GXObject *tail;
    int count;
} GexObjectList;

extern "C" GXObject *GOB_ObjectsMem_004a27a0;
extern "C" GexObjectList ListType_ARRAY_004a28a0[10];

static int isObjectNodeOrSentinel(GXObject *object)
{
    for (int i = 0; i != 10; ++i) {
        if ((char *)&ListType_ARRAY_004a28a0[i] + 4 == (char *)object)
            return 1;
    }
    unsigned int base = (unsigned int)GOB_ObjectsMem_004a27a0;
    unsigned int address = (unsigned int)object;
    if (base == 0 || address < base) return 0;
    unsigned int offset = address - base;
    return offset < 100 * 0x204 && offset % 0x204 == 0;
}

static int isGameCallback(GXDoItFunc callback)
{
    unsigned int address = (unsigned int)callback;
    unsigned int section = address >> 16;
    unsigned int offset = address & 0xffff;
    return (section > 0x40 && section < 0x44) ||
           (section == 0x40 && offset >= 0x1000) ||
           (section == 0x44 && offset < 0xbd54);
}

extern "C" {
void __cdecl FUN_0042CBF0(GXObject *obj);
void __cdecl FUN_0042CC00(void *list, GXObject *obj);
extern int DAT_004A27A4;
extern unsigned char DAT_004A27B0;
}

extern "C" void __cdecl GOB_DoIt_0040ef40(GXObject *p)
{
    while (p != 0 && isObjectNodeOrSentinel(p)) {
        GXObject *next = p->next;
        if (next == 0) break;
        if (!isObjectNodeOrSentinel(next)) break;
        if ((p->flags & 0x100000u) != 0) {
            GXObject *obj = p;
            p = next;
            FUN_0042CBF0(obj);
            FUN_0042CC00(&DAT_004A27B0, obj);
            --DAT_004A27A4;
        } else {
            if (p->doit != 0 && isGameCallback(p->doit))
                (*p->doit)(p);
            p = next;
        }
    }
}
