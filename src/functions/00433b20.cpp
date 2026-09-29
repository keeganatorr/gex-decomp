extern "C" void __cdecl GOB_ProcessEvents_00433900(void **);
extern "C" void __cdecl GOB_RezzifyObject_00444530(void *);
extern "C" void __cdecl FUN_0042e850(void **);
extern "C" void __cdecl GOB_DisplayObject_00444590(void **);
extern "C" void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(int *);

static void __cdecl DefDraw_00433b20_Draw(int *object, int rotate)
{
    int timer = object[0x2e];
    int savedColour = object[0x2f];
    int flash = timer != 0 && (timer & 1) == 0;
    if (flash)
        object[0x2f] = 0x1d001d00;
    if (rotate)
        GOB_DisplayObjectScaleAndRotate_00441150(object);
    else
        GOB_DisplayObject_00444590((void **)object);
    if (flash)
        object[0x2f] = savedColour;
}

extern "C" void __cdecl DefDraw_00433b20(int *object)
{
    unsigned int flags = object[0x38];
    int *parent = (int *)object[0x57];
    flags &= ~0x02000000;
    object[0x38] = flags;
    if (flags & 0x100000) {
        object[0x35] = object[0x1e];
        object[0x36] = object[0x1f];
        object[0x3f] = object[0x1b];
        object[0x3d] = object[0x14];
        object[0x3e] = object[0x15];
        object[0x39] = 0;
        object[0x3a] = 0;
        object[0x3b] = 0;
        object[0x3c] = 0;
        flags = (((flags * 2) ^ flags) & 0x200) ^ flags;
        object[0x38] = flags & ~0x100;
        GOB_ProcessEvents_00433900((void **)object);
        if (object[0x45] == -1)
            object[0x44] = 0;
        object[0x45] = -1;
    }
    if (object[0x38] & 0x80000)
        return;
    if (object[0x2e] > 0)
        --object[0x2e];
    if (object[0x38] & 0x40000)
        GOB_RezzifyObject_00444530(object);

    if (parent != 0) {
        int savedX = object[0x1e];
        int savedY = object[0x1f];
        int offsetX = 0;
        int offsetY = 0;
        while (parent[0x57] != 0) {
            offsetX += parent[0x1e];
            offsetY += parent[0x1f];
            parent = (int *)parent[0x57];
        }
        object[0x1e] = savedX + parent[0x1e] + offsetX;
        object[0x1f] = savedY + parent[0x1f] + offsetY;
        if (object[0x38] & 0x40) {
            int savedScaleX = object[0x32];
            int savedScaleY = object[0x33];
            object[0x7e] = object[0x1e];
            object[0x7f] = object[0x1f];
            FUN_0042e850((void **)object);
            DefDraw_00433b20_Draw(object, 1);
            object[0x32] = savedScaleX;
            object[0x33] = savedScaleY;
        } else {
            DefDraw_00433b20_Draw(object, 0);
        }
        object[0x7e] = object[0x1e];
        object[0x7f] = object[0x1f];
        object[0x38] |= 0x02000000;
        object[0x1e] = savedX;
        object[0x1f] = savedY;
        return;
    }

    if (object[0x38] & 0x40) {
        int savedX = object[0x1e];
        int savedY = object[0x1f];
        int savedScaleX = object[0x32];
        int savedScaleY = object[0x33];
        FUN_0042e850((void **)object);
        DefDraw_00433b20_Draw(object, 1);
        object[0x1e] = savedX;
        object[0x1f] = savedY;
        object[0x32] = savedScaleX;
        object[0x33] = savedScaleY;
    } else {
        DefDraw_00433b20_Draw(object, 0);
    }
}
