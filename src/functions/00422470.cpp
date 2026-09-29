extern "C" {
extern int DAT_0045AAEC;
extern int DAT_004A0224;
extern int DAT_004A0254;
extern void* DAT_004A27FC;
extern int DAT_004A281C;
extern void* DAT_004A2888;
extern int DAT_00456AFC;

void __cdecl FUN_00405350(int);
void __cdecl FUN_0041A250(void**, int, int, int);
void __cdecl FUN_00422360(int);

void __cdecl FUN_00422470_EatObjects(void** gOb)
{
    if (DAT_004A2888 != (void*)0x0) {
        FUN_00405350((int)&DAT_0045AAEC);
        return;
    }
    if ((int)gOb[2] >= 0x39 && (int)gOb[2] <= 0x42) {
        DAT_004A0254 = 1;
        DAT_004A0224 = (int)gOb[2] - 0x39;
        FUN_00422360((int)DAT_004A27FC);
        DAT_004A2888 = (void*)gOb;
        return;
    }
    if ((int)gOb[2] == 0x130) {
        FUN_0041A250(gOb, 0x91, 0x80, 0x60);
        if (DAT_004A281C < DAT_00456AFC) {
            DAT_004A281C = DAT_004A281C + 1;
        }
        DAT_004A2888 = (void*)gOb;
    }
}
}
