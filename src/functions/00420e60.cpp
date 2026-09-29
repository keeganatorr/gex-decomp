// Bubble object callback. Reconstructed from the pinned PE's 00420e60 body.
// A source-level behavior candidate; exact bytes and source types are unproven.
extern "C" {
int __cdecl FUN_0041a480(void*);
unsigned int __cdecl FUN_0040f170(void*, int, int);
int __cdecl FUN_0041a160(void*, void*);
void __cdecl FUN_00444590(void*);
void __cdecl FUN_00419520(void*);
extern void* DAT_004a2990;
extern int DAT_004a2ac8;

void __cdecl GEX_Target(void* bubble)
{
    int* fields = (int*)bubble;
    int remove = 0;
    if (++fields[0x9c / 4] >= 5) {
        fields[0x9c / 4] = 0;
        ++fields[0x54 / 4];
        if (!FUN_0041a480(bubble))
            remove = 1;
    }

    unsigned int tile = FUN_0040f170(DAT_004a2990,
                                     fields[0x78 / 4], fields[0x7c / 4]);
    if (tile == 0x54)
        fields[0x78 / 4] -= 0x20000;
    else if (tile == 0x55)
        fields[0x78 / 4] += 0x20000;
    else
        remove = 1;

    if (!remove && FUN_0041a160(DAT_004a2990, bubble)) {
        int oldX = fields[0x7c / 4];
        fields[0x7c / 4] = oldX + ((DAT_004a2ac8 & 4) ? -0x10000 : 0) - 0x80000;
        FUN_00444590(bubble);
        fields[0x7c / 4] = oldX;
    } else {
        FUN_00419520(bubble);
    }
}
}
