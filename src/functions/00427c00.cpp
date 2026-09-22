extern "C" {
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
extern int FUN_004A2990;
void __cdecl FUN_00422360(void*);
void __cdecl FUN_00424B80(void*);
void __cdecl FUN_00427760(void*);
void __cdecl FUN_00424AA0(void*);
void __cdecl FUN_00424090(void*);
void __cdecl FUN_004250B0(void*);
void __cdecl FUN_004213F0(void*);
void __cdecl FUN_004213C0(int, void*);
int __cdecl FUN_00421560(int, void*);

void __cdecl GEX_Target(void* param_1)
{
    if ((DAT_004A0295 != 0 || DAT_004A0294 != 0) && DAT_004A0293 == 0) {
        FUN_00422360(param_1);
        if (DAT_004A0294 != 0) {
            FUN_00424B80(param_1);
            return;
        }
        FUN_00427760(param_1);
        return;
    }
    int count = *(int*)((char*)param_1 + 0x98) + 1;
    *(int*)((char*)param_1 + 0x98) = count;
    if (count >= 3) {
        *(int*)((char*)param_1 + 0x98) = 0;
        int frame = *(int*)((char*)param_1 + 0x54) + 1;
        *(int*)((char*)param_1 + 0x54) = frame;
        if (frame > 3) {
            FUN_00422360(param_1);
            if (*(int*)((char*)param_1 + 0xa4) != 0) {
                FUN_00424AA0(param_1);
                return;
            }
            FUN_00424090(param_1);
            return;
        }
    }
    FUN_004213F0(param_1);
    FUN_004213C0(FUN_004A2990, param_1);
    if (FUN_00421560(FUN_004A2990, param_1) == 0) {
        FUN_00422360(param_1);
        FUN_004250B0(param_1);
    }
}
}
