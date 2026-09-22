typedef unsigned char byte;
typedef unsigned int uint;

extern "C" int TracePrintf_Debug_00405390(const char *format, ...);

extern "C" void __cdecl _GEX_Target(int *gamePasswordList, int value, uint value2, int numBits)
{
    int iVar1;
    int iVar2;
    int iVar3;
    byte *streamValueAddress;

    streamValueAddress = (byte *)((int)gamePasswordList + ((int)(value2 + ((int)value2 >> 0x1f & 7U)) >> 3));
    TracePrintf_Debug_00405390("Put value %d %d %d %2x (addr = %x)\n", value, value2, numBits, (uint)*streamValueAddress, streamValueAddress);
    if (1 << (byte)numBits <= value) {
        TracePrintf_Debug_00405390("Error: numbits %d too small for value %d\n", numBits, value);
    }
    for (; numBits != 0; numBits = numBits - iVar2) {
        iVar1 = 8 - (value2 & 7);
        iVar3 = iVar1 - numBits;
        iVar2 = numBits;
        if (iVar3 < 0) {
            iVar3 = 0;
            iVar2 = iVar1;
        }
        value2 = value2 + iVar2;
        *streamValueAddress = (byte)(*streamValueAddress |
            (byte)((((1 << (byte)iVar2) - 1) & (byte)value) << (byte)iVar3));
        value = value >> (byte)iVar2;
        streamValueAddress = streamValueAddress + 1;
    }
    TracePrintf_Debug_00405390("stream value now = %2x\n", (uint)streamValueAddress[-1]);
}
