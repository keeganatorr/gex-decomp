struct GXObject;
// LST_InsertBefore: the original accesses next at +0 and previous at +4.
// Only this intrusive-list prefix is reconstructed; no GXObject layout is inferred.
struct Node {
    Node *next;
    Node *previous;
};
extern "C" void __cdecl GEX_Target(Node *next, Node *node)
{
    Node *previous = next->previous;
    node->previous = previous;
    node->next = next;
    previous->next = node;
    next->previous = node;
}
