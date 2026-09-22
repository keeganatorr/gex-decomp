extern "C" {
int __cdecl CLD_ComputeAngleEdges_0041cb80(void *, int *);
extern unsigned char IMAGE_DOS_HEADER_00400000[];
extern unsigned char DAT_004a286c[];
extern unsigned char DAT_004a2820[];
extern unsigned char DAT_004a2848[];
extern unsigned char DAT_004a2868[];

void __cdecl GEX_Target(const int *state, void *other)
{
    int offset;
    int finalTop;
    int finalBottom;
    int left;
    int right;
    int cursor;
    int i;
    int upper;
    int edges[10];

    finalBottom = CLD_ComputeAngleEdges_0041cb80(other, edges);
    if (finalBottom == 0)
        return;

    offset = (int)((unsigned int)state[0x31] + 0x200000U);
    right = state[0x1e];
    if ((unsigned int)offset & 0x400000U) {
        left = right - 0x180000;
        right += 0x180000;
        upper = state[0x1f];
        cursor = upper - 0x100000;
        upper += 0x100000;
    } else {
        left = right - 0x100000;
        right += 0x100000;
        upper = state[0x1f];
        cursor = upper - 0x180000;
        upper += 0x180000;
    }

    i = 0;
    offset = ((const int *)(IMAGE_DOS_HEADER_00400000 + 0x56f40))[state[0x1c]];
    finalBottom = cursor + offset - 0x200000;
    finalTop = upper + offset - 0x200000;
    cursor = left;

    for (;;) {
        if (edges[6] <= cursor && cursor <= edges[7]) {
            if (edges[8] <= finalBottom && finalBottom <= edges[9])
                DAT_004a286c[i] = 1;
            if (edges[8] <= finalTop && finalTop <= edges[9])
                DAT_004a2820[i] = 1;
        }
        if (cursor == right)
            break;
        ++i;
        cursor += 0x100000;
        if (right < cursor)
            cursor = right;
    }

    i = 0;
    for (;;) {
        if (edges[8] <= finalBottom && finalBottom <= edges[9]) {
            if (edges[6] <= left && left <= edges[7])
                DAT_004a2848[i] = 1;
            if (edges[6] <= right && right <= edges[7])
                DAT_004a2868[i] = 1;
        }
        if (finalBottom == finalTop)
            break;
        ++i;
        finalBottom += 0x100000;
        if (finalTop < finalBottom)
            finalBottom = finalTop;
    }
}
}
