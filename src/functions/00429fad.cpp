struct MapFunkUnk
{
    char  pad_00[0x70];
    int   field_70;      /* offset 0x70 */
    char  pad_74[0x40];  /* 0x74 .. 0xb3 */
    void *field_b4;      /* offset 0xb4 */
};

extern "C" int   FUN_0042a630_Gex_Frames(void *obj);
extern "C" int   gShowMapTutorials_004a0210;
extern "C" int   INT_ARRAY_ARRAY_00463b10[6][2];
extern "C" char *STRING_CHOOSEREMOTEANDPRESSJUMP_0048a020;
extern "C" void  HelpBoxNew_0040d5f0(int a, int b, char *s, int c);

/* Free function with C linkage: the object-level symbol emitted for the
   identifier FUN_00429fad_MapFunkUnk is FUN_00429fad_MapFunkUnk, which is the contract target. */
extern "C" void FUN_00429fad_MapFunkUnk(MapFunkUnk *self)
{
    if (FUN_0042a630_Gex_Frames(self) == 0)
        return;

    if (self->field_b4 != 0
        && INT_ARRAY_ARRAY_00463b10[6][0] == 0
        && gShowMapTutorials_004a0210 != 0)
    {
        INT_ARRAY_ARRAY_00463b10[6][0] = 1;
        HelpBoxNew_0040d5f0(0xa00000, 0x6e0000,
                            STRING_CHOOSEREMOTEANDPRESSJUMP_0048a020, 2);
    }

    self->field_70 = 2;
}
