// Adapted from pc_decomp_backup/src/functions/FUN_0041A6F0.cpp
// Historical source SHA256: c6f83a8e89e2d01c9379dea7975d7374f4f139d4225f022822d4355cd788faa8
extern "C" {
extern "C" { extern int DAT_00456ADC; }
extern "C" { extern int DAT_0046359C; }
extern "C" { extern int DAT_004A27D4; }
extern "C" { extern int DAT_004A280C; }
extern "C" { extern int DAT_004A2810; }
extern "C" { extern int DAT_004A282C; }
extern "C" { extern int DAT_004A2830; }
extern "C" { extern int DAT_004A2990; }
extern "C" { extern int DAT_004A2A40; }
extern "C" { extern int DAT_004A2A98; }
extern "C" { extern int DAT_00456AE0; }
extern "C" { extern unsigned char DAT_004A2710[]; }

extern "C" int __cdecl FUN_0040F1D0(int, void**);
extern "C" void __cdecl FUN_00419840(void**);
extern "C" void __cdecl FUN_0041F8C0(unsigned int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_004A27D4 != 0)
    {
        DAT_0046359C = 0;
        if ((int)param_1[0x2d] == DAT_00456ADC)
        {
            DAT_004A280C = (int)param_1[0x1e];
            DAT_004A2810 = (int)param_1[0x1f];
            DAT_004A282C = (int)param_1[0x1e];
            param_1[0x1f] = (void*)((int)param_1[0x1f] + 0x200000);
            DAT_00456AE0 = 1;
            DAT_004A2830 = (int)param_1[0x1f];

            {
                int glue_result = FUN_0040F1D0(DAT_004A2990, param_1);
                int orig_glue = glue_result;
                int abs_glue = glue_result < 0 ? -glue_result : glue_result;
                if (abs_glue < 0x5A0000)
                {
                    DAT_004A2830 += orig_glue;
                }
            }
        }
        FUN_00419840(param_1);
        return;
    }

    {
        int level_id = DAT_004A2A98;
        unsigned char door_byte = DAT_004A2710[level_id];
        if ((int)door_byte == (int)param_1[0x2d])
        {
            int zero_check = 0;
            if ((int)DAT_004A282C >= zero_check && DAT_00456AE0 == 1 && DAT_004A2A40 != zero_check)
            {
                param_1[0x27] = (void*)0;
                param_1[0x28] = (void*)0;
                param_1[0x15] = (void*)0;
                param_1[0x14] = (void*)0;
                param_1[0x26] = (void*)1;
                return;
            }

            param_1[0x26] = (void*)3;
            param_1[0x15] = (void*)0;
            param_1[0x14] = (void*)2;
            return;
        }

        FUN_0041F8C0(0x4A);
    }
}
}
