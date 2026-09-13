// Ghidra FUN_00420D30: decrement the player-bubble counter.
// Candidate only until pc-decomp verifies code and the global relocation destination.
// Unsigned expresses the observed 32-bit wraparound; original source signedness is unknown.
extern "C" unsigned gNumPlayerBubbles_004a2854;
extern "C" void __cdecl GEX_Target(void)
{
    --gNumPlayerBubbles_004a2854;
}
