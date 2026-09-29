extern "C" void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(int *);
extern "C" void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
extern "C" void __cdecl GOB_RemoveObject_00419520(void *);

extern "C" void __cdecl FUN_0041a810(int *object)
{
    int &phase = object[0x98 / 4];
    int &countdown = object[0x9c / 4];
    int action = ((int *)0x00459060)[phase];
    if (action > 20) {
        object[0xc8 / 4] = action;
        object[0xcc / 4] = action;
        ++phase;
        GOB_DisplayObjectScaleAndRotate_00441150(object);
        return;
    }
    if (action == 0) {
        GFX_Fade_0043f490(2, 255, 255, 255, 255, 255, 255);
        countdown = 5;
        ++phase;
        GOB_DisplayObjectScaleAndRotate_00441150(object);
    } else if (action == 1) {
        GOB_DisplayObjectScaleAndRotate_00441150(object);
        if (--countdown == 0) {
            GFX_Fade_0043f490(15, 0, 255, 0, 255, 0, 255);
            countdown = 17;
            ++phase;
        }
    } else if (action == 2 && --countdown == 0) {
        *(int *)0x0046359c = 0;
        GOB_RemoveObject_00419520(object);
    }
}
