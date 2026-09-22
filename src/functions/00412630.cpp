extern "C" {
extern int DAT_00458c78;
extern unsigned char DAT_004a0294;
extern int DAT_004586d8[];
extern int DAT_004586dc[];
extern unsigned int DAT_00458068[];
int __cdecl FUN_00421f20(void**);
void __cdecl FUN_00421cd0(void**);
void __cdecl FUN_00411160(void**);
void __cdecl FUN_004138B0(void**);
void __cdecl GEX_Target(void** param1) {
    if (DAT_00458c78 == 0 && DAT_004a0294 == 0) {
        int iVar1 = FUN_00421f20(param1);
        if (iVar1 == 0) return;
        FUN_00421cd0(param1);
        int v26 = (int)param1[0x26];
        v26 += 0x10000;
        param1[0x26] = (void*)v26;
        if (v26 > 0x10000) {
            v26 -= 0x10000;
            param1[0x26] = (void*)v26;
            int v15 = (int)param1[0x15];
            v15++;
            int v27 = (int)param1[0x27];
            param1[0x15] = (void*)v15;
            if (v27 & 0x10) {
                int byteIdx = (v27 & 0xF) * 8;
                int ecx = *(int *)((char *)DAT_004586d8 + byteIdx);
                ecx = ecx + ecx * 4;
                ecx = ecx << 16;
                ecx = -ecx;
                char* x = (char*)param1[0x1E];
                x = x + ecx;
                char* y = (char*)param1[0x1F];
                param1[0x1E] = x;
                int eax = *(int *)((char *)DAT_004586dc + byteIdx);
                eax = eax + eax * 4;
                eax = eax << 16;
                eax = -eax;
                y = y + eax;
                param1[0x1F] = y;
            }
            if (v15 > 3) {
                int edx = (int)param1[0x1B];
                void* eax = param1[0x31];
                void* ecx = (void*)edx;
                eax = (void*)((unsigned int)eax & 0xFFE7FFFF);
                eax = (void*)((int)eax >> 19);
                ecx = (void*)((unsigned int)ecx & 0x80000000U);
                ecx = (void*)((unsigned int)ecx >> 28);
                ecx = (void*)((int)ecx << 2);
                ecx = (void*)((int)eax | (int)ecx);
                edx = edx & 0x7FFFFFFF;
                unsigned int tblVal = *(unsigned int *)((char *)DAT_00458068 + (int)ecx);
                param1[0x1B] = (void*)edx;
                param1[0x31] = (void*)((tblVal & 7) << 21);
                if ((tblVal & 8) != 0) {
                    edx = edx | 0x80000000;
                    param1[0x1B] = (void*)edx;
                }
                FUN_00411160(param1);
                return;
            }
        }
    } else {
        FUN_004138B0(param1);
    }
}
}
