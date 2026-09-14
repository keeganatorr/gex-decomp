extern "C" {
extern void *DAT_004A27FC;
extern void __cdecl FUN_0042CC70(int, void *);
int __cdecl GEX_Target(void *object)
{
    void *subject = object;
    void *value = DAT_004A27FC;
    if (subject == value)
        FUN_0042CC70(0, subject);
    return 0;
}
}
