// Reconstruction of FUN_00422500_pStateUnk_Lash_Inner (GEX_Target)
// Contract: /O2 /G5 /Oy /GR-, cdecl, one 4-byte pointer argument.
extern "C" {
extern void* DAT_004A2838;
extern int DAT_004A0234;
extern int DAT_0045AA30;

void __cdecl GEX_Target(int* param_1)
{
    if (DAT_004A2838 != (void*)0x0) {
        param_1[0x20] = (int)(((unsigned int)param_1[0x20] & 0xffffff00u) << 3);
        param_1[0x23] = (int)(((unsigned int)param_1[0x23] & 0xffffff00u) << 3);
        return;
    }
    param_1[0x20] = ((int*)&DAT_0045AA30)[DAT_004A0234] * (param_1[0x20] >> 8);
    param_1[0x23] = ((int*)&DAT_0045AA30)[DAT_004A0234] * (param_1[0x23] >> 8);
}
}
