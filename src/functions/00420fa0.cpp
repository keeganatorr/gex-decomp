struct GXObject {
    unsigned char reserved[0x78];
    long xpos;
    long ypos;
};

extern "C" {
extern unsigned long DAT_00463ab0;
extern GXObject *DAT_00463ac4;
extern long DAT_00463ad4;
extern unsigned long DAT_004A2990;
extern unsigned long DAT_004A2AC8;

unsigned long __cdecl FUN_0040F170(unsigned long, long, long);
void __cdecl FUN_0041F8C0(long);
void __cdecl FUN_0041FA80(long);
void __cdecl FUN_00420f30(GXObject *);

inline long __cdecl FUN_00420fa0_xpos_movement(GXObject *param_1)
{
    unsigned long attribute;

    if ((DAT_004A2AC8 != DAT_00463ab0) ||
        (DAT_00463ac4 != param_1)) {
        DAT_00463ac4 = param_1;
        DAT_00463ab0 = DAT_004A2AC8;

        attribute = FUN_0040F170(DAT_004A2990,
                                 param_1->xpos,
                                 param_1->ypos);

        switch (attribute) {
        case 0x2d:
            if ((DAT_004A2AC8 & 0x3f) == 0)
                FUN_0041F8C0(0x3d);
            FUN_0041FA80(0x3d);
            param_1->xpos -= 0x30000;
            DAT_00463ad4 = 1;
            break;

        case 0x2e:
            if ((DAT_004A2AC8 & 0x3f) == 0)
                FUN_0041F8C0(0x3d);
            FUN_0041FA80(0x3d);
            param_1->xpos += 0x30000;
            DAT_00463ad4 = 1;
            break;

        case 0x54:
            FUN_0041FA80(0x19);
            param_1->xpos -= 0x10000;
            FUN_00420f30(param_1);
            DAT_00463ad4 = 1;
            break;

        case 0x55:
            FUN_0041FA80(0x19);
            FUN_00420f30(param_1);
            param_1->xpos += 0x10000;
            DAT_00463ad4 = 1;
            break;

        default:
            DAT_00463ad4 = 0;
            break;
        }
    }

    return DAT_00463ad4;
}
}

typedef long (__cdecl *FUN_00420fa0_xpos_movementPointer)(GXObject *);
static FUN_00420fa0_xpos_movementPointer volatile FUN_00420fa0_xpos_movementReference = FUN_00420fa0_xpos_movement;
