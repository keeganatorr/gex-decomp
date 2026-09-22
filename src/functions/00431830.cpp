extern "C" {
int __cdecl FUN_0040F170(int, unsigned int, unsigned int);
void __cdecl FUN_0042CEC0(int, void**, void (__cdecl *)(void), int);
void __cdecl LAB_00431820(void);
extern int FUN_004A2990;
extern unsigned int DAT_0045B9A0[];
extern int DAT_00463FE0;

void __cdecl GEX_Target(void** param1, unsigned int param2, unsigned int param3) {
    DAT_00463FE0 = 0;
    unsigned int id = FUN_0040F170(FUN_004A2990, param2, param3);
    if ((DAT_0045B9A0[id * 8] & 0x80000000) != 0) {
        void* savedX = param1[0x1e];
        void* savedY = param1[0x1f];
        void* savedDX = param1[0x35];
        void* savedDY = param1[0x36];
        param1[0x1e] = (void*)param2;
        param1[0x1f] = (void*)param3;
        *(void* volatile*)&param1[0x35] = (void*)(param2 - (unsigned int)param1[0x20]);
        param1[0x35] = (void*)(param3 - (unsigned int)param1[0x23]);
        DAT_00463FE0 = 0;
        FUN_0042CEC0(FUN_004A2990, param1, LAB_00431820, 0);
        param1[0x1e] = savedX;
        param1[0x1f] = savedY;
        param1[0x35] = savedDX;
        param1[0x36] = savedDY;
    }
}
}
