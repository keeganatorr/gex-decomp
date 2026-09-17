typedef struct ObjectIntroTracker {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int *field2C;
    int field30;
    int field34;
    int field38;
} ObjectIntroTracker;

extern "C" void __cdecl GEX_Target(ObjectIntroTracker *pThis, int param_2, int *param_3, int param_4, int param_5, int param_6, int param_7, int param_8)
{
    pThis->field04 = param_2;
    pThis->field0C = param_5;
    pThis->field10 = param_6;
    pThis->field14 = -1;
    pThis->field18 = -1;
    pThis->field1C = -1;
    pThis->field20 = -1;
    pThis->field24 = -1;
    pThis->field28 = -1;
    pThis->field2C = param_3;
    pThis->field30 = param_4;
    pThis->field34 = param_7;
    pThis->field38 = param_8;
}
