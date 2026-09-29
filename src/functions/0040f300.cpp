struct astruct_28 {
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
};

extern "C" astruct_28 *gInputRecords_004a27dc;

extern "C" void *memset(void *, int, unsigned int);

extern "C" void InitControllers_0040f300(int param_1, astruct_28 *keyInput)
{
    unsigned int size = param_1 * 0x24;
    memset(keyInput, 0, size);
    gInputRecords_004a27dc = keyInput;
    do {
        size -= 0x24;
        *(int *)((char *)gInputRecords_004a27dc + size) = 0;
    } while (size != 0);
}
