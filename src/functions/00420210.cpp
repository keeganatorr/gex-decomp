typedef struct Level {
    void *blocks;
} Level;
extern "C" {
extern Level *M1_CurrentLevel_004a2990;
void __cdecl BLOC_LoadBlocks_0040b8c0(void *blocks, int id, int *base, int **list);
void __cdecl BLOC_WaitForBlocksToLoad_0040b940(int **list);
int __cdecl LINK_RESOLVE_0040b390(int base, int offset);
int __cdecl PAR_ResolveParallax_00420190(int base, int offset);

int *__cdecl GEX_Target(int id, int *outBase)
{
    int *list;
    int base;
    int *result;

    BLOC_LoadBlocks_0040b8c0(M1_CurrentLevel_004a2990->blocks, id, &base, &list);
    BLOC_WaitForBlocksToLoad_0040b940(&list);
    list = (int *)LINK_RESOLVE_0040b390(base, *list);
    result = list;
    while (*list) {
        *list = PAR_ResolveParallax_00420190(base, *list);
        list++;
    }
    *outBase = base;
    return result;
}
}
