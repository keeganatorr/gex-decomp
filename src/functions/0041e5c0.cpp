// Adapted from pc_decomp_backup/src/functions/FUN_0041E5C0.cpp
// Historical source SHA256: cd0763049599b0971ae52475a00e86e0eb06310cbd61dfbc38b144bced074351
extern "C" {
extern "C" void __cdecl FUN_0041E700(void);
extern "C" void __cdecl FUN_0041E710(void);
extern "C" void __cdecl FUN_0041E720(int, int**);
extern "C" void __cdecl FUN_0042CBF0(int*);
extern "C" void __cdecl FUN_0042CC00(int*, int*);
extern "C" int* __cdecl FUN_0042CC20(int*);
extern "C" void __cdecl FUN_00405350(const char*, ...);

extern "C" void __cdecl GEX_Target(void)
{
    FUN_0041E700();
    *(int*)0x00463734 = 0;
    *(int*)0x0046368C = 0;
    *(int*)0x00463690 = 0;
    *(int*)0x00463738 = 0;

    int* node;
    while ((node = FUN_0042CC20((int*)0x00463680)) != 0) {
        int object = node[2];
        if (object == 0) {
            FUN_0042CBF0(node);
            FUN_0042CC00((int*)0x00463728, node);
            --*(int*)0x004A23C0;
        } else {
            if ((*(unsigned int*)(object + 0x6C) & 0x100000) != 0)
                FUN_00405350((const char*)0x00459598, *(int*)(object + 8));
            unsigned int list = (*(unsigned int*)(object + 0x6C) & 0xF00) >> 8;
            FUN_0042CC00((int*)(0x00463698 + list * 12), node);
        }
    }

    for (int list = 0, listHead = 0x00463698;
         listHead <= 0x0046371C;
         ++list, listHead += 12) {
        node = *(int**)listHead;
        while (*node != 0) {
            int* next = (int*)node[0];
            int object = node[2];
            if (object == 0) {
                FUN_0042CBF0(node);
                FUN_0042CC00((int*)0x00463728, node);
                --*(int*)0x004A23C0;
            } else {
                if ((*(unsigned int*)(object + 0x6C) & 0x100000) != 0)
                    FUN_00405350((const char*)0x00459528, *(int*)(object + 8));
                FUN_0041E720(list, (int**)node);
            }
            node = next;
        }
        int freeList = *(int*)0x00463730;
        if (freeList != 0 && *(int*)freeList == (int)node) {
            FUN_00405350((const char*)0x00459568, list);
        }
    }
    FUN_0041E710();
}
}
