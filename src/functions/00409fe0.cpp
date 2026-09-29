// Adapted from pc_decomp_backup/src/functions/FUN_00409FE0.cpp
// Historical source SHA256: c54497e05272e0930cd3f2b1834d9cec53d8f5842a130119177283585faaab56
extern "C" {
extern "C" { extern void* DAT_00487F70; }
extern "C" { extern int DAT_004A295C; }

extern "C" void __cdecl FUN_00409fe0_RestartHWND()
{
    void** base;
    int outer;
    void** p;
    int inner;

    DAT_004A295C = 0;
    base = (void**)DAT_00487F70;

    for (outer = 0xf0; outer; outer--)
    {
        p = base;
        inner = 0xa0;
        while (inner)
        {
            *p++ = 0;
            inner--;
        }
        base += 0x200;
    }
}
}
