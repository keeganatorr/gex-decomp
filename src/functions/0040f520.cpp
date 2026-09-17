extern "C" void __cdecl GEX_Target(int* param_1)
{
    unsigned int bVar1, bVar2, bVar3, bVar4;
    unsigned char bVar5;
    unsigned char* pbVar5;

    if (param_1[3] > 1)
    {
        param_1[3]--;
        return;
    }

    for (;;)
    {
        bVar5 = *(unsigned char*)param_1[2];
        pbVar5 = (unsigned char*)param_1[2] + 1;
        param_1[2] = (int)pbVar5;

        if ((bVar5 & 0x80) != 0)
        {
            param_1[2] = ((int (*)(int))((int**)param_1[1])[bVar5 & 0x7f])(param_1[2]);
            continue;
        }

        switch (bVar5)
        {
        case 1:
            pbVar5 = (unsigned char*)param_1[2];
            param_1[3] = *pbVar5++;
            param_1[2] = (int)pbVar5;
            bVar1 = *pbVar5++;
            param_1[2] = (int)pbVar5;
            bVar2 = *pbVar5++;
            param_1[2] = (int)pbVar5;
            bVar3 = *pbVar5++;
            param_1[2] = (int)pbVar5;
            bVar4 = *pbVar5++;
            param_1[2] = (int)pbVar5;
            param_1[4] = ((bVar1 << 16) | bVar3) << 8 | (bVar2 << 16) | bVar4;
            return;

        case 2:
            pbVar5 = (unsigned char*)param_1[2];
            param_1[3] = *pbVar5++;
            param_1[2] = (int)pbVar5;
            param_1[5] = *pbVar5++;
            param_1[2] = (int)pbVar5;
            return;

        case 3:
            param_1[0] = 0;
            return;
        }
    }
}
