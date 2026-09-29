typedef struct GXObject {
    unsigned char _pad0[0xc4];
    int gob_angle;             /* 0xc4 */
    int gob_scaleX;            /* 0xc8 */
    int gob_scaleY;            /* 0xcc */
} GXObject;
extern "C" {
extern int gTrigTable_0045a5c8[];
extern int DAT_004642a4;
extern unsigned char gInputControllers_004a0280[];
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *gob);
void __cdecl GOB_DisplayObject_00444590(GXObject *gob);
void __cdecl PlatformDraw_00434670(GXObject *gob)
{
    int sx;
    int sy;

    DAT_004642a4 += 0x10000;
    if (DAT_004642a4 >= 0x1000000)
        DAT_004642a4 -= 0x1000000;
    sx = ((DAT_004642a4 >> 16) < 0 ? -((-(DAT_004642a4 >> 16)) > 256 ? (((-(DAT_004642a4 >> 16)) % 256) > 128 ? -((((-(DAT_004642a4 >> 16)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-(DAT_004642a4 >> 16)) % 256) - 128)] : gTrigTable_0045a5c8[((-(DAT_004642a4 >> 16)) % 256) - 128]) : ((((-(DAT_004642a4 >> 16)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-(DAT_004642a4 >> 16)) % 256))] : gTrigTable_0045a5c8[((-(DAT_004642a4 >> 16)) % 256)])) : ((-(DAT_004642a4 >> 16)) > 128 ? -(((-(DAT_004642a4 >> 16)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-(DAT_004642a4 >> 16)) - 128)] : gTrigTable_0045a5c8[(-(DAT_004642a4 >> 16)) - 128]) : ((-(DAT_004642a4 >> 16)) > 64 ? gTrigTable_0045a5c8[128 - (-(DAT_004642a4 >> 16))] : gTrigTable_0045a5c8[-(DAT_004642a4 >> 16)]))) : ((DAT_004642a4 >> 16) > 256 ? (((DAT_004642a4 >> 16) % 256) > 128 ? -((((DAT_004642a4 >> 16) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((DAT_004642a4 >> 16) % 256) - 128)] : gTrigTable_0045a5c8[((DAT_004642a4 >> 16) % 256) - 128]) : ((((DAT_004642a4 >> 16) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((DAT_004642a4 >> 16) % 256))] : gTrigTable_0045a5c8[((DAT_004642a4 >> 16) % 256)])) : ((DAT_004642a4 >> 16) > 128 ? -(((DAT_004642a4 >> 16) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((DAT_004642a4 >> 16) - 128)] : gTrigTable_0045a5c8[(DAT_004642a4 >> 16) - 128]) : ((DAT_004642a4 >> 16) > 64 ? gTrigTable_0045a5c8[128 - (DAT_004642a4 >> 16)] : gTrigTable_0045a5c8[DAT_004642a4 >> 16])))) * 5;
    if (sx < 0)
        sx = -sx;
    sy = (((DAT_004642a4 >> 16) + 64) < 0 ? -((-((DAT_004642a4 >> 16) + 64)) > 256 ? (((-((DAT_004642a4 >> 16) + 64)) % 256) > 128 ? -((((-((DAT_004642a4 >> 16) + 64)) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((-((DAT_004642a4 >> 16) + 64)) % 256) - 128)] : gTrigTable_0045a5c8[((-((DAT_004642a4 >> 16) + 64)) % 256) - 128]) : ((((-((DAT_004642a4 >> 16) + 64)) % 256)) > 64 ? gTrigTable_0045a5c8[128 - (((-((DAT_004642a4 >> 16) + 64)) % 256))] : gTrigTable_0045a5c8[((-((DAT_004642a4 >> 16) + 64)) % 256)])) : ((-((DAT_004642a4 >> 16) + 64)) > 128 ? -(((-((DAT_004642a4 >> 16) + 64)) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((-((DAT_004642a4 >> 16) + 64)) - 128)] : gTrigTable_0045a5c8[(-((DAT_004642a4 >> 16) + 64)) - 128]) : ((-((DAT_004642a4 >> 16) + 64)) > 64 ? gTrigTable_0045a5c8[128 - (-((DAT_004642a4 >> 16) + 64))] : gTrigTable_0045a5c8[-((DAT_004642a4 >> 16) + 64)]))) : (((DAT_004642a4 >> 16) + 64) > 256 ? ((((DAT_004642a4 >> 16) + 64) % 256) > 128 ? -(((((DAT_004642a4 >> 16) + 64) % 256) - 128) > 64 ? gTrigTable_0045a5c8[128 - ((((DAT_004642a4 >> 16) + 64) % 256) - 128)] : gTrigTable_0045a5c8[(((DAT_004642a4 >> 16) + 64) % 256) - 128]) : (((((DAT_004642a4 >> 16) + 64) % 256)) > 64 ? gTrigTable_0045a5c8[128 - ((((DAT_004642a4 >> 16) + 64) % 256))] : gTrigTable_0045a5c8[(((DAT_004642a4 >> 16) + 64) % 256)])) : (((DAT_004642a4 >> 16) + 64) > 128 ? -((((DAT_004642a4 >> 16) + 64) - 128) > 64 ? gTrigTable_0045a5c8[128 - (((DAT_004642a4 >> 16) + 64) - 128)] : gTrigTable_0045a5c8[((DAT_004642a4 >> 16) + 64) - 128]) : (((DAT_004642a4 >> 16) + 64) > 64 ? gTrigTable_0045a5c8[128 - ((DAT_004642a4 >> 16) + 64)] : gTrigTable_0045a5c8[(DAT_004642a4 >> 16) + 64])))) * 5;
    if (sy < 0)
        sy = -sy;
    if (gInputControllers_004a0280[0x28]) {
        gob->gob_angle = DAT_004642a4;
        gob->gob_scaleX = sx;
        gob->gob_scaleY = sy;
        GOB_DisplayObjectScaleAndRotate_00441150(gob);
        return;
    }
    gob->gob_scaleX = 0x10000;
    gob->gob_scaleY = 0x10000;
    gob->gob_angle = 0;
    GOB_DisplayObject_00444590(gob);
}
}
