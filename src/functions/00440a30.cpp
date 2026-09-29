extern "C" int __cdecl FUN_00402fa0_GetFrameTimingValue(void);
extern "C" void __cdecl GXINP_ReadPads_0041fc40(void);
extern "C" void __cdecl FUN_0043eed0_TvStatic(void);
extern "C" void __cdecl FUN_0043f080_ResetGraphics_Clean1(unsigned int);
extern "C" void __cdecl FUN_00444800_Tiles(int, int, int, int, int,
                                             unsigned int, unsigned int);
extern "C" void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(int *);
extern "C" void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
extern "C" void __cdecl CEL_DrawCels_0043db70(int);

extern "C" void __cdecl FUN_00440a30_ContainsInput_CallsInputFunction_MAINGAMELOOP(void)
{
    int countdown = *(int *)0x00460f60;
    int width = 0x10000;
    int frame = 0;
    int shrinking = 0;
    int object[0x81];
    for (int index = 0; index < 0x81; ++index)
        object[index] = 0;
    object[0x32] = 1;
    object[0x33] = 1;
    object[0x1e] = 0xa00000;
    object[3] = *(int *)0x004a2ad4;
    *(int *)0x004a2a38 = 0;
    *(int *)0x004a2a1c = 0;
    *(int *)0x004a2974 = 0;
    *(short *)0x004a2a96 = 0;
    *(int *)0x004a2988 = 0;
    *(short *)0x004a2a94 = 0;
    object[0x1f] = 0x780000;
    object[0x31] = 0xe00000;
    object[0x14] = 0x17;

    int done;
    do {
        done = 0;
        ++frame;
        FUN_00402fa0_GetFrameTimingValue();
        GXINP_ReadPads_0041fc40();
        if (!shrinking)
            FUN_0043eed0_TvStatic();
        FUN_0043f080_ResetGraphics_Clean1(0);
        int image = *(int *)0x00460f50;
        FUN_00444800_Tiles(0x0046bc80, 0, 0, 0xa00000, 0x770000, image,
                           0x1f001f00);
        FUN_00444800_Tiles(0x0046bc8c, 0xa00000, 0, 0xa00000, 0x770000,
                           image, 0x1f001f00);
        FUN_00444800_Tiles(0x0046bc98, 0, 0x780000, 0xa00000, 0x780000,
                           image, 0x1f001f00);
        FUN_00444800_Tiles(0x0046bca4, 0xa00000, 0x780000, 0xa00000,
                           0x780000, image, 0x1f001f00);
        FUN_00444800_Tiles(0x0046bcb0, 0, 0x770000, width, 0x10000,
                           image, 0x1f001f00);
        FUN_00444800_Tiles(0x0046bcbc, 0x1410000 - width, 0x770000,
                           width, 0x10000, image, 0x1f001f00);
        if (shrinking) {
            GOB_DisplayObjectScaleAndRotate_00441150(object);
            object[0x32] = *(int *)0x00460f64 / countdown;
            object[0x31] = (object[0x31] + *(int *)0x00460f58) & 0xff0000;
            if (countdown <= *(int *)0x00460f5c || frame > 0x48) {
                frame = 0;
                done = 1;
            }
            countdown -= *(int *)0x00460f68;
            object[0x33] = object[0x32];
        } else {
            width += (0xa00000 - width) / *(int *)0x00460f54;
            if (width > 0x9effff || frame > 0x46) {
                shrinking = 1;
                frame = 0;
            }
        }
        FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
        CEL_DrawCels_0043db70(1);
    } while (!done && *(unsigned char *)0x004a0285 == 0);
}
