// Only the observed intrusive-list prefix is modeled: next +0, previous +4.
typedef struct Node {
    struct Node *next;
    struct Node *previous;
} Node;
// EAX contains the old predecessor at return. Its original API return type is unproven.
Node *__cdecl LST_InsertBefore_0042cbb0(Node *next, Node *node)
{
    Node *previous = next->previous;
    node->previous = previous;
    node->next = next;
    previous->next = node;
    next->previous = node;
    return previous;
}
