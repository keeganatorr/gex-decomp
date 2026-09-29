// Partial 32-bit field view; no claim that the full GXObject layout is recovered.
extern "C" unsigned int GEX_pGlob_004a2ad4;
extern "C" int debugLevel_00455c54;
extern "C" const char* stateNames_00457648[];
extern "C" const char stateTraceFormat_0045aad8[];
extern "C" void __cdecl TracePrintf_00405390(const char*, ...);
extern "C" void __cdecl GOB_ResetState_00420bc0(unsigned int* object)
{
    object[3] = GEX_pGlob_004a2ad4;
    object[0x39] = 0;
    object[0x3a] = 0;
    object[0x3b] = 0;
    object[0x3c] = 0;
    if (debugLevel_00455c54 > 2)
        TracePrintf_00405390(stateTraceFormat_0045aad8, stateNames_00457648[object[0x1c]]);
}
