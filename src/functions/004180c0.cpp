struct GXObject {
    char pad[0x15c];
    GXObject* field_15c;
    GXObject* field_160;
    GXObject* field_164;
};

extern "C" void GOB_Remove_00419a80(GXObject*);
extern "C" void TracePrintf_Debug_00405390(const char*);
extern "C" int DAT_00455c54_DebugVar;
extern "C" const char s_REMOVING_OBJECT_00458e28[];

extern "C" int __cdecl SCRIPT_RemoveObject_004180c0(int param_1, GXObject* param_2)
{
    GXObject* pGVar1;
    GXObject* pGVar2;

    pGVar2 = param_2->field_15c;
    if (pGVar2 != 0) {
        pGVar1 = pGVar2->field_160;
        if (param_2 == pGVar1) {
            pGVar2->field_160 = param_2->field_164;
        } else {
            pGVar2 = pGVar1->field_164;
            while (pGVar2 != param_2) {
                pGVar1 = pGVar1->field_164;
                pGVar2 = pGVar1->field_164;
            }
            pGVar1->field_164 = param_2->field_164;
        }
        param_2->field_15c = 0;
        param_2->field_164 = 0;
    }
    pGVar2 = param_2->field_160;
    if (pGVar2 != 0) {
        do {
            pGVar2->field_15c = 0;
            pGVar2 = pGVar2->field_164;
        } while (pGVar2 != 0);
        param_2->field_160 = 0;
    }
    GOB_Remove_00419a80(param_2);
    if (DAT_00455c54_DebugVar > 1) {
        TracePrintf_Debug_00405390(s_REMOVING_OBJECT_00458e28);
    }
    return param_1;
}
