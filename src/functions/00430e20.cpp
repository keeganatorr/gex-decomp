extern "C" {
void __cdecl GEX_Target(void** param_1)
{
    if ((int)param_1[0x26] == 1) {
        param_1[0x14] = 0;
    } else {
        int v = (int)param_1[0x15] + 1;
        param_1[0x15] = (void*)v;
        if (v < 3) goto LAB;
    }
    param_1[0x15] = 0;
LAB:
    {
        int v = (int)param_1[0x2c] - 1;
        param_1[0x2c] = (void*)v;
        if (v > 0) goto END;
    }
    param_1[0x2c] = (void*)3;
    {
        int v = (int)param_1[0x2b] + 1;
        param_1[0x2b] = (void*)v;
        if (v == 10) param_1[0x2b] = 0;
    }
    ((int*)param_1)[0x1f] = ((int*)param_1)[0x1f] + (((int*)0x45B0B0)[((int*)param_1)[0x2b]] << 16);
END:
    ;
}
}
