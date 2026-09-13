// This collision callback forwards both arguments without accessing their layout.
extern "C" {
extern void __cdecl FUN_004355D0(void *, unsigned int *);
void __cdecl GEX_Target(void *object, unsigned int *collision)
{
    FUN_004355D0(object, collision);
}
}
