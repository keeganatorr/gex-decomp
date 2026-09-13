// Adapted from pc_decomp_backup/src/functions/FUN_0043A910.cpp
// Historical source SHA256: 41762cf3a5e2eedb1a04fb4af90f0fb2773184150e1ea4d68b14bc48519d21a5
extern "C" {
extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" { extern int CAMERA_XPos_004A2A38; }
extern "C" { extern int CAMERA_YPos_004A2A1C; }

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
    gOb = param_1[0x26];
    gOb_00 = param_1[0x27];
    
    {
        int pGVar2 = (int)param_1[0x38];
        pGVar2 = ((pGVar2 * 2 ^ pGVar2) & 0x200 ^ pGVar2);
        param_1[0x38] = (void*)(pGVar2 & 0xfffffeff);
    }
    
    if (FUN_0040FCE0(param_1) == 0) {
        int iVar3 = (int)param_1[0x1e] + (-0xa00000 - CAMERA_XPos_004A2A38);
        int iVar1 = (int)param_1[0x1f] + (-0x780000 - CAMERA_YPos_004A2A1C);
        if (gOb != 0) {
            ((int*)gOb)[0] = (int)param_1[0x1e] - (iVar3 >> 1);
            ((int*)gOb)[1] = (int)param_1[0x1f] - (iVar1 >> 1);
        }
        if (gOb_00 != 0) {
            ((int*)gOb_00)[0] = (int)param_1[0x1e] + iVar3;
            ((int*)gOb_00)[1] = (int)param_1[0x1f] + iVar1;
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
}
