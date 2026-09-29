// Ghidra SCRIPT_UnforceVoiceSituation_00418e20: call voice reset, preserve the argument.
// This candidate exercises a REL32 call relocation, not a wildcard-masked comparison.
extern "C" void __cdecl VSIT_UnforceVoiceSituation_0041fbc0(void);
extern "C" unsigned __cdecl SCRIPT_UnforceVoiceSituation_00418e20(unsigned value)
{
    VSIT_UnforceVoiceSituation_0041fbc0();
    return value;
}
