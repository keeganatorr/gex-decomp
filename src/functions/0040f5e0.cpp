// Input records are 0x24 bytes; only the previous-button field at +8 is established here.
struct InputRecord { unsigned int unknown0, unknown4, previous; unsigned int unknownC[6]; };
extern "C" InputRecord* gInputRecords_004a27dc;
extern "C" unsigned int __cdecl FilterInputForJustOn_0040f5e0(int index, unsigned int buttons)
{
    unsigned int previous = gInputRecords_004a27dc[index].previous;
    gInputRecords_004a27dc[index].previous = buttons;
    return ~previous & buttons;
}
