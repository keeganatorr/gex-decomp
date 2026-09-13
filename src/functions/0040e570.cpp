// Adapted from pc_decomp_backup/src/functions/FUN_0040E570.cpp
// Historical source SHA256: 293b8340d97947385d459a4f5e85f6bd97e793a158cc579a93bbece0fe90b75f
extern "C" {
extern "C" void __cdecl FUN_00444590(int*);
extern "C" { extern int FUN_004A2964; }

extern "C" void __cdecl GEX_Target(int* object)
{
    short* destination = (short*)((char*)object + 0x11E);
    int sourceTable = object[3];
    if (sourceTable == 0) return;
    sourceTable = *(int*)sourceTable;
    if (sourceTable == 0) return;
    sourceTable = *(int*)(sourceTable + object[0x14] * 4);
    if (sourceTable == 0) return;
    sourceTable = *(int*)sourceTable;
    if (sourceTable == 0) return;
    sourceTable = *(int*)(sourceTable + 0x18);
    if (sourceTable == 0) return;
    sourceTable = *(int*)sourceTable;
    if (sourceTable == 0) return;
    short* source = *(short**)(sourceTable + 0x0C);
    if (source == 0) return;

    object[0x46] = 0xFFFFFF00;
    *(short*)((char*)object + 0x11C) = *source;

    if (object[0x26] == 0) {
        for (int column = 0; column < 2; ++column) {
            short last = destination[10];
            destination[10] = destination[8];
            destination[8] = destination[6];
            destination[6] = destination[4];
            destination[4] = destination[2];
            destination[2] = destination[0];
            destination[0] = last;
            ++destination;
        }
    } else {
        object[0x26] = 0;
        for (int index = 0; index < 0x0F; ++index)
            *destination++ = *++source;
    }

    int savedImage = object[0x30];
    int savedY = object[0x1F];
    int savedFlags = object[0x15];
    object[0x30] = (int)((char*)object + 0x11C);
    object[0x1F] = savedY - object[0x27] - 0x80000;
    if (FUN_004A2964 == 0x86)
        object[0x1F] = savedY - object[0x27] - 0x180000;
    object[0x15] = 0;
    object[0x1E] = 0x9F0000;
    FUN_00444590(object);
    object[0x1F] = savedY;
    object[0x15] = savedFlags;
    object[0x30] = savedImage;

    if (object[0x29] != 0)
        object[0x1F] = savedY + object[0x29];
    object[0x27] = (object[0x27] + 0x70000) & 0x3F0000;
}
}
