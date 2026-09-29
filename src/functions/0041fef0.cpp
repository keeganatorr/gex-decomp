extern "C" short DAT_004a0270_Background_Unk2;
extern "C" short DAT_004a0272_LEVEL_MAP;
extern "C" void __cdecl FUN_00440cb0_DrawBackgroundInnerInner(void *, int, int);

extern "C" void __cdecl PAR_DrawParallax_0041fef0(int *parallax,
                                                   int cameraX, int cameraY)
{
    int oldCameraY = parallax[3];
    parallax[3] = cameraY;
    unsigned int period = parallax[1];
    unsigned int viewY = (unsigned int)parallax[4] % period;

    int **layerSlot = (int **)(parallax + 6);
    while (*layerSlot != 0) {
        int *layer = *layerSlot++;
        int verticalStep = layer[5] * ((cameraY >> 16) - (oldCameraY >> 16)) + layer[7];
        layer[2] -= verticalStep;
        layer[3] -= verticalStep;
        while (layer[2] < 0) {
            layer[2] += period;
            layer[3] += period;
        }
        while (layer[2] >= (int)period) {
            layer[2] -= period;
            layer[3] -= period;
        }

        int visible = 0;
        int origin = viewY;
        if (layer[3] >= (int)viewY && layer[2] <= (int)(viewY + 0xf00000)) {
            visible = 1;
        } else if (layer[3] >= (int)(viewY + period) &&
                   layer[2] <= (int)(viewY + period + 0xf00000)) {
            origin = (int)(viewY - period);
            visible = 1;
        }
        DAT_004a0272_LEVEL_MAP = (short)((layer[2] - layer[9] + origin) >> 17);
        layer[9] = layer[2] + origin;
        if (!visible)
            continue;

        int oldCameraX = layer[8];
        layer[8] = cameraX;
        int horizontalStep = layer[4] * ((cameraX >> 16) - (oldCameraX >> 16)) +
                             layer[6];
        int offset = layer[1] + horizontalStep;
        layer[1] = offset;
        DAT_004a0270_Background_Unk2 = (short)(-horizontalStep >> 17);
        while (offset < 0) {
            layer[10] = layer[10] == 0 ? layer[11] : layer[10] - 1;
            int *tile = (int *)layer[12 + layer[10]];
            offset += tile[6];
            layer[1] = offset;
        }
        for (;;) {
            int *tile = (int *)layer[12 + layer[10]];
            if (tile[6] > offset)
                break;
            offset -= tile[6];
            layer[10] = layer[10] == layer[11] ? 0 : layer[10] + 1;
            layer[1] = offset;
        }

        int drawX = -offset;
        int tileIndex = layer[10];
        int animateIndex = tileIndex;
        int layerY = layer[2];
        do {
            int *tile = (int *)layer[12 + tileIndex];
            if (animateIndex >= 0) {
                tile[8] += tile[7];
                if (tile[8] > 0x10000) {
                    tile[8] -= 0x10000;
                    ++tile[3];
                }
            }
            FUN_00440cb0_DrawBackgroundInnerInner(tile, tile[4] + drawX,
                                                    origin + layerY + tile[5]);
            drawX += tile[6];
            tileIndex = tileIndex == layer[11] ? 0 : tileIndex + 1;
            if (animateIndex == tileIndex)
                animateIndex = -1;
        } while (drawX < 0x1400000);
    }
}
