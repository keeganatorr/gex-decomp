extern "C" {
int __cdecl CLD_ComputeAngleEdges_0041cb80(void *, int *);
extern unsigned char IMAGE_DOS_HEADER_00400000[];
extern unsigned char DAT_004a286c[];
extern unsigned char DAT_004a2820[];
extern unsigned char DAT_004a2848[];
extern unsigned char DAT_004a2868[];

void __cdecl GEX_Target(const int *state, void *other)
{
    int edges[10];
    int left, right, bottom, top;
    int x, i;
    int offset;

    if (!CLD_ComputeAngleEdges_0041cb80(other, edges))
        return;

    right = state[0x1e];
    if (((unsigned int)state[0x31] + 0x200000U) & 0x400000U) {
        left = right - 0x180000;
        right += 0x180000;
        top = state[0x1f];
        bottom = top - 0x100000;
        top += 0x100000;
    } else {
        left = right - 0x100000;
        right += 0x100000;
        top = state[0x1f];
        bottom = top - 0x180000;
        top += 0x180000;
    }

    offset = ((const int *)(IMAGE_DOS_HEADER_00400000 + 0x56f40))[state[0x1c]];
    bottom = bottom + offset - 0x200000;
    top = top + offset - 0x200000;

    i = 0;
    x = left;
    for (;;) {
        if (edges[6] <= x && x <= edges[7]) {
            if (edges[8] <= bottom && bottom <= edges[9])
                DAT_004a286c[i] = 1;
            if (edges[8] <= top && top <= edges[9])
                DAT_004a2820[i] = 1;
        }
        if (x == right)
            break;
        ++i;
        x += 0x100000;
        if (x > right)
            x = right;
    }

    i = 0;
    for (;;) {
        if (edges[8] <= bottom && bottom <= edges[9]) {
            if (edges[6] <= left && left <= edges[7])
                DAT_004a2848[i] = 1;
            if (edges[6] <= right && right <= edges[7])
                DAT_004a2868[i] = 1;
        }
        if (bottom == top)
            break;
        ++i;
        bottom += 0x100000;
        if (bottom > top)
            bottom = top;
    }
}
}
