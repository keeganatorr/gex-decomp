extern "C" {
extern int DAT_004A2AD4;
extern int DAT_0045AED0;
extern int DAT_00463B44;
extern void __cdecl FUN_00441150(void*);

struct GXLocal {
    int pad_a[3];
    int f_00c;
    int pad_b[16];
    int f_050;
    int f_054;
    int pad_c[5];
    int f_06c;
    int pad_d[2];
    int f_078;
    int f_07c;
    int pad_e[15];
    int f_0bc;
    int f_0c0;
    int f_0c4;
    int f_0c8;
    int f_0cc;
    int pad_f[77];
};

void __cdecl GEX_Target(int param_1, int param_2)
{
    GXLocal local;

    local.f_078 = param_1;
    local.f_07c = param_2;
    local.f_054 = 0;
    local.f_00c = DAT_004A2AD4;
    local.f_06c = 0;
    local.f_0c8 = DAT_0045AED0;
    local.f_0cc = DAT_0045AED0;
    local.f_050 = 0x1e;
    local.f_0c4 = ((DAT_00463B44 * 0x57) << 0x10) & 0xff0000;
    local.f_0bc = 0;
    local.f_0c0 = 0;
    FUN_00441150(&local);
}
}
