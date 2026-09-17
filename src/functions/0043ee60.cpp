extern "C" {

struct DrawCacheEntry {
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
};

extern DrawCacheEntry DrawCacheEntry_ARRAY_00464e58[];
extern DrawCacheEntry DrawCacheEntry_ARRAY_00465370[];

void __cdecl GEX_Target(char *param_1)
{
    short sVar1 = *(short *)(param_1 - 2);
    DrawCacheEntry *ppDVar2;

    param_1 -= 4;

    if (sVar1 >= 0) {
        if (*param_1 != 0) {
            ppDVar2 = &DrawCacheEntry_ARRAY_00464e58[sVar1];
        }
        else {
            ppDVar2 = &DrawCacheEntry_ARRAY_00465370[sVar1];
        }
        ppDVar2->field2 = 0;
        *(short *)(param_1 + 2) = -1;
    }
}

}
