// Adapted from pc_decomp_backup/src/functions/FUN_00422470.cpp
// Historical source SHA256: 0edbfe654ce05a7f3af9e17bd6b42246266b90853452542346b0775f117b948e
extern "C" {
extern "C" { extern int DAT_0045AAEC; }
extern "C" { extern int DAT_004A0224; }
extern "C" { extern int DAT_004A0254; }
extern void* DAT_004A27FC;
extern "C" { extern int DAT_004A281C; }
extern void* DAT_004A2888;
extern "C" { extern int DAT_00456AFC; }

extern "C" void __cdecl FUN_00405350(int, int);
extern "C" void __cdecl FUN_0041A250(void**, int, int);
extern "C" void __cdecl FUN_00422360(int);

extern "C" void __cdecl GEX_Target(void** gOb)
{
    if (DAT_004A2888 != (void*)0x0) {
        FUN_00405350((int)&DAT_0045AAEC, 0);
        return;
    }
    if ((int)gOb[2] > 0x38 && (int)gOb[2] < 0x43) {
        DAT_004A0254 = 1;
        DAT_004A0224 = (int)gOb[2] - 0x39;
        FUN_00422360((int)DAT_004A27FC);
        DAT_004A2888 = (void*)gOb;
        return;
    }
    if ((int)gOb[2] == 0x130) {
        FUN_0041A250(gOb, 0x91, 0x80);
        if (DAT_004A281C < DAT_00456AFC) {
            DAT_004A281C = DAT_004A281C + 1;
        }
        DAT_004A2888 = (void*)gOb;
    }
}
}
