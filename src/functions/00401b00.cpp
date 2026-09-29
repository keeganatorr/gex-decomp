extern "C" {
extern int DAT_00455C0C;
extern int DAT_004A2A0C;
extern int DAT_0048A048;
extern int DAT_0049A068;
extern int DAT_0049A054;

int __cdecl VFX_IsPlaying_00401b00()
{
    return !DAT_00455C0C || DAT_004A2A0C || DAT_0048A048 || (!DAT_0049A068 && !DAT_0049A054);
}
}
