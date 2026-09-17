struct M1Tile {
    int field0;
    int field1;
    int field2;
};

struct M1TileSet {
    M1Tile* tiles;
    int field1;
    int field2;
    int field3;
    int field4;
};

extern "C" {
extern M1TileSet* M1_TileSets_00463740[];
extern M1Tile gTiles_004a02f0[];
extern int M1_DidLastLoadSucceed_00463840;

void GEX_Target(void)
{
    M1TileSet** gTilesPTR = M1_TileSets_00463740;
    do {
        M1TileSet* gTiles = *gTilesPTR;
        if (gTiles != 0) {
            int currentTile = (int)gTiles->tiles;
            while (currentTile != 0) {
                currentTile = gTiles->field4 + gTiles->field3;
                gTiles->field3 = currentTile;
                if (currentTile > 0x10000) {
                    gTiles->field3 = currentTile - 0x10000;
                    currentTile = gTiles->field2 + 1;
                    gTiles->field2 = currentTile;
                    if (gTiles->tiles[currentTile].field0 == 0) {
                        gTiles->field2 = 0;
                    }
                    M1Tile* puVar2 = &gTiles->tiles[gTiles->field2];
                    gTiles_004a02f0[gTiles->field1] = *puVar2;
                }
                currentTile = (int)gTiles[1].tiles;
                gTiles = &gTiles[1];
            }
        }
        gTilesPTR++;
    } while (gTilesPTR < (M1TileSet**)&M1_DidLastLoadSucceed_00463840);
}
}
