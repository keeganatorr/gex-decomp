extern "C" {
// Declaration order is load-bearing: VC4 orders the compare's operands by
// internal symbol numbering (docs/knowledge/symbol-numbering.md).
extern void __cdecl FUN_0042CC70(int, void *);
extern void *DAT_004A27FC;
int __cdecl FUN_0042dcf0_Object_unk(void *object)
{
    void *subject = object;
    void *value = DAT_004A27FC;
    if (subject == value)
        FUN_0042CC70(0, subject);
    return 0;
}
}
