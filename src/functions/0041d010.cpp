// Adapted from pc_decomp_backup/src/functions/FUN_0041D010.cpp
// Historical source SHA256: 796729bb21cc477f1bc6302192c6281ea066dc7e002fb4661803b79a12260a7a
extern "C" {
extern "C" void __cdecl FUN_0041CC70(int*, int, int, int, int, unsigned int, int, int);
extern "C" void __cdecl GEX_Target(int param1, int* param2, int param3, int param4, unsigned int param5, int param6) {
    int iVar1;
    if ((*(unsigned int*)(param1 + 0x6c) & 0x80000000) == 0) {
        *(int*)(param6 + 4) = param2[0];
        *(int*)(param6 + 0xc) = param2[2];
        *(int*)(param6 + 0x14) = param2[2];
        iVar1 = param2[0];
    } else {
        *(int*)(param6 + 4) = -param2[2];
        *(int*)(param6 + 0xc) = -param2[0];
        *(int*)(param6 + 0x14) = -param2[0];
        iVar1 = -param2[2];
    }
    *(int*)(param6 + 0x1c) = iVar1;
    if ((*(unsigned int*)(param1 + 0x6c) & 0x40000000) == 0) {
        *(int*)(param6 + 8) = param2[1];
        *(int*)(param6 + 0x10) = param2[1];
        *(int*)(param6 + 0x18) = param2[3];
        *(int*)(param6 + 0x20) = param2[3];
    } else {
        *(int*)(param6 + 8) = -param2[3];
        *(int*)(param6 + 0x10) = -param2[3];
        *(int*)(param6 + 0x18) = -param2[1];
        *(int*)(param6 + 0x20) = -param2[1];
    }
    FUN_0041CC70((int*)param6, *(int*)(param1 + 0x78), *(int*)(param1 + 0x7c), param3, param4, param5, *(int*)(param1 + 200), *(int*)(param1 + 0xcc));
}
}
