extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" int CAMERA_XPos_004A2A38;
extern "C" int CAMERA_YPos_004A2A1C;

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* gOb;
    void* gOb_00;
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    unsigned int flags = (unsigned int)param_1[0x38];
    param_1[0x38] = (void*)((((flags * 2) ^ flags) & 0x200) ^ flags);
    param_1[0x38] = (void*)((unsigned int)param_1[0x38] & 0xfffffeffU);
    gOb = param_1[0x26];
    gOb_00 = param_1[0x27];

    if (FUN_0040FCE0(param_1) == 0) {
        int dx = (int)param_1[0x1e] - CAMERA_XPos_004A2A38 - 0xa00000;
        int dy = (int)param_1[0x1f] - CAMERA_YPos_004A2A1C - 0x780000;
        if (gOb != 0) {
            ((int*)gOb)[0x1e] = (int)param_1[0x1e] - (dx >> 1);
            ((int*)gOb)[0x1f] = (int)param_1[0x1f] - (dy >> 1);
        }
        if (gOb_00 != 0) {
            ((int*)gOb_00)[0x1e] = (int)param_1[0x1e] + dx;
            ((int*)gOb_00)[0x1f] = (int)param_1[0x1f] + dy;
        }
    } else {
        if (gOb_00 != 0) FUN_00419520((void**)gOb_00);
        if (gOb != 0) FUN_00419520((void**)gOb);
    }
    if (param_1[0x45] == (void*)-1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = (void*)-1;
}
