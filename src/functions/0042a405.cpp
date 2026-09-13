// Adapted from pc_decomp_backup/src/functions/FUN_0042A405.cpp
// Historical source SHA256: 90879d7d8f8290f1550c196cdd200a700a2fbd9c55cb1e24611efc22e90b966b
extern "C" {
extern "C" { extern int DAT_0048A024; }
extern "C" void __cdecl FUN_0040D5F0(int, int, int, int);
extern "C" void __cdecl FUN_0042A630(void**);

extern "C" void __cdecl GEX_Target(void** context)
{
    FUN_0042A630(context);
    
    if (context == 0) return;
    
    if ((int)context[0x21] == 0x19) {
        FUN_0040D5F0((int)context[0x1e], (int)context[0x1f] - 0x180000, DAT_0048A024, 0);
    }
    
    context[0x21] = (void*)((int)context[0x21] - 1);
    if ((int)context[0x21] > 0x14) return;
    
    context[0x22] = (void*)((int)context[0x21] + (int)context[0x20]);
    
}
}
