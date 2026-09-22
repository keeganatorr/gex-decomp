extern "C" int TracePrintf_Debug_00405390(const char *fmt, ...);
extern "C" void assertfail_00405350(const char *fmt, ...);

extern "C" void GEX_Target(unsigned int *dataEnd, int *dataStart, int byteSize)
{
    unsigned int *puVar7;
    unsigned int *puVar1;
    unsigned char *pbVar4;
    unsigned char bVar2;
    int uVar5;

    puVar7 = (unsigned int *)(*dataStart + (int)dataStart);
    puVar1 = (unsigned int *)(byteSize + (int)dataEnd);
    pbVar4 = (unsigned char *)(dataStart + 1);

    TracePrintf_Debug_00405390("Unpacking %d bytes, control at %x\n",
                               byteSize, dataStart + 1, puVar7);

    while (dataEnd < puVar1) {
        bVar2 = *pbVar4++;
        if ((bVar2 & 0x80) != 0) {
            uVar5 = bVar2 & 0x7f;
            if (uVar5 == 0)
                uVar5 = 0x80;
            while (uVar5 > 0) {
                *dataEnd++ = *puVar7;
                uVar5--;
            }
            puVar7++;
        } else {
            uVar5 = bVar2 & 0x7f;
            if (uVar5 == 0)
                uVar5 = 0x80;
            while (uVar5 > 0) {
                *dataEnd++ = *puVar7++;
                uVar5--;
            }
        }
    }

    if (dataEnd != puVar1) {
        assertfail_00405350("ERROR: Unpacked from %x, data actually at %x\n",
                            (int)dataStart, dataEnd, puVar1);
        return;
    }
    if ((unsigned char *)(*dataStart + (int)dataStart) < pbVar4 - 1) {
        assertfail_00405350("ERROR: Unpacked from %x, control at %x\n",
                            (int)dataStart, pbVar4,
                            (unsigned char *)(*dataStart + (int)dataStart));
        return;
    }
}
