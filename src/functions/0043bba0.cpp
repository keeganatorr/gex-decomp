extern "C" {

extern int* DAT_00464DE8;
extern int* DAT_00464DF8;
extern int* DAT_00464E00;
extern int* PTR_00464E08;
extern int* PTR_00464E14;

extern int* FUN_004195D0(int, int, int, int);
extern void FUN_00419BE0(int*, int*);
extern void FUN_00419BC0(int*, int*);
extern void FUN_00419B80(int*, int);

void __cdecl GEX_Target(int* param_1)
{
    int i;
    int** slot;
    int j;
    int* obj;

    if (param_1[0x26] != 0x80)
        return;

    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    i = 0;
    j = 0;
    slot = &DAT_00464DE8;

    do {
        obj = FUN_004195D0(0x105, param_1[0x1e], param_1[0x1f], param_1[3]);
        if (obj != 0) {
            obj[0x26] = i;
            *slot = obj;
            obj[0x27] = j;
            obj[0x28] = j;
            obj[0x14] = 0;
            obj[0x15] = 0;
            obj[0x17] = 0;
            if (slot >= &DAT_00464DF8) {
                if (obj != 0 && PTR_00464E14 != 0)
                    FUN_00419BC0(obj, PTR_00464E14);
            } else {
                if (obj != 0 && PTR_00464E08 != 0)
                    FUN_00419BE0(obj, PTR_00464E08);
            }
        }
        j += 0x2b;
        slot++;
        i++;
    } while (slot < &DAT_00464E00);

    FUN_00419B80(param_1, 0);
}

}
