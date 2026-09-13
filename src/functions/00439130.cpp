// Adapted from pc_decomp_backup/src/functions/FUN_00439130.cpp
// Historical source SHA256: fa50985cfc2f92caa4947fabc46f677110496b8975970a8362a3f313bb12c024
extern "C" {
extern "C" { extern short DAT_0045F440[]; }

extern "C" int __cdecl GEX_Target(int param_1, int param_2)
{
    int idx = ((param_2 >> 16) * 17) + (param_1 >> 16);
    int val = DAT_0045F440[idx] + 0x40;
    if (val > 0xff) val = DAT_0045F440[idx] - 0xc0;
    return val << 16;
}
}
