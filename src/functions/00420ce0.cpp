extern "C" {

int __cdecl FUN_00420c70_GexWallCollisionInner(void**);
extern int FUN_004A2990;
int __cdecl FUN_0040F170(int, int, int);

int __cdecl GEX_Target(void** param1) {
    int uVar1 = FUN_00420c70_GexWallCollisionInner(param1);
    if (uVar1 != 0) {
        int uVar2 = 2;
        unsigned int attr = FUN_0040F170(
            FUN_004A2990, (int)param1[0x1e], (int)param1[0x1f]);
        if (attr == 0x52) uVar2 = 8;
        return uVar2;
    }
    return 0;
}

}
