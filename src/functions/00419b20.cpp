// Adapted from pc_decomp_backup/src/functions/FUN_00419B20.cpp
// Historical source SHA256: d23b10463b4793044507cef9be6df769e3cc4f7b23bccb0f8368ea18d9348742
extern "C" {
extern "C" { extern int DAT_004A27A4; }
extern void* DAT_004A27B0;
extern void* DAT_004A28A0;

extern "C" void __cdecl FUN_0041E930();
extern "C" void __cdecl FUN_0042CBF0(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);

extern "C" void __cdecl GEX_Target()
{
    void* pppGVar3;
    void* loaded_gOb;
    void* pGVar2;
    int flagMask;

    pppGVar3 = (void*)&DAT_004A28A0;
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
        } while (*(void**)loaded_gOb != (void*)0x0);
next_list:
        pppGVar3 = (void*)((int)pppGVar3 + 0x0c);
    } while ((int)pppGVar3 < 0x004A2918);
}
}
