extern "C" void FUN_0041A360(int, int);
extern "C" void FUN_004372F0(void *);
extern "C" int FUN_0045ACC0;
extern "C" unsigned char DAT_004A2540[];

struct GXObject {
    unsigned char pad00[0x54];
    unsigned int  field54;          /* +0x54 */
    unsigned char pad58[0x9c - 0x58];
    unsigned int  index;            /* +0x9c */
    unsigned int  padA0;
    unsigned int  flags;            /* +0xa4 */
};

extern "C" void __cdecl ob220DoIt_00429ac0(GXObject *obj)
{
    unsigned int flags = obj->flags;

    if ((flags & 0x200) != 0 && (flags & 0x400) != 0 &&
        (DAT_004A2540[obj->index] & 1) != 0) {
        if ((flags & 0x40000000) == 0) {
            FUN_0041A360(0x65, 0xff);
            obj->field54 = 0;
            FUN_004372F0(obj);
        }
        else if ((flags & 0x20000000) != 0) {
            FUN_0045ACC0 = 1;
        }
        obj->flags &= 0xfffffbffu;
    }
}
