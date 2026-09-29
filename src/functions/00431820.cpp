// The callback at 00431820 sets the gameplay flag and reports zero.
// The 13-byte body was inspected in the pinned PE; Ghidra has no function
// inventory entry for this address.
extern "C" int DAT_00463fe0;

extern "C" int __cdecl FUN_00431820(void)
{
    DAT_00463fe0 = 1;
    return 0;
}
