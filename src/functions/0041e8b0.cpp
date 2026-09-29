extern "C" {
    extern int DAT_004A23C0;
    void __cdecl FUN_00405350(const char*, ...);
    void __cdecl FUN_0042CBF0(void*);
    void __cdecl FUN_0042CC00(void*, void*);

    struct GXType {
        int pad0;
        int pad4;
        int id;
        char pad[0x6c - 12];
        unsigned int flags;
    };

    struct GXObject {
        GXObject* next;
        int pad;
        GXType* gob_type;
    };

    struct FreeList {
        int field0;
        int field1;
        GXObject** field2;
    };

    extern FreeList DAT_00463728;
}

extern "C" void __cdecl CLD_FreeAllRemovedCldObjectsFromList_0041e8b0(GXObject** list, int param_2)
{
    GXObject* node = *list;
    if (node->next != 0) {
        GXObject* next;
        do {
            next = node->next;
            GXType* type = node->gob_type;
            if (type == 0) {
                FUN_0042CBF0(node);
                FUN_0042CC00(&DAT_00463728, node);
                DAT_004A23C0 = DAT_004A23C0 - 1;
            } else if ((type->flags & 0x100000) != 0) {
                FUN_00405350((const char*)0x00459528, type->id);
            }
            node = next;
        } while (next->next != 0);
    }
    if (*DAT_00463728.field2 == node) {
        FUN_00405350((const char*)0x00459568, param_2);
    }
}
