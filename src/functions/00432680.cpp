extern "C" {
extern int FUN_004A2AD4;
int __cdecl FUN_0040FCE0(void **);
void __cdecl FUN_0040F260(void **);
void __cdecl FUN_0040F2A0(void **);
unsigned int __cdecl FUN_00431900_Movement_unk(void **);
void ** __cdecl FUN_004195D0(int, int, int, int);
void __cdecl FUN_00419BE0(void **, void **);
void __cdecl FUN_00419520(void **);

void __cdecl ob94DoIt_00432680(void **param_1)
{
    void *counter;
    void **obj;
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x38] = (void *)(((((unsigned int)param_1[0x38] * 2u) ^ (unsigned int)param_1[0x38]) & 0x200u) ^ (unsigned int)param_1[0x38]);
    param_1[0x38] = (void *)((unsigned int)param_1[0x38] & 0xfffffeffu);
    if (FUN_0040FCE0(param_1) == 0) {
        FUN_0040F260(param_1);
        FUN_0040F2A0(param_1);
        if (FUN_00431900_Movement_unk(param_1) != 0) {
            obj = FUN_004195D0(0x5c, (int)param_1[0x1e], (int)param_1[0x1f], FUN_004A2AD4);
            if (obj != 0) {
                obj[0x14] = (void *)0x1e;
                obj[0x2e] = (void *)6;
                obj[0x28] = (void *)0x320000;
                obj[0x1c] = (void *)0x41;
                obj[0x32] = (void *)0x8000;
                obj[0x33] = (void *)0x8000;
                obj[0x31] = (void *)0x10000;
                obj[0x2f] = (void *)0x1f801f00;
                FUN_00419BE0(obj, param_1);
            }
            FUN_00419520(param_1);
        }
        counter = (void *)((int)param_1[0x26] + 1);
        param_1[0x26] = counter;
        if ((int)counter >= 2) {
            param_1[0x26] = 0;
            param_1[0x15] = (void *)((int)param_1[0x15] + 1);
        }
    }
    if (param_1[0x45] == (void *)0xffffffff) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = (void *)0xffffffff;
}
}
