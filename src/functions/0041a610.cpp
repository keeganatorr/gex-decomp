// EditedGex's loop and the original REP STOSD both clear exactly 36 words.
extern "C" {
extern unsigned int DAT_004A2710[36];
extern void *__cdecl memset(void *, int, unsigned int);
void __cdecl InitStartDoors_0041a610(void)
{
    memset(DAT_004A2710, 0, sizeof(DAT_004A2710));
}
}
