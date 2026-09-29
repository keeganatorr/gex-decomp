extern "C" {
extern "C" void __cdecl FUN_00431730(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);
extern "C" void** __cdecl FUN_0041A380(void**);
extern "C" void __cdecl FUN_004327F0(void*);

extern "C" void __cdecl FUN_00432930_next_gOb(void** param1)
{
    if (param1[0x59] != 0)
        FUN_00432930_next_gOb((void**)param1[0x59]);
    if (param1[0x58] != 0)
        FUN_00432930_next_gOb((void**)param1[0x58]);
    FUN_00431730(param1);
    param1[0x17] = 0;
    param1[0x19] = 0;
    param1[0x1b] = (void*)((unsigned int)param1[0x1b] & 0xffbfffff);
    param1[0x26] = 0;
    param1[0x18] = (void*)&FUN_004327F0;
    param1[0x28] = (void*)0x1e;
    param1[0x27] = 0;
    FUN_0041E7C0(param1);
    void** frame = FUN_0041A380(param1);

    unsigned int f = (unsigned int)param1[0x1b] & 0x40000000;
    int a;
    int b;
    if (f)
        a = -(int)frame[3];
    else
        a = (int)frame[1];
    if (f)
        b = -(int)frame[1];
    else
        b = (int)frame[3];
    param1[0x2a] = 0;
    param1[0x2b] = (void*)(a + ((b - a + 1) >> 1));
}
}
