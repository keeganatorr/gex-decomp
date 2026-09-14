extern "C" {
extern unsigned int DAT_004A2660[6];
void __cdecl GEX_Target(unsigned int value)
{
    int index = 0;
    unsigned int *slot = DAT_004A2660;
    while (slot < DAT_004A2660 + 6) {
        if (*slot == 4) {
            DAT_004A2660[index] = value;
            return;
        }
        slot += 1;
        index += 1;
    }
}
}
