// Adapted from pc_decomp_backup/src/functions/FUN_0043FB40.cpp
// Historical source SHA256: 778ec8467656aaa3dc6053d23da32f38628008d0622d240a78f3f68f8a456483
extern "C" {
extern short DAT_004a2a96_CameraX_After;

extern short FUN_004A2A94;


extern int *DAT_0046bc74_draw1data;
extern int *DAT_0046bc6c_drawunk1data;
extern int *DAT_0046bc70_draw4data;
extern int *DAT_0046bc68_drawunk4data;
extern int DAT_0046bc64_draw1ptr;
extern int DAT_0046bc58_drawunk1ptr;
extern int DAT_0046bc60_draw4ptr;
extern int DAT_0046bc5c_drawunk4ptr;

extern "C" void __cdecl FUN_0043fce0_DrawTilesInner(void *, void *, int, int);

extern "C" void __cdecl GEX_Target(void *CurrentTileMaybe, void *GTiles, unsigned int CameraXParam, unsigned int CameraYParam)
{
    unsigned int xParam_2;
    int CameraY;
    unsigned int *currentTile;
    unsigned int xTile;
    int yTile;
    unsigned int xParam;
    int xTile_3;
    unsigned int x_y_Param;
    int diff;

    diff = (int)DAT_004a2a96_CameraX_After;
    x_y_Param = diff >> 31;
    xParam = ((diff ^ x_y_Param) - x_y_Param) * 0x20000;

    diff = (int)FUN_004A2A94;
    x_y_Param = diff >> 31;
    x_y_Param = ((diff ^ x_y_Param) - x_y_Param) * 0x20000;

    if ((int)CameraYParam < (int)x_y_Param) {
        x_y_Param = CameraYParam;
    }
    if ((int)CameraXParam < (int)xParam) {
        xParam = CameraXParam;
    }

    DAT_0046bc74_draw1data = (int *)&DAT_0046bc64_draw1ptr;
    DAT_0046bc6c_drawunk1data = (int *)&DAT_0046bc58_drawunk1ptr;
    DAT_0046bc64_draw1ptr = 0xffffff;
    DAT_0046bc58_drawunk1ptr = 0xffffff;
    DAT_0046bc70_draw4data = (int *)&DAT_0046bc60_draw4ptr;
    DAT_0046bc68_drawunk4data = (int *)&DAT_0046bc5c_drawunk4ptr;
    DAT_0046bc60_draw4ptr = 0xffffff;
    DAT_0046bc5c_drawunk4ptr = 0xffffff;

    currentTile = (unsigned int *)((int)((char *)CurrentTileMaybe + 0x2c) +
        ((int)(CameraYParam - x_y_Param & 0xff3fffff) >> 0x16) * *(int *)((char *)CurrentTileMaybe + 0xc) +
        ((int)(CameraXParam - xParam & 0xff3fffff) >> 0x16));


    {
        int field_0x10 = *(int *)((char *)CurrentTileMaybe + 0x10);
        int camYShifted = (int)CameraYParam >> 0x18;
        xTile = (unsigned int)(field_0x10 - camYShifted != 1);
    }
    yTile = (int)xTile + 1;
    xTile = *(unsigned int *)((char *)CurrentTileMaybe + 0xc) - (unsigned int)((int)(CameraXParam - xParam) >> 0x18);
    if ((int)xTile > 3) {
        xTile = 3;
    }

    xParam_2 = CameraXParam & 0xff0000;
    CameraXParam = -(int)xParam_2;
    CameraY = -(int)(CameraYParam & 0xff0000);

    if (xParam != xParam_2 && (int)(xParam + (int)CameraXParam) > -1) {
        CameraXParam = CameraXParam - 0x1000000;
    }
    if (x_y_Param != (CameraYParam & 0xff0000) && (int)(x_y_Param + CameraY) > -1) {
        CameraY = CameraY - 0x1000000;
    }

    xTile_3 = *(int *)((char *)CurrentTileMaybe + 0xc);
    x_y_Param = CameraXParam;
    xParam_2 = xTile;

    do {
        do {
            if (*(int *)currentTile != 0) {
                FUN_0043fce0_DrawTilesInner((void *)*(int *)currentTile, GTiles, (int)x_y_Param, CameraY);
            }
            currentTile = currentTile + 1;
            xParam_2 = xParam_2 - 1;
            x_y_Param = x_y_Param + 0x1000000;
        } while (xParam_2 != 0);

        CameraY = CameraY + 0x1000000;
        yTile = yTile - 1;
        currentTile = currentTile + (xTile_3 - (int)xTile);
        x_y_Param = CameraXParam;
        xParam_2 = xTile;
    } while (yTile != 0);
}
}
