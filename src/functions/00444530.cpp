extern "C" void* __cdecl FUN_0041A500(void*);
extern "C" void __cdecl FUN_00444410(int);

extern "C" void __cdecl GOB_RezzifyObject_00444530(void* param_1)
{
    int* self = (int*)param_1;
    int* spr;
    int* node;
    int* e;

    if (self[0x15] < 0)
        return;

    spr = (int*)FUN_0041A500(param_1);
    if (spr == 0)
        return;

    if (self[0x30] != 0) {
        FUN_00444410(self[0x30]);
        return;
    }

    node = (int*)spr[6];
    if (node == 0)
        return;

    while (*node != 0) {
        e = (int*)*node;
        node += 1;
        if (*(int*)e[2] > 0)
            FUN_00444410(e[3]);
    }
}
