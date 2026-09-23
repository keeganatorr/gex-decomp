extern "C" {
extern int DAT_004A2890;
extern void __cdecl FUN_00425250(void*);
extern void __cdecl FUN_00424D80(void*);

int __cdecl GEX_Target(void* param_1)
{
    if (DAT_004A2890 < 0) {
        DAT_004A2890 = 0;
        FUN_00425250(param_1);
        return 1;
    }
    if (DAT_004A2890 > 0) {
        int save;
        int vel;
        vel = DAT_004A2890;
        save = *(int*)((char*)param_1 + 0x8c);
        DAT_004A2890 = 0;
        FUN_00424D80(param_1);
        *(int*)((char*)param_1 + 0x8c) = save;
        *(int*)((char*)param_1 + 0xa0) = vel;
        return 1;
    }
    return 0;
}
}