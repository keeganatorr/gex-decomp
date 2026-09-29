extern "C" {
extern int DAT_004A27A4;
extern int DAT_004A2AC8;
extern int DAT_004A27B0;
extern void __cdecl FUN_0042CBF0(int *object);
extern void __cdecl FUN_0042CC00(int *list, int *object);

typedef void (__cdecl *ObjectCallback)(int *object);

extern "C" void __cdecl GOB_DrawList_0040efa0(int *object)
{
    while (object[0] != 0) {
        if (object[0x1b] & 0x100000) {
            int *oldobj = object;
            object = (int *)object[0];
            FUN_0042CBF0(oldobj);
            FUN_0042CC00(&DAT_004A27B0, oldobj);
            --DAT_004A27A4;
        } else {
            ObjectCallback callback = (ObjectCallback)object[0x18];
            if (callback != 0)
                callback(object);
            if ((object[0x38] & 0x2000000) == 0) {
                object[0x7e] = object[0x1e];
                object[0x7f] = object[0x1f];
            }
            object[0x7d] = DAT_004A2AC8;
            object = (int *)object[0];
        }
    }
}
}
