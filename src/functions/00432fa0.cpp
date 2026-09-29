extern "C" {
extern void *FUN_004A27FC;

int __cdecl FUN_00432F40(void *param_1);
int __cdecl FUN_0041CB80(void *param_1, int *param_2);
unsigned int __cdecl FUN_00420C10(unsigned int param_1, unsigned int param_2);
void __cdecl FUN_004355D0(void *param_1, unsigned int *param_2);

void __cdecl FUN_00432fa0_Event_unk(void **param_1, unsigned int *param_2)
{
    int local_28[10];
    int iVar1;

    if (*param_2 == 0) {
        return;
    }

    if (((*(unsigned int *)param_1[0x5d]) & 0xffff) == 1) {
        FUN_00432F40(param_1);
        return;
    }

    if (FUN_004A27FC == param_1[0x5e]) {
        iVar1 = FUN_0041CB80(param_1[0x5e], local_28);
        if (iVar1 != 0) {
            if (((FUN_00420C10(local_28[6], local_28[8]) & 0x80000000) != 0) ||
                ((FUN_00420C10(local_28[7], local_28[8]) & 0x80000000) != 0) ||
                ((FUN_00420C10(((local_28[7] - local_28[6]) >> 1) + local_28[6], local_28[8]) & 0x80000000) != 0)) {
                FUN_00432F40(param_1);
                return;
            }
        }
    }

    FUN_004355D0(param_1, param_2);
}
}
