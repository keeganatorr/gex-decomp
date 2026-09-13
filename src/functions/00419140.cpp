// Adapted from pc_decomp_backup/src/functions/FUN_00419140.cpp
// Historical source SHA256: 0e490f6501ab6a34af8add86367c18c0e93f29518cf856dae07fe4d14d12b89d
extern "C" {
extern "C" { extern int DAT_0049FB90; }
extern "C" void __cdecl FUN_0040BC70(int, int, unsigned int, int*, int*, int, char*, void**);

extern "C" void* __cdecl GEX_Target(unsigned char* param_1, void** param_2)
{
    char local_4;
    char local_3;
    char local_2;
    char local_1;
    int work = DAT_0049FB90;
    unsigned char* p = param_1 + 1;
    unsigned int ch = (unsigned int)*param_1;
    void** p2 = param_2;

    local_4 = (char)(work / 100);
    if (local_4 == 0) {
        local_4 = ' ';
    } else {
        local_4 = local_4 + '0';
    }
    local_3 = (char)((work / 10) % 10);
    if (local_4 == ' ' && local_3 == 0) {
        local_3 = ' ';
    } else {
        local_3 = local_3 + '0';
    }
    local_2 = (char)(work % 10) + '0';
    local_1 = 0;
    FUN_0040BC70((int)p2[0x1e], (int)p2[0x1f], ch, (int*)0x0, (int*)0x0, -1, &local_4, p2);
    return p;
}
}
