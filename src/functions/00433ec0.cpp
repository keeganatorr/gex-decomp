extern "C" {
extern int DAT_0045b5ec;
extern int DAT_0045b5e8;
extern int FUN_00464210;
extern unsigned int FUN_00464214[];
void __cdecl FUN_00441150(int *);

void __cdecl GEX_Target(int *param_1)
{
    int saved_30, saved_1e, saved_1f, saved_2f;
    unsigned short local_array[31];
    int index;
    unsigned int uVar3;
    unsigned int *dest;
    int count;

    local_array[0] = 0x801f;
    local_array[1] = 0x801d;
    local_array[2] = 0x801b;
    local_array[3] = 0x8019;
    local_array[4] = 0x8017;
    local_array[5] = 0x8015;
    local_array[6] = 0x8013;
    local_array[7] = 0x8011;
    local_array[8] = 0x800f;
    local_array[9] = 0x800d;
    local_array[10] = 0x800b;
    local_array[11] = 0x8009;
    local_array[12] = 0x8007;
    local_array[13] = 0x8005;
    local_array[14] = 0x8003;
    local_array[15] = 0x8001;
    local_array[16] = 0x8003;
    local_array[17] = 0x8005;
    local_array[18] = 0x8007;
    local_array[19] = 0x8009;
    local_array[20] = 0x800b;
    local_array[21] = 0x800d;
    local_array[22] = 0x800f;
    local_array[23] = 0x8011;
    local_array[24] = 0x8013;
    local_array[25] = 0x8015;
    local_array[26] = 0x8017;
    local_array[27] = 0x8019;
    local_array[28] = 0x801b;
    local_array[29] = 0x801d;
    local_array[30] = 0xffff;

    saved_1e = param_1[0x1e];
    saved_30 = param_1[0x30];
    saved_1f = param_1[0x1f];
    saved_2f = param_1[0x2f];
    FUN_00441150(param_1);

    index = *(volatile int *)&DAT_0045b5ec;
    uVar3 = local_array[index];
    if (uVar3 == 0xffff) {
        DAT_0045b5ec = 0;
        uVar3 = 0x801f;
    }
    FUN_00464210 = 0xffffff00;
    uVar3 |= uVar3 << 16;
    dest = FUN_00464214;
    for (count = 16; count != 0; --count) {
        *dest++ = uVar3;
    }
    *(unsigned short *)FUN_00464214 = 0;
    param_1[0x30] = (int)FUN_00464214;
    DAT_0045b5e8 = DAT_0045b5e8 - 1;
    if (DAT_0045b5e8 <= 0) {
        DAT_0045b5e8 = 3;
        DAT_0045b5ec = DAT_0045b5ec + 1;
    }
    param_1[0x2f] = 0x1f801f80;
    FUN_00441150(param_1);
    param_1[0x1e] = saved_1e;
    param_1[0x1f] = saved_1f;
    param_1[0x30] = saved_30;
    param_1[0x2f] = saved_2f;
}
}
