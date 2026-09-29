// Adapted from pc_decomp_backup/src/functions/FUN_0041F2D0.cpp
// Historical source SHA256: 5498e3dda0312fbf71883a9bea93b68776b86d7878684cd80bb07ef2dfd56433
// Behavior candidate; original bytes are not claimed to match.
extern "C" unsigned int __cdecl LINK_RESOLVE_0040b390(int, unsigned int);
extern "C" unsigned int* __cdecl GOB_ResolveLoadObject_0040eb70(int, unsigned int);
extern "C" void __cdecl RM_ExtraResolve_00440750(void*);
extern "C" void __cdecl TracePrintf_Debug_00405390(const char*, ...);
extern "C" void __cdecl _exit_00449780(int);

static unsigned int Resolve(int base, unsigned int reference)
{
    return LINK_RESOLVE_0040b390(base, reference);
}

extern "C" void __cdecl M1_ResolveMap_0041f2d0(int* level)
{
    int base = level[2];
    int* tileTable = (int*)0x004A02F0;
    int* tileLists = (int*)0x00463740;
    int* clear;
    int count;

    for (clear = tileTable; clear < (int*)0x004A23C0; clear += 3) {
        *clear = 0;
    }
    for (clear = tileLists, count = 0x40; count != 0; --count, ++clear) {
        *clear = 0;
    }

    unsigned int root = Resolve(base, *(unsigned int*)level[1]);
    level[1] = root;

    unsigned int* grid = (unsigned int*)(root + 0x2c);
    for (count = *(int*)(root + 0x0c) * *(int*)(root + 0x10);
         count != 0; --count, ++grid) {
        if (*grid != 0) {
            unsigned int tile = Resolve(base, *grid);
            *grid = tile;
            *(unsigned int*)(tile + 4) = Resolve(base, *(unsigned int*)(tile + 4));
        }
    }

    unsigned int* groups = (unsigned int*)Resolve(base, *(unsigned int*)(root + 0x24));
    *(unsigned int*)(root + 0x24) = (unsigned int)groups;
    while (*groups != 0) {
        int* group = (int*)Resolve(base, *groups);
        *groups = (unsigned int)group;
        int* entry = group + 1;
        for (count = *group; count != 0; --count, entry += 4) {
            unsigned int* strings = (unsigned int*)Resolve(base, entry[3]);
            entry[3] = (int)strings;
            while (*strings != 0) {
                if ((*strings & 0x80000000) != 0) {
                    strings[1] = Resolve(base, strings[1]);
                }
                strings += 2;
            }
        }
        ++groups;
    }

    unsigned int chain = Resolve(base, *(unsigned int*)(root + 0x1c));
    level[3] = chain;
    unsigned int* link = (unsigned int*)(chain + 4);
    while (*link != 0) {
        *link = Resolve(base, *link);
        ++link;
    }

    unsigned int* pair = (unsigned int*)Resolve(base, *(unsigned int*)(root + 0x18));
    level[5] = Resolve(base, pair[0]);
    level[7] = Resolve(base, pair[1]);

    link = (unsigned int*)level[5];
    while (*link != 0) {
        *link = Resolve(base, *link);
        ++link;
    }
    link = (unsigned int*)level[7];
    while (*link != 0) {
        *link = Resolve(base, *link);
        link += 5;
    }

    groups = (unsigned int*)Resolve(base, *(unsigned int*)(root + 0x28));
    if (*groups != 0) {
        int* listSlot = tileLists;
        do {
            unsigned int* table = (unsigned int*)Resolve(base, *groups);
            unsigned int* tile = table + 1;
            *listSlot = Resolve(base, *table);

            while ((int)*tile > 0) {
                unsigned int tileNumber = *tile;
                if (tileNumber > 699) {
                    TracePrintf_Debug_00405390((const char*)0x00459880, tileNumber, 700);
                    _exit_00449780(10);
                }
                if (tileTable[tileNumber * 3] != 0) {
                    TracePrintf_Debug_00405390((const char*)0x0045985C, tileNumber);
                }
                tileTable[tileNumber * 3] = Resolve(base, tile[1]);
                tileTable[tileNumber * 3 + 1] = Resolve(base, tile[2]) + 4;
                tileTable[tileNumber * 3 + 2] = tile[3];
                RM_ExtraResolve_00440750((void*)tileTable[tileNumber * 3]);
                tile += 4;
            }

            tile = (unsigned int*)*listSlot;
            while (*tile != 0) {
                unsigned int* row = (unsigned int*)Resolve(base, *tile);
                *tile = (unsigned int)row;
                while (*row != 0) {
                    *row = Resolve(base, *row);
                    row[1] = Resolve(base, row[1]) + 4;
                    row += 3;
                }
                tile += 5;
            }

            ++groups;
            ++listSlot;
        } while (*groups != 0);
    }

    groups = (unsigned int*)Resolve(base, *(unsigned int*)(root + 0x20));
    *(unsigned int*)(root + 0x20) = (unsigned int)groups;
    while (*groups != 0) {
        unsigned int* objects = (unsigned int*)Resolve(base, *groups);
        *groups = (unsigned int)objects;
        while (*objects != 0) {
            *objects = (unsigned int)GOB_ResolveLoadObject_0040eb70(base, *objects);
            unsigned int* strings = (unsigned int*)Resolve(base, objects[1]);
            objects[1] = (unsigned int)strings;
            while (*strings != 0) {
                if ((*strings & 0x80000000) != 0) {
                    strings[1] = Resolve(base, strings[1]);
                }
                strings += 2;
            }
            objects += 2;
        }
        ++groups;
    }

    *(int*)0x004A2934 = **(int**)(root + 0x20);
}
