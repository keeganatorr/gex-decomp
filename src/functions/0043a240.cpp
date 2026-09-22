struct GXObject;
typedef void (__cdecl *GXObjectCallback)(GXObject *);

struct GXObject {
    char pad_00[0x0c];
    int field_0c;
    char pad_10[0x40];
    int field_50;
    int field_54;
    char pad_58[0x04];
    GXObjectCallback field_5c;
    GXObjectCallback field_60;
    GXObjectCallback field_64;
    char pad_68[0x10];
    int field_78;
    int field_7c;
    char pad_80[0x1c];
    int field_9c;
    char pad_a0[0x0c];
    int field_ac;
    char pad_b0[0x0c];
    unsigned int field_bc;
    char pad_c0[0x10];
    unsigned int field_d0;
    char pad_d4[0x0c];
    unsigned int field_e0;
};

extern "C" {
GXObject * __cdecl GOB_AddObject_004195d0(int, int, int, int);
void __cdecl GOB_PutObjectInfrontOfObject_00419be0(GXObject *, GXObject *);
void __cdecl GOB_PutObjectBehindObject_00419bc0(GXObject *, GXObject *);
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *, int);
void __cdecl FUN_004395b0_HuntDiveInner(int, int);
void __cdecl FUN_0043a160(GXObject *);
void __cdecl FUN_0043A1F0(GXObject *);
extern int DAT_00464520;
extern GXObject *PTR_ARRAY_00464610[];
extern GXObject *DAT_00464630;
extern int DAT_004646f0;
extern GXObject *DAT_00464704;
extern GXObject *gPlayerObject_004a27fc;
}

extern "C" void __cdecl GEX_Target(GXObject *param_1)
{
    GXObject **slot;
    int index;
    GXObject *object;

    if (param_1->field_ac == 3) {
        DAT_00464520 = 0;
        param_1->field_60 = 0;
        param_1->field_64 = 0;
        param_1->field_d0 = 0x30000000U;
        index = 0;
        slot = PTR_ARRAY_00464610;

        do {
            object = GOB_AddObject_004195d0(0x13b, param_1->field_78,
                                             param_1->field_7c,
                                             param_1->field_0c);
            if (object != 0) {
                *slot = object;
                object->field_9c = index;
                switch (index) {
                case 0:
                    DAT_00464704 = object;
                    GOB_PutObjectInfrontOfObject_00419be0(object, gPlayerObject_004a27fc);
                    object->field_50 = 4;
                    break;
                case 1:
                    object->field_50 = 2;
                    break;
                case 2:
                    object->field_50 = 6;
                    break;
                case 3:
                case 4:
                    object->field_50 = 1;
                    break;
                case 5:
                case 6:
                    object->field_50 = 0;
                    break;
                case 7:
                    object->field_50 = 5;
                    break;
                }
                object->field_54 = 0;
                object->field_5c = 0;
                if (slot > PTR_ARRAY_00464610)
                    GOB_PutObjectBehindObject_00419bc0(object, slot[-1]);
            }
            ++slot;
            ++index;
        } while (slot < &DAT_00464630);

        FUN_004395b0_HuntDiveInner(param_1->field_78, param_1->field_7c);
        DAT_004646f0 = 3;

        object = GOB_AddObject_004195d0(0x13b, param_1->field_78,
                                         param_1->field_7c,
                                         param_1->field_0c);
        if (object != 0) {
            GOB_PutObjectBehindObject_00419bc0(object, gPlayerObject_004a27fc);
            object->field_d0 = 0x30000000U;
            object->field_5c = 0;
            object->field_64 = 0;
            object->field_60 = FUN_0043a160;
            object->field_bc = 0x82000081U;
            object->field_e0 |= 0x01000000U;
        }

        object = GOB_AddObject_004195d0(0x13b, param_1->field_78,
                                         param_1->field_7c,
                                         param_1->field_0c);
        if (object != 0) {
            GOB_SetObjectDisplayPriority_00419b80(object, 9);
            object->field_d0 = 0x30000000U;
            object->field_5c = FUN_0043A1F0;
            object->field_64 = 0;
            object->field_60 = 0;
        }
    }
}
