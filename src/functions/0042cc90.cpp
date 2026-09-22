extern "C" {
int __cdecl FUN_0041CB80(void**, int*);
void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern int DAT_00455B8C;
extern int DAT_004A01E4;
extern int CAMERA_XPos_004a2a38;

int __cdecl GEX_Target(void** param1, void (__cdecl *param2)(void**, int)) {
    int edges[10];
    if (DAT_00455B8C != 0) {
        if (FUN_0041CB80(param1, edges) == 0) return 0;
        int delta = edges[7] - CAMERA_XPos_004a2a38;
        if (delta >= 0x1300000) {
            DAT_004A01E4 = 1;
            param1[0x1e] = (char*)param1[0x1e] + (0x12f0000 - delta);
            if (param2 != 0) param2(param1, 0);
            param1[0x39] = (void*)(CAMERA_XPos_004a2a38 + 0x12f0000);
            if (param1[0x3a] != 0) FUN_0042cc70_Object_unk(0, param1);
        }
        delta = edges[6] - CAMERA_XPos_004a2a38;
        if (delta < 0x100000) {
            DAT_004A01E4 = 1;
            param1[0x1e] = (char*)param1[0x1e] + (0x110000 - delta);
            if (param2 != 0) param2(param1, 0);
            param1[0x3a] = (void*)(CAMERA_XPos_004a2a38 + 0x110000);
            if (param1[0x39] != 0) FUN_0042cc70_Object_unk(0, param1);
        }
    }
    return 0;
}
}
