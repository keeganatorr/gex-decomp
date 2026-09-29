typedef unsigned int uint;
extern "C" {
extern void *DAT_004A27FC;
extern void __cdecl FUN_00417B70(uint);
uint __cdecl FUN_0042de30_ObjCallUnk(void *object)
{
    if (object == DAT_004A27FC)
        FUN_00417B70(0);
    return 0;
}
}
