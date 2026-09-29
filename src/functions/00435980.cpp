extern "C" {
extern "C" void __cdecl FUN_00435a10(void**);
extern "C" void __cdecl FUN_00441150(void*);
extern "C" void __cdecl FUN_00444590(void*);
extern "C" { extern int DAT_0045b7b4; }

extern "C" void __cdecl ob2Draw_00435980(void** gOb)
{
    int val = (int)gOb[0x1c];
    switch (val) {
    case 0:
        FUN_00435a10(gOb);
        gOb[0x15] = gOb[0x26];
        gOb[0x14] = 0;
        if (((unsigned int)gOb[0x2d] & 1) != 0) {
            int tmp = (int)gOb[0x2a] + DAT_0045b7b4;
            gOb[0x2a] = (void*)tmp;
            tmp &= 0xff0000;
            gOb[0x2a] = (void*)tmp;
            gOb[0x31] = (void*)tmp;
            FUN_00441150(gOb);
            gOb[0x31] = 0;
            return;
        }
        FUN_00444590(gOb);
        return;
    case 1:
        FUN_00444590(gOb);
        return;
    }
}
}
