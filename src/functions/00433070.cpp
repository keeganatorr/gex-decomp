struct GXObject {
    char pad0[0xbc];
    unsigned int gob_pixc;
    void *gob_plut;
};

extern "C" void GOB_DisplayObjectScaleAndRotate_00441150(struct GXObject *);

extern "C" void __cdecl GEX_Target(struct GXObject *param_1) {
    GOB_DisplayObjectScaleAndRotate_00441150(param_1);
    unsigned int uVar1 = param_1->gob_pixc;
    param_1->gob_pixc = 0x1f801f80;
    void *pvVar2 = param_1->gob_plut;
    param_1->gob_plut = (void *)0x45b2e4;
    GOB_DisplayObjectScaleAndRotate_00441150(param_1);
    param_1->gob_pixc = uVar1;
    param_1->gob_plut = pvVar2;
}
