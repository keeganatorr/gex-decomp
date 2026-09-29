// Adapted from pc_decomp_backup/src/functions/FUN_00437330.cpp
extern "C" {
extern int DAT_004642D0;
extern int DAT_004642D4;
extern void* DAT_004A27FC;
extern int DAT_004A2AC8;
extern void __cdecl FUN_0041E7C0(void**);
extern void __cdecl FUN_0041FA80(int);
extern void __cdecl FUN_00437310(void**);

void __cdecl RezOutAll_00437330(void** param_1)
{
    if (param_1[0x59] != (void*)0x0) {
        RezOutAll_00437330((void**)param_1[0x59]);
    }
    if (param_1[0x58] != (void*)0x0) {
        RezOutAll_00437330((void**)param_1[0x58]);
    }
    if (((unsigned int)param_1[0x38] & 0x10) == 0) {
        if (DAT_004A27FC != (void*)0x0) {
            if (DAT_004A2AC8 - DAT_004642D4 > 0xf) {
                DAT_004642D0 = 0;
            }
            DAT_004642D0 = DAT_004642D0 + 1;
            if (DAT_004642D0 >= 3) {
                FUN_0041FA80(0x15);
            }
        }
        param_1[0x17] = (void*)0x0;
        param_1[0x19] = (void*)0x0;
        FUN_0041E7C0(param_1);
    }
    FUN_00437310(param_1);
}
}
