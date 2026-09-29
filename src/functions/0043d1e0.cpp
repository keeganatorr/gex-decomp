typedef unsigned int uint;
typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;
extern "C" {
extern void __cdecl FUN_00434A20(void *);
void __cdecl ob120Init_0043d1e0(int **object)
{
    Node *node = *(Node **)((char *)object[3]);
    node = node->next->next;
    if (node != 0 && (((uint)node->next & 1) != 0))
        object[0x29] = (int *)node[3].prev;
    if (object[0x26] == 0)
        object[0x26] = (int *)0x4000;
    FUN_00434A20(object);
}
}
