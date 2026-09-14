typedef unsigned int uint;
extern "C" {
extern void *DAT_004A27FC;
extern void __cdecl FUN_00417CA0(uint);
void __cdecl GEX_Target(uint value, void *object)
{
    if (object != DAT_004A27FC)
        return;
    FUN_00417CA0(value);
}
}
