extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" void __cdecl FUN_00411ff0(void**, int, int);
extern void** FUN_004A2864;

extern "C" void __cdecl GEX_Target(void** param1, int param2, int param3)
{
    struct {
        int pad[6];
        int local_10;
        int local_c;
        int local_8;
        int local_4;
    } L;

    char* p = (char*)param1;

    FUN_00420BC0(param1);
    if (FUN_004A2864 != 0)
    {
        int iVar1 = FUN_0041CB80(FUN_004A2864, L.pad);
        if (iVar1 != 0)
        {
            unsigned u = *(unsigned*)(p + 0x6c);
            int v = *(int*)(p + 0xc4);
            unsigned ang = ((u & 0x80000000u) >> 28) | (unsigned)(v >> 21);

            if (param2 != 0)
            {
                void* pGVar2;
                if (ang != 0xe)
                    pGVar2 = (void*)(L.local_10 - 0x180000);
                else
                    pGVar2 = (void*)(L.local_c + 0x180000);
                *(void**)(p + 0x78) = pGVar2;
            }
            if (param3 != 0)
                *(void**)(p + 0x7c) = (void*)(L.local_4 + 0x180000);

            FUN_00411ff0(param1, (param2 == 0) ? 0 : 2, (param3 == 0) ? 0 : 2);
        }
    }
}
}
