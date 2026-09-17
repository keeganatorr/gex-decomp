extern "C" {
extern int DAT_004A27A4;
extern void* DAT_004A27B0;
extern void* DAT_004A28A0;
extern void* DAT_004a2918_LevelObjectsListEnd;

extern void __cdecl FUN_0041E930();
extern void __cdecl FUN_0042CBF0(void**);
extern void __cdecl FUN_0042CC00(void**, void**);

void __cdecl GEX_Target()
{
    void* loaded_gOb;
    void* pGVar2;
    char* pppGVar3;
    int flagMask;

    pppGVar3 = (char*)&DAT_004A28A0;
    FUN_0041E930();
    do {
        loaded_gOb = *(void**)pppGVar3;
        if (*(void**)loaded_gOb == (void*)0x0) {
            goto next_list;
        }
        flagMask = 0x100000;
        do {
            pGVar2 = *(void**)loaded_gOb;
            if ((*(int*)((int)loaded_gOb + 0x6c) & flagMask) != 0) {
                FUN_0042CBF0((void**)loaded_gOb);
                FUN_0042CC00((void**)&DAT_004A27B0, (void**)loaded_gOb);
                DAT_004A27A4 = DAT_004A27A4 - 1;
            }
            loaded_gOb = pGVar2;
        } while (*(void**)pGVar2 != (void*)0x0);
next_list:
        pppGVar3 += 0x0c;
    } while (pppGVar3 < (char*)&DAT_004a2918_LevelObjectsListEnd);
}
}
