extern "C" {
extern unsigned char DAT_004a0294;
extern unsigned char DAT_004a0283;
extern int FUN_004A2990;
void __cdecl FUN_00424B80(void* param_1);
void __cdecl FUN_00424090(void* param_1);
void __cdecl FUN_004250B0(void* param_1);
void __cdecl FUN_00427850(void* param_1);
void __cdecl FUN_004213f0(void* param_1);
void __cdecl FUN_004213c0(int level, void* param_1);
int  __cdecl FUN_00421560_DrawCharacter(int level, void* param_1);
}

struct GXObjectWork {
    char pad[0x98];
    int counter;
};

extern "C" void __cdecl GEX_Target(void* param_1)
{
    if (DAT_004a0294 != 0) {
        FUN_00424B80(param_1);
        return;
    }
    if (DAT_004a0283 == 0) {
        FUN_00424090(param_1);
        return;
    }
    if (FUN_00421560_DrawCharacter(FUN_004A2990, param_1) == 0) {
        FUN_004250B0(param_1);
        return;
    }
    GXObjectWork* obj = (GXObjectWork*)param_1;
    if (++obj->counter >= 4) {
        FUN_00427850(param_1);
        return;
    }
    FUN_004213f0(param_1);
    FUN_004213c0(FUN_004A2990, param_1);
}
