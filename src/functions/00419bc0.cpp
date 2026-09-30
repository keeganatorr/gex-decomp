// Adapted from pc_decomp_backup/src/functions/FUN_00419BC0.cpp
// Historical source SHA256: c6e7c9176bfcc4e3c13ce079889cf379ff051436131552f7a0e10697ec4b3de8
struct GOBListNode {
    GOBListNode *next;
    GOBListNode *previous;
};

extern "C" {
extern GOBListNode *GOB_ObjectsMem_004a27a0;
extern unsigned char ListType_ARRAY_004a28a0[];
extern "C" void __cdecl FUN_0042CBF0(void**);
extern "C" void __cdecl FUN_0042CBB0(void**, void**);

static int isGOBListNode(GOBListNode *node)
{
    unsigned int address = (unsigned int)node;
    unsigned int base = (unsigned int)GOB_ObjectsMem_004a27a0;
    unsigned int offset;
    int i;

    for (i = 0; i < 10; ++i) {
        unsigned char *list = ListType_ARRAY_004a28a0 + i * 12;
        if ((unsigned char *)node == list ||
            (unsigned char *)node == list + 4)
            return 1;
    }
    if (base == 0 || address < base)
        return 0;
    offset = address - base;
    return offset < 100 * 0x204 && offset % 0x204 == 0;
}

static int isGOBObject(GOBListNode *node)
{
    unsigned int address = (unsigned int)node;
    unsigned int base = (unsigned int)GOB_ObjectsMem_004a27a0;
    unsigned int offset;

    if (base == 0 || address < base)
        return 0;
    offset = address - base;
    return offset < 100 * 0x204 && offset % 0x204 == 0;
}

static GOBListNode *findGOBSuccessor(GOBListNode *node)
{
    GOBListNode *found = 0;
    unsigned int base = (unsigned int)GOB_ObjectsMem_004a27a0;
    int i;

    if (base == 0)
        return 0;
    for (i = 0; i < 100; ++i) {
        GOBListNode *candidate = (GOBListNode *)(base + i * 0x204);
        if (candidate->previous == node &&
            isGOBListNode(candidate->next) &&
            candidate->next->previous == candidate) {
            if (found)
                return 0;
            found = candidate;
        }
    }
    for (i = 0; i < 10; ++i) {
        GOBListNode *tail = (GOBListNode *)(ListType_ARRAY_004a28a0 + i * 12 + 4);
        if (tail->previous == node) {
            if (found)
                return 0;
            found = tail;
        }
    }
    return found;
}

static int hasValidGOBLinks(GOBListNode *node)
{
    GOBListNode *successor;

    if (!isGOBObject(node) || !isGOBListNode(node->previous) ||
        node->previous->next != node)
        return 0;
    if (isGOBListNode(node->next) && node->next->previous == node)
        return 1;
    successor = findGOBSuccessor(node);
    if (!successor)
        return 0;
    node->next = successor;
    return 1;
}

extern "C" void __cdecl GOB_PutObjectBehindObject_00419bc0(void** p1, void** p2) {
    if (p1 == p2 || !hasValidGOBLinks((GOBListNode *)p1) ||
        !hasValidGOBLinks((GOBListNode *)p2))
        return;
    FUN_0042CBF0(p1);
    FUN_0042CBB0(p2, p1);
}
}
