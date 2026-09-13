// Adapted from pc_decomp_backup/src/functions/FUN_00412630.cpp
// Historical source SHA256: 7e4b79ace2fcdbe76e6831eb4a136b201e242dc6dcf4dbdecf57b5f05ecd727d
extern "C" {
extern "C" { extern int DAT_00458c78; }
extern "C" { extern unsigned char DAT_004a0294; }
extern "C" { extern int DAT_004586d8[]; }
extern "C" { extern int DAT_004586dc[]; }
extern "C" { extern unsigned int DAT_00458068[]; }

extern "C" int __cdecl FUN_00421f20(void**);
extern "C" void __cdecl FUN_00421cd0(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" void __cdecl FUN_004138B0(void**);

extern "C" void __cdecl GEX_Target(void** param1) {
    if (DAT_00458c78 != 0 || DAT_004a0294 != 0) {
        FUN_004138B0(param1);
        return;
    }
    int iVar1 = FUN_00421f20(param1);
    if (iVar1 == 0) return;
    FUN_00421cd0(param1);
    int v26 = (int)param1[0x26];
    v26 += 0x10000;
    param1[0x26] = (void*)v26;
    if ((int)param1[0x26] > 0x10000) {
        v26 -= 0x10000;
        int v15 = (int)param1[0x15];
        v15++;
        param1[0x26] = (void*)v26;
        int v27 = (int)param1[0x27];
        param1[0x15] = (void*)v15;
        if (v27 & 0x10) {
            int byteIdx = (v27 & 0xF) * 8;
            int ecx = *(int *)((char *)DAT_004586d8 + byteIdx);
            ecx = ecx + ecx * 4;
            ecx = ecx << 16;
            ecx = -ecx;
            int x = (int)param1[0x1E];
            x = x + ecx;
            int y = (int)param1[0x1F];
            param1[0x1E] = (void*)x;
            int eax = *(int *)((char *)DAT_004586dc + byteIdx);
            eax = eax + eax * 4;
            eax = eax << 16;
            eax = -eax;
            y = y + eax;
            param1[0x1F] = (void*)y;
        }
        if (v15 > 3) {
            int edx = (int)param1[0x1B];
            int eax = (int)param1[0x31];
            int ecx = edx;
            eax = eax & 0xFFE7FFFF;
            eax = (int)((unsigned int)eax) >> 19;
            ecx = ecx & 0x80000000;
            ecx = (int)((unsigned int)ecx >> 28);
            ecx = ecx << 2;
            edx = edx & 0x7FFFFFFF;
            ecx = ecx | eax;
            unsigned int tblVal = *(unsigned int *)((char *)DAT_00458068 + ecx);
            param1[0x1B] = (void*)edx;
            ecx = (int)(tblVal & 7);
            ecx = ecx << 21;
            param1[0x31] = (void*)ecx;
            if ((tblVal & 8) != 0) {
                edx = edx | 0x80000000;
                param1[0x1B] = (void*)edx;
            }
            FUN_00411160(param1);
            return;
        }
    }
}
}
