// Adapted from pc_decomp_backup/src/functions/FUN_00413170.cpp
// Historical source SHA256: 48c486fd5beb02f4bc7ee2dc42438b8baf482a3a5da3a2b4e669572445908eeb
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_004135A0(void**);
extern "C" void __cdecl FUN_004130A0(void**);
extern "C" void __cdecl FUN_004136D0(void**);
extern "C" { extern unsigned int DAT_00458758[]; }
extern "C" void __cdecl GEX_Target(void** param1) {
    unsigned int uVar2 = DAT_00458758[0]; 
    unsigned int index = (((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c) << 2;
    unsigned int uVar1 = *((unsigned int*)((char*)DAT_00458758 + index + 4));
    FUN_00420BC0(param1);
    unsigned int uVar3 = (uVar1 & 7) + 1;
    unsigned int uVar4 = ((uVar1 - 2) & 7) + 1;
    if (uVar1 == uVar2 || uVar2 == uVar3 || uVar2 == uVar4) { FUN_004135A0(param1); return; }
    unsigned int uVar5 = 0;
    if (uVar2 != 0) uVar5 = ((uVar2 + 3) & 7) + 1;
    if (uVar1 != uVar5 && uVar5 != uVar3 && uVar5 != uVar4) {
        param1[0x1c] = (void*)0x55;
        param1[0x26] = 0; param1[0x27] = 0; param1[0x29] = 0; param1[0x15] = 0; param1[0x14] = (void*)0x55;
        FUN_004130A0(param1); return;
    }
    FUN_004136D0(param1);
}
}
