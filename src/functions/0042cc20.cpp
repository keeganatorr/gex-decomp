struct Node { Node* next; Node* previous; };
struct List { Node* head; Node* tailSentinel; Node* tailPrevious; };
extern "C" void __cdecl LST_Remove_0042cbf0(Node* node);
extern "C" Node* __cdecl GEX_Target(List* list)
{
    Node* node = list->tailPrevious;
    if (node->previous)
        LST_Remove_0042cbf0(node);
    else
        node = 0;
    return node;
}
