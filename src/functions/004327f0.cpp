struct GXObject {
    unsigned char unknown_000[0x0c];
    GXObject **global;
    unsigned char unknown_010[0x40];
    int field_050;
    int field_054;
    unsigned char unknown_058[0x14];
    int field_06c;
    unsigned char unknown_070[8];
    int gob_xpos;
    int gob_ypos;
    unsigned char unknown_080[0x18];
    int gob_work0;
    int gob_work1;
    int gob_work2;
    unsigned char unknown_0a4[4];
    int gob_work4;
    int gob_work5;
    unsigned char unknown_0b0[0x0c];
    unsigned int field_0bc;
    void *gob_plut;
    int field_0c4;
    int field_0c8;
    int field_0cc;
    unsigned char unknown_0d0[0x134];
};

extern "C" {
extern GXObject ** volatile GEX_pGlob_004a2ad4;
int __cdecl UTL_ReallyRandom_00428c80(int);
void __cdecl GOB_DisplayObject_00444590(GXObject *);
void __cdecl GOB_DisplayObjectScaleAndRotate_00441150(GXObject *);
void __cdecl GOB_ResetPos_004317e0(GXObject *);
void __cdecl RezOutAll_00437330(GXObject *);

void __cdecl GEX_Target(GXObject *object)
{
    GXObject local;
    int remaining;
    int y_offset;
    int y_position;
    int work0;

    if (object->gob_work1 < 0) {
        object->gob_work1 = UTL_ReallyRandom_00428c80(4);
        object->gob_work0 = (object->gob_work0 == 0);
    } else {
        object->gob_work1 = object->gob_work1 - 1;
    }

    local.gob_xpos = object->gob_work4 + object->gob_xpos;
    y_offset = ((volatile GXObject *)object)->gob_work5;
    local.field_054 = 0;
    local.field_050 = 30;
    y_position = object->gob_ypos + y_offset;
    local.field_06c = 0;
    ((volatile GXObject *)&local)->gob_ypos = y_position;
    ((volatile GXObject *)&local)->field_0c4 = 0;
    local.global = GEX_pGlob_004a2ad4;
    work0 = object->gob_work0;
    local.field_0bc = 0x1f801f00;
    local.gob_plut = (void *)0x0045b21c;
    local.field_0c8 = 0x10000;
    local.field_0cc = 0x10000;
    if (work0 == 0) {
        local.gob_plut = (void *)0x0045b244;
    }
    GOB_DisplayObject_00444590(&local);

    if ((object->gob_work2 & 3U) == 0) {
        object->gob_plut = 0;
    } else {
        object->gob_plut = (void *)0x0045b244;
        if (object->gob_work0 == 0) {
            object->gob_plut = (void *)0x0045b21c;
        }
    }
    GOB_DisplayObjectScaleAndRotate_00441150(object);
    remaining = object->gob_work2 - 1;
    object->gob_work2 = remaining;
    if (remaining <= 0) {
        GOB_ResetPos_004317e0(object);
        RezOutAll_00437330(object);
    }
}
}
