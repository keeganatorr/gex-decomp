// Reconstructed from the pinned 00443ae0 instructions and a read-only Ghidra
// decompilation. Tile command layout and linked-list writes are provisional.
// The older backup source stopped after one tile and wrote through the address
// of the command-pool pointer instead of the pool itself.
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;

struct ImageStruct {
    int width;
    int height;
    int x_offset;
    int y_offset;
    byte flags;
    byte pad11;
    short cacheSlot;
    short firstTile;
    byte pad16[6];
    int expanded;
};
struct DrawStruct {
    DrawStruct *next;
    uint tag;
    ImageStruct *image;
    void *tileSelect;
    uint color;
};
struct SpriteStruct {
    byte pad[0x18];
    DrawStruct *draw;
};

extern "C" {
SpriteStruct *__cdecl GOB_GetCurrentFrameOrReset_0041a500(int *);
uint __cdecl FUN_0043e2c0(uint);
int *__cdecl FUN_0043e580_Image_Clean1(ImageStruct *);
int *__cdecl FUN_0043e920_Image(ImageStruct *);
uint __cdecl FUN_0043ecf0_SelectTile_Clean1(void *);
extern int gObjectTextureMap_00460f6c;
extern byte *PTR_004a2ae4;
extern byte *DAT_004a2adc_Tiles2;
extern byte *DAT_004a2ae0_TilesBack1;
extern int *DAT_004a2b14_Draw4;
extern int *DAT_004a2b18_Draw1;
extern ushort _DAT_004a2b20_Draw6;
}

static int lerpComponent_00443ae0(int a, int b, int position, int extent)
{
    if (position == 0 || a == b) return a;
    if (position == extent) return b;
    return (short)((short)(((b - a) * position) / extent) + a);
}

static uint pair_00443ae0(int x, int y, int width, int height,
                          uint a, uint b, uint c, uint d)
{
    int ax = (short)a, ay = (short)(a >> 16);
    int bx = (short)b, by = (short)(b >> 16);
    int cx = (short)c, cy = (short)(c >> 16);
    int dx = (short)d, dy = (short)(d >> 16);
    int lowerX = lerpComponent_00443ae0(ax, bx, x, width);
    int lowerY = lerpComponent_00443ae0(ay, by, x, width);
    int upperX = lerpComponent_00443ae0(dx, cx, x, width);
    int upperY = lerpComponent_00443ae0(dy, cy, x, width);
    int resultX = lerpComponent_00443ae0(lowerX, upperX, y, height);
    int resultY = lerpComponent_00443ae0(lowerY, upperY, y, height);
    return ((uint)(ushort)resultY << 16) | (ushort)resultX;
}

extern "C" void __cdecl GOB_DisplayCelToQuad_00443ae0(
    int *object, int index, uint x1, uint y1, uint x2, uint y2,
    uint x3, uint y3, uint x4, uint y4)
{
    if (object[0x15] < 0) return;
    SpriteStruct *frame = GOB_GetCurrentFrameOrReset_0041a500(object);
    if (!frame || !frame->draw) return;
    DrawStruct *draw = frame->draw + index;
    ImageStruct *image = draw->image;
    if (!image || !image->firstTile) return;

    int width = image->width >> 16;
    int height = image->height >> 16;
    uint color = object[0x2f] ? (uint)object[0x2f] : draw->color;
    uint pixel = FUN_0043e2c0(color);
    byte *info = 0;
    ushort *texture = 0;
    if (!(image->flags & 0x40)) {
        info = (byte *)(image->expanded == 0
                        ? FUN_0043e580_Image_Clean1(image)
                        : FUN_0043e920_Image(image));
    } else {
        texture = (ushort *)(gObjectTextureMap_00460f6c + image->cacheSlot * 8);
    }
    ushort palette = 0;
    if ((image->flags & 3) != 2) {
        void *select = object[0x30] ? (void *)object[0x30] : draw->tileSelect;
        palette = (ushort)FUN_0043ecf0_SelectTile_Clean1(select);
    }
    uint a = ((y1 >> 16) << 16) | (ushort)(x1 >> 16);
    uint b = ((y2 >> 16) << 16) | (ushort)(x2 >> 16);
    uint c = ((y3 >> 16) << 16) | (ushort)(x3 >> 16);
    uint d = ((y4 >> 16) << 16) | (ushort)(x4 >> 16);
    short *segment = (short *)((byte *)image + 0x14);
    while (*segment) {
        byte *command = PTR_004a2ae4;
        byte *next = command + 80;
        if (next > DAT_004a2adc_Tiles2) {
            command = DAT_004a2ae0_TilesBack1;
            next = command + 80;
        }
        PTR_004a2ae4 = next;
        *(uint *)(command + 4) = pixel |
            ((-((uint)((color & 0x8080) == 0)) & 0xfe000000) + 0x2e000000);
        *(ushort *)(command + 14) = palette;

        int sx0 = segment[2];
        int sy0 = segment[3];
        int sx1 = sx0 + *(byte *)(segment + 1);
        int sy1 = sy0 + *(byte *)((byte *)segment + 3);
        *(uint *)(command + 8) = pair_00443ae0(sx0, sy0, width, height, a, b, c, d);
        *(uint *)(command + 16) = pair_00443ae0(sx1, sy0, width, height, a, b, c, d);
        *(uint *)(command + 24) = pair_00443ae0(sx0, sy1, width, height, a, b, c, d);
        *(uint *)(command + 32) = pair_00443ae0(sx1, sy1, width, height, a, b, c, d);

        ushort mode;
        byte u, v;
        if (!(image->flags & 0x40)) {
            mode = *(ushort *)(info + 16);
            u = info[18];
            v = info[19];
        } else {
            mode = texture[0];
            u = ((byte *)texture)[2];
            v = ((byte *)texture)[3];
        }
        if (!(color & 1)) mode |= 0x20;
        *(ushort *)(command + 22) = mode;
        _DAT_004a2b20_Draw6 = mode;
        command[12] = u;
        command[13] = v;
        command[20] = (byte)(u + *(byte *)(segment + 1) - 1);
        command[21] = v;
        command[28] = u;
        command[29] = (byte)(v + *(byte *)((byte *)segment + 3) - 1);
        command[36] = command[20];
        command[37] = command[29];
        if (!(image->flags & 0x40)) info = *(byte **)(info + 4);
        else texture += 4;

        *DAT_004a2b18_Draw1 = (int)command;
        DAT_004a2b18_Draw1 = (int *)command;
        for (int word = 0; word < 10; ++word)
            ((int *)(command + 40))[word] = ((int *)command)[word];
        *DAT_004a2b14_Draw4 = (int)(command + 40);
        DAT_004a2b14_Draw4 = (int *)(command + 40);
        segment += 4;
    }
}
