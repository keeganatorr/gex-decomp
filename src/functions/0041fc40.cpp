// Adapted from pc_decomp_backup/src/functions/FUN_0041FC40.cpp
// Historical source SHA256: a85d12226a88c5916b153305f4866ae2345cab5e65829be42a2ec1c899f904ed
extern "C" {
extern "C" unsigned int __cdecl FUN_00404BA0(void);

extern "C" int __cdecl FUN_0040F4C0(int);
extern "C" int __cdecl FUN_0040F700(int, int*, int);
extern "C" int __cdecl FUN_0040F5E0(int, int);
extern "C" { extern int DAT_004A02C8; }
extern "C" { extern int DAT_004A02A0; }
extern "C" { extern unsigned char DAT_004A0285; }
extern "C" { extern int DAT_004A02CC; }
extern "C" { extern unsigned char DAT_00457C38[]; }
extern "C" { extern unsigned char DAT_004A0280[]; }
extern "C" { extern unsigned char DAT_0045A178[]; }
extern "C" { extern unsigned char DAT_004A028F[]; }

extern "C" void __cdecl GEX_Target()
{
    int keyInput;

    keyInput = FUN_0040F4C0(0);
    keyInput |= FUN_00404BA0();
    DAT_004A02C8 = keyInput;
    FUN_0040F700(keyInput, (int*)DAT_0045A178, (int)DAT_004A0280);
    DAT_004A02A0 = DAT_00457C38[keyInput & 0xf];
    keyInput = FUN_0040F5E0(0, keyInput);
    FUN_0040F700(keyInput, (int*)DAT_0045A178, (int)DAT_004A028F);
    DAT_004A02CC = DAT_004A0285;
}
}
