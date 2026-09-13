// Adapted from pc_decomp_backup/src/functions/FUN_0042E850.cpp
// Historical source SHA256: ed06b1bd3fd59bc4ce5a8786bebd012445b38fdcc48b61e213b3a45a0bd03088
extern "C" {
extern "C" void __cdecl FUN_0042e780(void**);
extern "C" { extern int DAT_0045b10c_XPOS; }
extern "C" { extern int DAT_0045b110_YPOS; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_0042e780(param_1);
    param_1[0x1e] = (void*)((int)param_1[0x1e] + DAT_0045b10c_XPOS - 0x1c);
    param_1[0x1f] = (void*)((int)param_1[0x1f] + DAT_0045b110_YPOS - 0x1c);
    param_1[0x7e] = (void*)((int)param_1[0x7e] + DAT_0045b10c_XPOS - 0x1c);
    param_1[0x7f] = (void*)((int)param_1[0x7f] + DAT_0045b110_YPOS - 0x1c);
}
}
