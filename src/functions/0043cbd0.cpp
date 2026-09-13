// Adapted from pc_decomp_backup/src/functions/FUN_0043CBD0.cpp
// Historical source SHA256: b693ca873344c756cd7d12bbdc39cdfe5e52fe73f6918b8b9f4cbbd3ef03c685
extern "C" {
extern "C" void __cdecl FUN_00417B70();
extern "C" void __cdecl FUN_0041A340(void*, int);
extern "C" { extern int DAT_004a023c; }
extern "C" { extern void* FUN_00464E14; }
extern "C" void __cdecl GEX_Target(void** param1, int* param2) {
    if (*param2 == 0) return;
    if ((int)param1[0x2e] > 0) return;
    if ((int)param1[0x27] < 0x11) return;
    if ((int)param1[0x27] > 0x6f) return;
    unsigned short uVar3 = (unsigned short)((int*)param1[0x5c])[1];
    unsigned short uVar2 = (unsigned short)((int*)param1[0x5d])[1];
    unsigned int uVar1 = ((unsigned int)param1[0x5e] >> 8) & 0xf;
    if (uVar1 == 2) {
        if (DAT_004a023c == 0) {
            if (uVar2 == uVar3 || uVar3 == 1) { FUN_00417B70(); return; }
            goto check;
        }
        goto check2;
    } else {
check:
        if (DAT_004a023c != 0) goto check2;
    }
    if (uVar3 != 2 && uVar2 != 1) return;
check2:
    if (uVar2 != 3) { FUN_0041A340(FUN_00464E14, 0x115); param1[0x15] = 0; }
}
}
