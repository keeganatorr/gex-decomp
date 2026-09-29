// The async read callback at 00437f00 marks its request owner complete.
// The 15-byte body was inspected in the pinned PE; Ghidra has no function
// inventory entry for this address.
extern "C" void __cdecl FUN_00437f00(void* request)
{
    void* owner = *(void**)((char*)request + 0x3c);
    *(int*)((char*)owner + 0x58) = 1;
}
