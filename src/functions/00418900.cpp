extern "C" int __cdecl GOB_GetHotSpot_00419c00(int* obj, int a, int b, int* px, int* py);
extern "C" int __cdecl GetGlueDist_0040f1d0(int level, int* obj);
extern "C" int M1_CurrentLevel_004a2990;

extern "C" int __cdecl SCRIPT_SnapToContour_00418900(int param_1, int* param_2)
{
    int local_8;
    int local_4;

    if (GOB_GetHotSpot_00419c00(param_2, 0, 0, &local_8, &local_4) != 0) {
        param_2[0x1e] += local_8;
        param_2[0x1f] += local_4;

        int glue = GetGlueDist_0040f1d0(M1_CurrentLevel_004a2990, param_2);
        if (glue > -0x200000 && glue < 0x200000) {
            param_2[0x1f] += glue;
        }

        param_2[0x1e] -= local_8;
        param_2[0x37] = 0x7fff0000;
        param_2[0x1f] -= local_4;
    }
    return param_1;
}
