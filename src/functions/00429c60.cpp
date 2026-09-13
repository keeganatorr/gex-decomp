// Minimal observed object prefix and ten 12-byte sentinel-list headers.
struct Object { Object* next; Object* previous; int type; };
struct List { Object* head; Object* tailSentinel; Object* tailPrevious; };
extern "C" List objectLists_004a28a0[10];
extern "C" Object* __cdecl GEX_Target(int type)
{
    List* list = objectLists_004a28a0;
    do
    {
        Object* object = list->head;
        while (object->next)
        {
            if (object->type == type) return object;
            object = object->next;
        }
        ++list;
    } while (list < objectLists_004a28a0 + 10);
    return 0;
}
