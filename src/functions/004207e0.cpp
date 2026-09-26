typedef struct Block { unsigned short a, b, c, attribute; } Block;
typedef struct TileAttribute { unsigned int flags; int rest[7]; } TileAttribute;
extern "C" {
extern void *M1_CurrentLevel_004a2990;
extern TileAttribute DAT_0045B9A0[];
extern Block * __cdecl GOB_GetBlockAddress_00419fe0(void *, int, int);
unsigned int __cdecl GEX_Target(int x, int y)
{
    return (DAT_0045B9A0[GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, x, y)->attribute].flags & 0x80000000) != 0;
}
}
