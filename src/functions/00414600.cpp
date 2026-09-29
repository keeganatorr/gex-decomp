extern "C" {
extern int DAT_004a0220;
extern unsigned char DAT_004a0282;
extern unsigned char DAT_004a0293;
extern unsigned char DAT_004a0294;
extern unsigned char DAT_004a0295;
extern int FUN_004A2990;
void __cdecl FUN_00424090(void**);
void __cdecl FUN_00427760(void**);
void __cdecl FUN_00424B80(void**);
void __cdecl FUN_00414890(void**);
int __cdecl FUN_00421560_DrawCharacter(int, void**);
void __cdecl FUN_004250B0(void**);
void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
void __cdecl FUN_004213c0(int, void**);

void __cdecl PlayerLookup_00414600(void** param1) {
    if (DAT_004a0220 == 0) {
        DAT_004a0220 = 1;
        if (DAT_004a0282 == 0) {
            FUN_00424090(param1);
            return;
        }
        if (DAT_004a0295 != 0) {
            FUN_00427760(param1);
            return;
        }
        if (DAT_004a0294 != 0) {
            FUN_00424B80(param1);
            return;
        }
        if (DAT_004a0293 == 0) {
            if (FUN_00421560_DrawCharacter(FUN_004A2990, param1) == 0) {
                FUN_004250B0(param1);
                return;
            }
        } else {
            FUN_00414890(param1);
            return;
        }
    }
    if ((int)param1[0x26] == 3) {
        param1[0x15] = (void*)1;
    } else {
        param1[0x26] = (void*)((int)param1[0x26] + 1);
    }
    FUN_004213f0_GexMovementLeftandRight((void*)param1);
    FUN_004213c0(FUN_004A2990, param1);
}
}
