extern "C" {
extern "C" void __cdecl FUN_00421cd0(void**);
extern "C" void __cdecl FUN_00411A40(void**);

extern "C" void __cdecl PlayerPlatAirToSideCrawl_00414240(void** p)
{
    FUN_00421cd0(p);
    int v = (int)p[0x26] + 1;
    p[0x26] = (void*)v;
    if (v >= 1) {
        int s = (int)p[0x15];
        if (s == 4) {
            FUN_00411A40(p);
            return;
        }
        p[0x26] = 0;
        p[0x15] = (void*)(s + 1);
    }
}
}
