// Adapted from pc_decomp_backup/src/functions/FUN_0041750B.cpp
// Historical source SHA256: e5b0c498f1ae82f34c17bff806699fd638abc75efe6469f9f7914bd9b4892693
extern "C" {
extern "C" void __cdecl FUN_0041A250(int obj, int a, int b, int c);
extern "C" void __cdecl FUN_00416320(int obj);
extern "C" void __cdecl FUN_0042E850(int obj);
extern "C" unsigned int __cdecl FUN_00428C60();
extern "C" int __cdecl FUN_00428C80(int a);
extern "C" int __cdecl FUN_00419C00(int obj, int a, int b, int* c, int* d);
extern "C" int __cdecl FUN_004195D0(int a, int b, int c, int d);
extern "C" void __cdecl FUN_00419BE0(int a, int b);
extern "C" void __cdecl FUN_0041A340(int obj, int soundId);
extern "C" void __cdecl FUN_00420D30();
extern "C" void __cdecl FUN_00420D40();

extern int DAT_00455C4C;
extern int DAT_00457210;
extern int DAT_00458B78;
extern int DAT_00458B7C;
extern int DAT_00458B80;
extern int DAT_00458B84;
extern int DAT_00458B88;
extern int DAT_00458B8C;
extern int DAT_00462E40;
extern int DAT_00463590;
extern int DAT_004A0218;
extern int DAT_004A0238;
extern int DAT_004A23F0;
extern int DAT_004A2840;
extern int DAT_004A2854;
extern int DAT_004A2878;

extern "C" void __cdecl GEX_Target(int param1, int param2, int player)
{
    int savedX, savedY, savedXScale, savedYScale;
    int i, a, b, ppObj, result;
    unsigned int randVal;
    int val1, val2, flags;
    int local_flags;
    
    if (param1 >= 0) {
        FUN_0041A250(player, param1, 0x80, 0x60);
        DAT_004A0218 = -1;
    }
    
    local_flags = *(int*)((char*)&DAT_00457210 + *(int*)(player + 0x70) * 4);
    if ((local_flags & 4) != 0) {
        return;
    }
    
    if ((*(int*)(player + 0xe0) & 0x40) == 0) {
        FUN_00416320(player);
    } else {
        savedX = *(int*)(player + 0x78);
        savedY = *(int*)(player + 0x7c);
        savedXScale = *(int*)(player + 0xc8);
        savedYScale = *(int*)(player + 0xcc);
        FUN_0042E850(player);
        FUN_00416320(player);
        *(int*)(player + 0x78) = savedX;
        *(int*)(player + 0x7c) = savedY;
        *(int*)(player + 0xc8) = savedXScale;
        *(int*)(player + 0xcc) = savedYScale;
    }
    
    if (DAT_00455C4C == 1) {
        if (DAT_004A2878 != 0) {
            DAT_004A2878 = DAT_004A2878 - 1;
            if (DAT_004A2878 == 0) {
                DAT_004A2840 = 0;
                DAT_00455C4C = 1 - DAT_004A2840;
            }
            goto check_collision;
        }
    } else {
check_collision:
        if (DAT_004A2878 == 0) goto check_health;
    }
    
    if (DAT_004A2878 != 0) {
        if (DAT_004A0238 == 0) return;
    }
    
    if (DAT_004A2878 != 0) return;
    
check_health:
    if (DAT_004A23F0 == 0) return;
    if ((*(int*)(player + 0xe0) & 0x100) == 0) return;
    
    if (*(int*)(player + 0x54) != DAT_00463590 ||
        *(int*)(player + 0x50) != DAT_00462E40) {
        flags = *(int*)((char*)&DAT_00457210 + *(int*)(player + 0x70) * 4);
        if ((flags & 0x200) == 0 || (FUN_00428C60() & 3) == 0) {
            DAT_00463590 = *(int*)(player + 0x54);
            DAT_00462E40 = *(int*)(player + 0x50);
            
            for (i = 0; i < 2; i++) {
                a = 0;
                b = 0;
                result = FUN_00419C00(player, 2, i, &a, &b);
                if (result == 0) return;
                
                if (DAT_004A2854 < 10) {
                    ppObj = FUN_004195D0(0x5c,
                        *(int*)(player + 0x78) + a,
                        *(int*)(player + 0x7c) + b,
                        DAT_004A23F0);
                    
                    if (ppObj != 0) {
                        *(int*)(ppObj + 0x58) = (int)&FUN_00420D30;
                        *(int*)(ppObj + 0x60) = (int)&FUN_00420D40;
                        *(int*)(ppObj + 0x54) = DAT_00458B88;
                        *(int*)(ppObj + 0xbc) = DAT_00458B8C;
                        *(int*)(ppObj + 0x6c) = *(int*)(ppObj + 0x6c) | 0x800000;
                        
                        if ((flags & 0x100) != 0) {
                            val1 = DAT_00458B84;
                            val2 = DAT_00458B80;
                        } else {
                            val1 = DAT_00458B7C;
                            val2 = DAT_00458B78;
                        }
                        
                        randVal = FUN_00428C80(val1 + val2);
                        randVal = randVal << 16;
                        
                        if ((flags & 0x400) == 0) {
                            if (*(int*)(ppObj + 0x78) <= *(int*)(player + 0x78)) {
                                randVal = (unsigned int)(-(int)randVal);
                            }
                            *(int*)(ppObj + 0x80) = (int)randVal;
                        } else {
                            *(int*)(ppObj + 0x8c) = (int)(-(int)randVal);
                        }
                        
                        FUN_0041A340(player, 0xdc);
                        FUN_00419BE0(ppObj, player);
                        DAT_004A2854 = DAT_004A2854 + 1;
                    }
                }
            }
        }
    }
}
}
