// Adapted from pc_decomp_backup/src/functions/FUN_00417F60.cpp
// Historical source SHA256: c09447cb926a07ef6431bbb571942dd6102b0d81f9f0113dd40e9fef970efb72
extern "C" {
extern "C" {
    extern int DAT_004A2990;
    extern int DAT_0049FB90;
    extern int DAT_0045B9A0;
    extern int __cdecl FUN_0040F170(int, int, int);
}

extern "C" int __cdecl GEX_Target(unsigned char* pos, void* obj)
{
    int idx1 = pos[0];
    int idx2 = pos[1];
    pos++;

    int edi = (int)obj;
    int eax = edi + 0x68;
    int v2 = *(int*)(eax + idx2 * 4);
    int v1 = *(int*)(eax + idx1 * 4);

    int ebx = *(int*)(edi + 0x7c);
    int ebp = *(int*)(edi + 0x78);

    int arg3 = v2 + ebx;
    int arg2 = v1 + ebp;

    int result = FUN_0040F170(DAT_004A2990, arg2, arg3);
    result <<= 5;

    int ecx = *(int*)((char*)&DAT_0045B9A0 + result);
    DAT_0049FB90 = ecx;

    return (int)pos + 1;
}
}
