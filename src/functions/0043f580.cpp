// Adapted from pc_decomp_backup/src/functions/FUN_0043F580.cpp
// Historical source SHA256: f7e32275fc38ba18e89c502ca594ecd8e30f3ae91265a19752be5d3691e82eba
extern "C" {
extern unsigned char DAT_004a2afa_InitUnk6;
extern unsigned char DAT_004a2af9_InitUnk5;
extern unsigned char DAT_004a2af8_InitUnk4;
extern int DAT_00460038_GraphicsDataPointer;
extern int DAT_004a2b00;

extern "C" void __cdecl FUN_00405390(char *);
extern "C" void __cdecl FUN_00445140_InnerGraphics(int);
extern "C" void __cdecl FUN_0043f310_InitializeGraphicsVariables();
extern "C" void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);

extern "C" void __cdecl GEX_Target()
{
    unsigned int uVar1;
    int pGVar2;
    unsigned char bVar3;
    unsigned char local_3;
    unsigned char local_2;
    unsigned char local_1;

    local_3 = DAT_004a2afa_InitUnk6;
    local_2 = DAT_004a2af9_InitUnk5;
    local_1 = DAT_004a2af8_InitUnk4;
    FUN_00405390((char *)0x00460df4);
    if (DAT_00460038_GraphicsDataPointer != 0) {
        while (DAT_004a2b00 != 0) {
            pGVar2 = DAT_00460038_GraphicsDataPointer;
            uVar1 = *(unsigned int *)pGVar2;
            while ((uVar1 & 0xffffff) != 0xffffff) {
                pGVar2 = *(int *)pGVar2;
                if ((*(unsigned char *)(pGVar2 + 7) != 0) && (*(unsigned char *)(pGVar2 + 7) != 0xe1)) {
                    bVar3 = DAT_004a2afa_InitUnk6;
                    if (local_3 != *(unsigned char *)(pGVar2 + 4)) {
                        bVar3 = (unsigned char)(((unsigned int)DAT_004a2afa_InitUnk6 * (unsigned int)*(unsigned char *)(pGVar2 + 4)) / (unsigned int)local_3);
                    }
                    *(unsigned char *)(pGVar2 + 4) = bVar3;
                    bVar3 = DAT_004a2af9_InitUnk5;
                    if (local_2 != *(unsigned char *)(pGVar2 + 5)) {
                        bVar3 = (unsigned char)(((unsigned int)DAT_004a2af9_InitUnk5 * (unsigned int)*(unsigned char *)(pGVar2 + 5)) / (unsigned int)local_2);
                    }
                    *(unsigned char *)(pGVar2 + 5) = bVar3;
                    bVar3 = DAT_004a2af8_InitUnk4;
                    if (local_1 != *(unsigned char *)(pGVar2 + 6)) {
                        bVar3 = (unsigned char)(((unsigned int)DAT_004a2af8_InitUnk4 * (unsigned int)*(unsigned char *)(pGVar2 + 6)) / (unsigned int)local_1);
                    }
                    *(unsigned char *)(pGVar2 + 6) = bVar3;
                }
                uVar1 = *(unsigned int *)pGVar2;
            }
            FUN_00445140_InnerGraphics(DAT_00460038_GraphicsDataPointer);
            local_3 = DAT_004a2afa_InitUnk6;
            local_2 = DAT_004a2af9_InitUnk5;
            local_1 = DAT_004a2af8_InitUnk4;
            if (DAT_004a2afa_InitUnk6 == 0) {
                local_3 = 1;
            }
            if (DAT_004a2af9_InitUnk5 == 0) {
                local_2 = 1;
            }
            if (DAT_004a2af8_InitUnk4 == 0) {
                local_1 = 1;
            }
            FUN_0043f310_InitializeGraphicsVariables();
            FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
        }
    }
}
}
