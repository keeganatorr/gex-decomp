// Adapted from pc_decomp_backup/src/functions/FUN_0042B760.cpp
// Historical source SHA256: b5d5472b97e5153552c5e8f2e953600496d5b76eb41a8176bf4318f162c258e4
extern "C" {
extern void* DAT_004A2AD4;
extern "C" { extern int DAT_0045AED0; }
extern "C" { extern int DAT_00463B44; }
extern "C" void __cdecl FUN_00441150(void*);

extern "C" void __cdecl GEX_Target(int param_1, int param_2)
{
    char local_204[0x204];
    int angle;

    *(int*)(local_204 + 0x78) = param_1;
    *(int*)(local_204 + 0x7c) = param_2;
    *(int*)(local_204 + 0x54) = 0;
    *(int*)(local_204 + 0x0c) = (int)DAT_004A2AD4;
    *(int*)(local_204 + 0x6c) = 0;
    *(int*)(local_204 + 0xc8) = DAT_0045AED0;
    *(int*)(local_204 + 0xcc) = DAT_0045AED0;
    *(int*)(local_204 + 0x50) = 0x1e;
    *(int*)(local_204 + 0xbc) = 0;
    *(int*)(local_204 + 0xc0) = 0;
    angle = ((DAT_00463B44 * 0x57) & 0xff) << 0x10;
    *(int*)(local_204 + 0xc8) = angle;
    FUN_00441150((void*)local_204);
}
}
