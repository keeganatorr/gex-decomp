extern "C" {
void __cdecl FUN_0041b700_ObjCallUnkInner(void*);
void** __cdecl FUN_004195D0(int, int, int, int);
int __cdecl FUN_0042d910_RightWallCollision(void**, int);

extern void** FUN_004A27FC;
extern void** DAT_004a23d4;
extern int DAT_004a23c8;
extern int DAT_004a2890_velocity_unk;
extern int DAT_0045b038;

int __cdecl GEX_Target(void** param1, int param2)
{
    if (param1 == FUN_004A27FC) {
        if (DAT_004a23d4 != 0)
            FUN_0041b700_ObjCallUnkInner(DAT_004a23d4);
        void** ppGVar1 = FUN_004195D0(0x11c, (int)param1[0x61], (int)param1[0x1f], 0);
        if (ppGVar1 != 0) {
            DAT_004a23d4 = ppGVar1;
            ppGVar1[0x29] = (void*)1;
        }
        FUN_0042d910_RightWallCollision(param1, param2);
        param1[0x20] = (void*)-*(int*)((int)&DAT_0045b038 + DAT_004a23c8 * 0xc);
        param1[0x23] = (void*)*(int*)((int)&DAT_0045b038 + 4 + DAT_004a23c8 * 0xc);
        DAT_004a23c8 = DAT_004a23c8 + 1;
        DAT_004a2890_velocity_unk = *(int*)((int)&DAT_0045b038 + 8 + (DAT_004a23c8 - 1) * 0xc);
        if (DAT_004a23c8 == 4)
            DAT_004a23c8 = DAT_004a23c8 - 1;
        return 0;
    }
    return FUN_0042d910_RightWallCollision(param1, param2);
}
}
