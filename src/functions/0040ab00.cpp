extern "C" {
extern void *PTR_M1_00455b80;
extern int OIN_DefaultIntroDist_00455b70;
extern int OIN_DefaultIntroRemoveDist_00455b74;
extern volatile int M1_004a2a80;
extern void __cdecl M1_EnterLevel_00409a30(void *);
extern void __cdecl FUN_00409fe0_RestartHWND(void);
extern int __cdecl M1_PlayLevel_0040a010(void *);
extern void __cdecl M1_ExitLevel_0040a660(void *);
void __cdecl FUN_0040ab00_EnterMainLoop(void)
{
    OIN_DefaultIntroDist_00455b70 = 0xa00000;
    OIN_DefaultIntroRemoveDist_00455b74 = 0xc00000;
    M1_EnterLevel_00409a30(PTR_M1_00455b80);
    FUN_00409fe0_RestartHWND();
    while (M1_PlayLevel_0040a010(PTR_M1_00455b80) && !M1_004a2a80)
        ;
    M1_ExitLevel_0040a660(PTR_M1_00455b80);
}
}
