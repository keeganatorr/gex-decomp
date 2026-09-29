struct GXObject;
extern "C" {
extern int __cdecl FUN_0042d7b0_Xor_Stub(GXObject *, int);
extern GXObject *gPlayerObject_004a27fc;
int __cdecl FUN_0042db90_ObjCallUnk(GXObject *gob, int arg)
{
    if (gob != gPlayerObject_004a27fc)
        return FUN_0042d7b0_Xor_Stub(gob, arg);
    return 0;
}
}
