struct GEX_Capture
{
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
};

unsigned int DAT_00461404;

extern "C" void _GEX_Target(int value)
{
    GEX_Capture *base = (GEX_Capture *)((unsigned int)&DAT_00461404 - 8u);
    base->field_08 = (unsigned int)value;
}
