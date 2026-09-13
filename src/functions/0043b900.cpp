// This collision callback forwards both arguments without accessing their layout.
extern "C" {
extern void __cdecl FUN_00433690(void *, int *);
void __cdecl GEX_Target(void *object, int *collision)
{
    FUN_00433690(object, collision);
}
}
