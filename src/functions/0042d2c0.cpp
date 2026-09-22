typedef int (__cdecl *TileCallback)(int *, unsigned char *);

struct AngleEdges {
    int unused[6];
    int local_10;
    int local_c;
    int local_8;
    int local_4;
};

struct CurrentLevel {
    int field_0;
    int levelData;
    int unused_8[3];
    int tileData;
};

struct TileAttributes {
    int unused_0[5];
    TileCallback til_downFunc;
    TileCallback til_upFunc;
    int unused_1c;
};

extern "C" {
extern int DAT_004A01EC;
extern CurrentLevel *DAT_004A2990;
extern int __cdecl FUN_0041CB80(int *, AngleEdges *);
extern unsigned char * __cdecl FUN_0042CE70(int, int, int, int);
extern void __cdecl FUN_0042CD90(int *, TileCallback);
extern TileAttributes gTileAttributes[];
}

extern "C" int __cdecl GEX_Target(void *, int *gOb, TileCallback Velocity_Function)
{
    AngleEdges edges;
    int end;
    int x;
    int y;
    unsigned char *block;
    unsigned short tile;
    TileCallback function;
    int direction;

    DAT_004A01EC = 0;
    if (FUN_0041CB80(gOb, &edges) == 0)
        return 0;

    direction = (gOb[0x1f] - gOb[0x36]) >= 0;
    end = edges.local_c - 0x80000;
    x = edges.local_10 + 0x80000;

    for (;;) {
        DAT_004A01EC++;
        FUN_0041CB80(gOb, &edges);

        if (direction)
            y = edges.local_8;
        else
            y = edges.local_4;

        block = FUN_0042CE70(DAT_004A2990->levelData,
                             DAT_004A2990->tileData, x, y);
        if (block != 0) {
            gOb[0x61] = x;
            gOb[0x62] = y;
            tile = *(unsigned short *)(block + 6);
            if (tile < 126) {
                if (direction)
                    function = gTileAttributes[tile].til_downFunc;
                else
                    function = gTileAttributes[tile].til_upFunc;

                if (function != 0 &&
                    function(gOb, block) != 0 &&
                    Velocity_Function != 0 &&
                    Velocity_Function(gOb, block) == 0)
                    break;
            }
        }

        if (end == x)
            break;
        x += 0x200000;
        if (end < x)
            x = end;
    }

    x = edges.local_10 + 0x80000;
    for (;;) {
        DAT_004A01EC++;
        FUN_0041CB80(gOb, &edges);

        if (direction)
            y = edges.local_4;
        else
            y = edges.local_8;

        block = FUN_0042CE70(DAT_004A2990->levelData,
                             DAT_004A2990->tileData, x, y);
        if (block != 0) {
            gOb[0x61] = x;
            gOb[0x62] = y;
            tile = *(unsigned short *)(block + 6);
            if (tile < 126) {
                if (direction)
                    function = gTileAttributes[tile].til_upFunc;
                else
                    function = gTileAttributes[tile].til_downFunc;

                if (function != 0 &&
                    function(gOb, block) != 0 &&
                    Velocity_Function != 0 &&
                    Velocity_Function(gOb, block) == 0)
                    break;
            }
        }

        if (end == x)
            break;
        x += 0x200000;
        if (end < x)
            x = end;
    }

    FUN_0041CB80(gOb, &edges);
    if (direction)
        edges.local_8 = edges.local_4;
    gOb[0x62] = edges.local_8;
    FUN_0042CD90(gOb, Velocity_Function);
    return 0;
}
