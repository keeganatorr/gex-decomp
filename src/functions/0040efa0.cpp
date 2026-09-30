extern "C" {
extern int DAT_004A27A4;
extern int DAT_004A2AC8;
extern int DAT_004A27B0;
extern void *GOB_ObjectsMem_004a27a0;
struct GexObjectList { void *head; void *tail; int count; };
extern GexObjectList ListType_ARRAY_004a28a0[10];
extern void __cdecl FUN_0042CBF0(int *object);
extern void __cdecl FUN_0042CC00(int *list, int *object);

typedef void (__cdecl *ObjectCallback)(int *object);

static int isValidObjectNode(int *object)
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

static int isValidObjectCallback(ObjectCallback callback)
{
    unsigned int address = (unsigned int)callback;
    unsigned int section = address >> 16;
    unsigned int offset = address & 0xffff;
    return (section > 0x40 && section < 0x44) ||
           (section == 0x40 && offset >= 0x1000) ||
           (section == 0x44 && offset < 0xbd54);
}

extern "C" void __cdecl GOB_DrawList_0040efa0(int *object)
{
    while (object != 0 && isValidObjectNode(object)) {
        int *next = (int *)object[0];
        if (next == 0 || !isValidObjectNode(next)) break;
        if (object[0x1b] & 0x100000) {
            int *oldobj = object;
            object = next;
            FUN_0042CBF0(oldobj);
            FUN_0042CC00(&DAT_004A27B0, oldobj);
            --DAT_004A27A4;
        } else {
            ObjectCallback callback = (ObjectCallback)object[0x18];
            if (callback != 0 && isValidObjectCallback(callback))
                callback(object);
            if ((object[0x38] & 0x2000000) == 0) {
                object[0x7e] = object[0x1e];
                object[0x7f] = object[0x1f];
            }
            object[0x7d] = DAT_004A2AC8;
            object = next;
        }
    }
}
}
