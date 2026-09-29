extern "C" void __cdecl FUN_0042e780(void**);
extern "C" int DAT_0045b10c_XPOS;
extern "C" int DAT_0045b110_YPOS;

extern "C" void __cdecl FUN_0042e850(void** param_1)
{
    FUN_0042e780(param_1);
    param_1[0x1e] = (void*)((int)param_1[0x1e] + DAT_0045b10c_XPOS);
    param_1[0x1f] = (void*)((int)param_1[0x1f] + DAT_0045b110_YPOS);
    param_1[0x7e] = (void*)((int)param_1[0x7e] + DAT_0045b10c_XPOS);
    param_1[0x7f] = (void*)((int)param_1[0x7f] + DAT_0045b110_YPOS);
}
