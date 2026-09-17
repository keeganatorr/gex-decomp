struct GXObject;

extern "C" void __cdecl GOB_ResetState_00420bc0(GXObject **);
extern "C" void __cdecl PlayerRun_004249e0(GXObject **);

extern "C" void __cdecl GEX_Target(GXObject **GexStruct)
{
    GOB_ResetState_00420bc0(GexStruct);
    GexStruct[0x15] = 0;
    GexStruct[0x26] = 0;
    GexStruct[0x1c] = (GXObject *)0x16;
    GexStruct[0x14] = (GXObject *)0x26;
    GexStruct[0x21] = (GXObject *)0x90000;
    PlayerRun_004249e0(GexStruct);
}
