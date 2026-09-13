// Adapted from pc_decomp_backup/src/functions/FUN_0041F7A0.cpp
// Historical source SHA256: 94f9a7be1bf05f362358b33e5062047657d72a50aa4dc8451575f93f9e0cc6f1
extern "C" {
extern "C" { extern int DAT_00463740; }
extern "C" { extern int DAT_004A02F0; }

extern "C" void __cdecl GEX_Target()
{
    
    
    
    
    
    int* const tileTable = (int*)0x004A02F0;
    int* gTiles;
    int* gTilesPTR;
    int currentTile;

    gTilesPTR = (int*)&DAT_00463740;
    do {
        gTiles = (int*)*gTilesPTR;
        if (gTiles != (int*)0x0) {
            currentTile = gTiles[0];
            while (currentTile != 0) {
                currentTile = gTiles[4] + gTiles[3];
                gTiles[3] = currentTile;
                if (currentTile > 0x10000) {
                    gTiles[3] = currentTile - 0x10000;
                    currentTile = gTiles[2] + 1;
                    gTiles[2] = currentTile;
                    if (*(int*)(gTiles[0] + currentTile * 0xc) == 0) {
                        gTiles[2] = 0;
                    }
                    currentTile = gTiles[1];
                    {
                        int* puVar2 = (int*)(gTiles[0] + gTiles[2] * 0xc);
                        tileTable[currentTile * 3] = puVar2[0];
                        tileTable[currentTile * 3 + 1] = puVar2[1];
                        tileTable[currentTile * 3 + 2] = puVar2[2];
                    }
                }
                gTiles = (int*)&gTiles[5];
                currentTile = *gTiles;
            }
        }
        gTilesPTR = gTilesPTR + 1;
    } while ((int)gTilesPTR < (int)&DAT_00463740 + 0x100);
}
}
