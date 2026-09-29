extern "C" int __cdecl OBI_CheckRemoveObject_0040fce0(int *);
extern "C" int __cdecl UTL_ReallyRandom_00428c80(int);
extern "C" unsigned int __cdecl GetTileFlagsAtPosition_00420c10(unsigned int,
                                                                 unsigned int);
extern "C" void __cdecl GOB_RemoveObject_00419520(void *);
extern "C" void __cdecl GOB_DisplayObject_00444590(void **);

extern "C" void __cdecl FUN_00420d40(void *object)
{
    unsigned char *data = (unsigned char *)object;
    if (OBI_CheckRemoveObject_0040fce0((int *)object))
        return;

    int &verticalSpeed = *(int *)(data + 0x8c);
    int target = *(int *)0x0045a6fc;
    int speedStep = *(int *)0x0045a6f8;
    if (verticalSpeed < target)
        verticalSpeed += speedStep;
    else if (verticalSpeed > target)
        verticalSpeed -= speedStep;

    int &horizontalSpeed = *(int *)(data + 0x80);
    int &turning = *(int *)(data + 0x98);
    int &timer = *(int *)(data + 0x9c);
    if (turning == 0) {
        int bound = *(int *)0x0045a704;
        int step = *(int *)0x0045a700;
        if (horizontalSpeed < 0) {
            if (-bound <= horizontalSpeed)
                turning = 1;
            else
                horizontalSpeed += step;
        } else if (horizontalSpeed > bound) {
            horizontalSpeed -= step;
        } else {
            turning = 1;
        }
    } else if (timer > 0) {
        --timer;
    } else {
        timer = *(int *)0x0045a70c +
                UTL_ReallyRandom_00428c80(*(int *)0x0045a708);
        horizontalSpeed = (UTL_ReallyRandom_00428c80(9) - 4) * 0x4000;
    }

    int &x = *(int *)(data + 0x78);
    int &y = *(int *)(data + 0x7c);
    x += horizontalSpeed;
    y += verticalSpeed;
    if (GetTileFlagsAtPosition_00420c10(x, y) & 1)
        GOB_DisplayObject_00444590((void **)object);
    else
        GOB_RemoveObject_00419520(object);
}
