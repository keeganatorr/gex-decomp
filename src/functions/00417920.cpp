extern "C" int *gEatingObject_004a2888;
extern "C" int *gPlayerObject_004a27fc;
extern "C" void FUN_00423130_pStateUnk_Eating(int *);

extern "C" void GEX_Target(int param_1, int *param_2)
{
    int *obj;
    if (*param_2 == 0) return;
    obj = *(int **)(param_1 + 0x178);
    if (gEatingObject_004a2888 != 0) return;
    if ((obj[27] & 0x200000) == 0) return;
    gEatingObject_004a2888 = obj;
    FUN_00423130_pStateUnk_Eating(gPlayerObject_004a27fc);
}
