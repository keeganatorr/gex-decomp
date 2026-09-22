extern "C" int GXObject_00463b70_gob_xScale[];

extern "C" void GEX_Target(int *param_1)
{
    int value;

    if (param_1[44] != param_1[43]) {
        value = param_1[43] + (param_1[45] >> 24);
        param_1[43] = value;

        if (value > 8)
            param_1[43] = value - 8;

        switch (param_1[43]) {
        case 0:
            param_1[20] = 0x1a;
            param_1[40] = 10;
            param_1[50] = GXObject_00463b70_gob_xScale[50];
            return;
        case 1:
            param_1[20] = 0x17;
            param_1[40] = 10;
            param_1[50] = -GXObject_00463b70_gob_xScale[50];
            return;
        case 2:
            param_1[20] = 0x1c;
            param_1[40] = 10;
            param_1[50] = -GXObject_00463b70_gob_xScale[50];
            return;
        case 3:
            param_1[20] = 0x16;
            param_1[40] = 10;
            param_1[50] = -GXObject_00463b70_gob_xScale[50];
            return;
        case 4:
            param_1[20] = 0x1b;
            param_1[40] = 10;
            param_1[50] = GXObject_00463b70_gob_xScale[50];
            return;
        case 5:
            param_1[20] = 0x16;
            param_1[40] = 10;
            param_1[50] = GXObject_00463b70_gob_xScale[50];
            return;
        case 6:
            param_1[20] = 0x1c;
            param_1[40] = 10;
            param_1[50] = GXObject_00463b70_gob_xScale[50];
            return;
        case 7:
            param_1[20] = 0x17;
            param_1[40] = 10;
            param_1[50] = GXObject_00463b70_gob_xScale[50];
        }
    }

    return;
}
