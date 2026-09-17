extern "C" {
void __cdecl GOB_ResetState_00420bc0(void** p);
void __cdecl PlayerRunTurnStop_00427110(void** p);
void __cdecl GEX_Target(void** p)
{
    GOB_ResetState_00420bc0(p);
    p[0x26] = 0;
    p[0x20] = 0;
    p[0x22] = 0;
    p[0x1c] = (void*)8;
    p[0x14] = (void*)0x3E;
    p[0x15] = (void*)1;
    PlayerRunTurnStop_00427110(p);
}
}
