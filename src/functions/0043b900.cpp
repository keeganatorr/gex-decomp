// This collision callback forwards both arguments without accessing their layout.
extern "C" {
extern void __cdecl FUN_00433690(void *, int *);
void __cdecl ob258Clid_0043b900(void *object, int *collision)
{
    FUN_00433690(object, collision);
}
}
