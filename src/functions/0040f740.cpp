typedef struct InputPlayback {
    int playing;       /* 0x0c */
    int length;        /* 0x10 */
    void *buffer;      /* 0x14 */
    int position;      /* 0x18 */
} InputPlayback;
typedef struct InputRecord {
    int unk0, unk4, unk8;
    InputPlayback playback;
    int unk1c, unk20;
} InputRecord;
extern "C" {
extern InputRecord *gInputRecords_004a27dc;
void __cdecl GEX_Target(int player, void *buffer, int length)
{
    InputPlayback *p;
    p = &gInputRecords_004a27dc[player].playback;
    p->buffer = buffer;
    p->length = length;
    p->position = 0;
    p->playing = 1;
}
}
