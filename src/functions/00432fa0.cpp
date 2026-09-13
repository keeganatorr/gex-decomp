// Adapted from pc_decomp_backup/src/functions/FUN_00432FA0.cpp
// Historical source SHA256: c4e1b6849ab0b2773de76b14e744b8fee262145cf5d3d7ceedd9bed5d1bd239b
extern "C" {
extern "C" { extern int FUN_004A27FC; }
extern "C" int __cdecl FUN_00432F40(void**);
extern "C" int __cdecl FUN_0041CB80(void**, int**);
extern "C" unsigned int __cdecl FUN_00420C10(unsigned int, unsigned int);
extern "C" void __cdecl FUN_004355D0(void**, unsigned int*);

extern "C" void __cdecl GEX_Target(void** param_1, unsigned int* param_2)
{
    if (*param_2 == 0) return;
    
    if (((unsigned int)param_1[0x5d] & 0xffff) == 1) {
        FUN_00432F40(param_1);
        return;
    }
    
    if ((int)FUN_004A27FC == (int)param_1[0x5e]) {
        int* local_28[6];
        int iVar1 = FUN_0041CB80((void**)param_1[0x5e], local_28);
        if (iVar1 != 0) {
            unsigned int local_10 = 0, local_c = 0, local_8 = 0;
            
            unsigned int uVar2 = FUN_00420C10(local_10, local_8);
            if ((int)uVar2 < 0) {
                FUN_00432F40(param_1);
                return;
            }
            
            uVar2 = FUN_00420C10(local_c, local_8);
            if ((int)uVar2 < 0) {
                FUN_00432F40(param_1);
                return;
            }
            
            uVar2 = FUN_00420C10(((int)(local_c - local_10) >> 1) + local_10, local_8);
            if ((int)uVar2 < 0) {
                FUN_00432F40(param_1);
                return;
            }
        }
    }
    
    FUN_004355D0(param_1, param_2);
}
}
