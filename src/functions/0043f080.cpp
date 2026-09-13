// Adapted from pc_decomp_backup/src/functions/FUN_0043F080.cpp
// Historical source SHA256: 567f2d10fb5e40191503ac47521ae30e501bb5f9e460d2ff387e64108d05e359
extern "C" {
extern "C" { extern unsigned int DAT_00460678; }
extern "C" { extern unsigned char DAT_00460674; }
extern "C" { extern int DAT_00460258; }
extern "C" { extern unsigned int DAT_0046A534; }
extern "C" { extern int DAT_004A2AE4; }
extern "C" { extern int DAT_004A2ADC; }
extern "C" { extern int DAT_004A2AE0; }
extern "C" { extern int DAT_004A2B18; }
extern "C" { extern int DAT_004A2B14; }
extern "C" { extern unsigned char DAT_004A2AF8; }
extern "C" { extern unsigned char DAT_004A2AF9; }
extern "C" { extern unsigned char DAT_004A2AFA; }
extern "C" { extern int DAT_004A2B0C; }
extern "C" { extern int DAT_004A2B10; }
extern "C" { extern unsigned char DAT_0046A5A1; }
extern "C" { extern unsigned char DAT_0046A5A2; }
extern "C" { extern unsigned char DAT_0046A5A3; }
extern "C" { extern unsigned char DAT_0046A5FD; }
extern "C" { extern unsigned char DAT_0046A5FE; }
extern "C" { extern unsigned char DAT_0046A5FF; }

extern "C" int __cdecl FUN_0043E580(int *);
extern "C" unsigned int __cdecl FUN_0043ECF0(int);
extern "C" void __cdecl FUN_00445350(int, int, int, int);

extern "C" void __cdecl GEX_Target(unsigned int graphicsMode)
{
    int *imageInfo;
    unsigned int selectedTileIndex;
    int rowCounter;
    int rowIndex;
    int colCounter;
    int nextTilePtr;
    int tilePtr;
    int currentTile;
    int pMVar2;
    unsigned char *tileBytes;
    unsigned char *pMVar2Bytes;

    if (graphicsMode == DAT_00460678) {
        if (DAT_00460674 != 0) {
            imageInfo = (int *)FUN_0043E580(&DAT_00460258);
            selectedTileIndex = FUN_0043ECF0(DAT_0046A534);

            nextTilePtr = DAT_004A2AE4 + 6;
            tilePtr = DAT_004A2AE4;
            DAT_004A2AE4 = nextTilePtr;
            if (DAT_004A2ADC < nextTilePtr) {
                tilePtr = DAT_004A2AE0;
                DAT_004A2AE4 = DAT_004A2AE0 + 6;
            }
            FUN_00445350(
                tilePtr, 0, 1,
                ((imageInfo[3] & 0x3c0) | 0x800) >> 6 | (imageInfo[3] & 0x1000000) >> 0x14);
            *(int *)DAT_004A2B18 = tilePtr;
            {
                int puVar1 = tilePtr + 3;
                DAT_004A2B18 = tilePtr;
                *(int *)puVar1 = *(int *)(tilePtr + 0);
                *(int *)(puVar1 + 1) = *(int *)(tilePtr + 1);
                *(int *)(puVar1 + 2) = *(int *)(tilePtr + 2);
            }
            {
                int puVar1_addr = tilePtr + 3;
                *(int *)DAT_004A2B14 = puVar1_addr;
                DAT_004A2B14 = puVar1_addr;
            }
            rowCounter = 0;
            do {
                colCounter = 0;
                do {
                    nextTilePtr = DAT_004A2AE4 + 10;
                    tilePtr = DAT_004A2AE4;
                    DAT_004A2AE4 = nextTilePtr;
                    if (DAT_004A2ADC < nextTilePtr) {
                        tilePtr = DAT_004A2AE0;
                        DAT_004A2AE4 = DAT_004A2AE0 + 10;
                    }
                    pMVar2 = tilePtr + 5;
                    tileBytes = (unsigned char *)tilePtr;
                    pMVar2Bytes = (unsigned char *)pMVar2;

                    tileBytes[7] = 100;
                    *(unsigned short *)(tileBytes + 8) = (unsigned short)rowCounter;
                    *(unsigned short *)(tileBytes + 10) = (unsigned short)colCounter;
                    colCounter = colCounter + 32;
                    *(unsigned short *)(tileBytes + 16) = 0x40;
                    *(unsigned short *)(tileBytes + 18) = 0x20;
                    tileBytes[12] = (unsigned char)((short)imageInfo[3] << 2);
                    tileBytes[13] = *(unsigned char *)((int)imageInfo + 0xe);
                    *(unsigned short *)(tileBytes + 14) = (unsigned short)selectedTileIndex;
                    tileBytes[4] = DAT_004A2AFA;
                    tileBytes[5] = DAT_004A2AF9;
                    tileBytes[6] = DAT_004A2AF8;

                    *(int *)DAT_004A2B18 = tilePtr;
                    currentTile = tilePtr;
                    DAT_004A2B18 = tilePtr;
                    for (rowIndex = 5; rowIndex != 0; rowIndex = rowIndex - 1) {
                        *(int *)(pMVar2Bytes + 0) = *(int *)((unsigned char *)currentTile + 0);
                        pMVar2Bytes = pMVar2Bytes + 12;
                        currentTile = (int)((unsigned char *)currentTile + 12);
                    }
                    DAT_004A2B10 = (int)(tilePtr + 4);
                    *(int *)DAT_004A2B14 = (int)(tilePtr + 4);
                    DAT_004A2B14 = (int)(tilePtr + 4);
                } while (colCounter < 0xf0);
                rowCounter = rowCounter + 0x40;
            } while (rowCounter < 0x140);
            DAT_004A2B0C = DAT_004A2B18;
            return;
        }
        if (graphicsMode == DAT_00460678) {
            DAT_004A2B0C = DAT_004A2B18;
            DAT_004A2B10 = DAT_004A2B14;
            return;
        }
    }
    DAT_0046A5A1 = (unsigned char)((graphicsMode >> 7) & 0xf8);
    DAT_0046A5A3 = (unsigned char)(graphicsMode << 3);
    DAT_0046A5A2 = (unsigned char)((graphicsMode >> 2) & 0xf8);
    DAT_0046A5FD = DAT_0046A5A3;
    DAT_0046A5FE = DAT_0046A5A2;
    DAT_0046A5FF = DAT_0046A5A1;
    DAT_00460678 = graphicsMode;
    DAT_00460674 = 0;
    DAT_004A2B0C = DAT_004A2B18;
    DAT_004A2B10 = DAT_004A2B14;
}
}
