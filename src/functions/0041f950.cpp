extern "C" int __cdecl UTL_ReallyRandom_00428c80(int);
extern "C" int __cdecl VFX_SetTableEntry_004019a0(int, int, int);
extern "C" void __cdecl assertfail_00405350(const char *, ...);

extern "C" void __cdecl FUN_0041f950(void)
{
    int count = *(int *)0x004638b4;
    if (count == 0 || *(int *)0x004a298c == 0)
        return;

    int chosen = 0;
    int tries = 32;
    do {
        int index = *(int *)0x004638d0 - UTL_ReallyRandom_00428c80(count) - 1;
        if (index < 0)
            index += 32;
        chosen = ((int *)0x004638d8)[index];
        *(int *)0x004638b0 = ((int *)0x00463958)[index];
        --tries;
    } while ((chosen == *(int *)0x004638c8 ||
              chosen == *(int *)0x004638cc) && tries != 0);

    if (chosen == 0) {
        assertfail_00405350((const char *)0x0045a158);
        return;
    }
    int slot = *(int *)0x004638b8;
    VFX_SetTableEntry_004019a0(*(int *)0x00455b78, chosen, slot);
    *(int *)0x004638c0 = 1;
    ((int *)0x004a02d0)[slot] = 0;
    ((int *)0x004638c8)[slot] = chosen;
}
