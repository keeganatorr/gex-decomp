typedef struct Glob {
    unsigned int *anims;
    unsigned int *scripts;
    int type;
    int unkC;
    unsigned int numFrames;
} Glob;
typedef struct FrameList {
    int count;
    unsigned int *frames;
} FrameList;
typedef struct Extra {
    int unk0;
    int unk4;
    unsigned int data;
    unsigned int info;
} Extra;
typedef struct Anim {
    unsigned int flags;
    int unk4[3];
    unsigned int f10;
    unsigned int frames;
    unsigned int extras;
    unsigned int f1c;
    unsigned int f20;
} Anim;
extern "C" {
unsigned int __cdecl LINK_RESOLVE_0040b390(int base, unsigned int offset);
void __cdecl TracePrintf_Debug_00405390(char *fmt, ...);
void __cdecl GOB_ExtraResolve_00441010(unsigned int data);
extern char s_Glob____x_004563a4[];
extern char s_anims___scripts____x___x_00456388[];
extern char s_numFrames____x_00456378[];
extern char s_scripts__d_____x_00456364[];
extern char s_gxlob_anims__d_____x_0045634c[];

Glob *__cdecl GEX_Target(int base, unsigned int offset)
{
    Glob *glob;
    unsigned int *entry;
    int k;
    int i;
    int j;
    unsigned int value;
    int m;
    unsigned int *anim;
    unsigned int *first;
    Anim *a;
    FrameList *frames;
    unsigned int *extras;
    Extra *extra;

    glob = (Glob *)LINK_RESOLVE_0040b390(base, offset);
    TracePrintf_Debug_00405390(s_Glob____x_004563a4, glob);
    glob->anims = (unsigned int *)LINK_RESOLVE_0040b390(base, (unsigned int)glob->anims);
    glob->scripts = (unsigned int *)LINK_RESOLVE_0040b390(base, (unsigned int)glob->scripts);
    TracePrintf_Debug_00405390(s_anims___scripts____x___x_00456388, glob->anims, glob->scripts);
    if (glob->type) {
        glob->numFrames = LINK_RESOLVE_0040b390(base, glob->numFrames);
        TracePrintf_Debug_00405390(s_numFrames____x_00456378, glob->numFrames);
    }
    for (i = 0; glob->scripts[i] & 1; i++) {
        glob->scripts[i] = LINK_RESOLVE_0040b390(base, glob->scripts[i]);
        TracePrintf_Debug_00405390(s_scripts__d_____x_00456364, i, glob->scripts[i]);
        value = ((unsigned int *)glob->scripts[i])[0];
        if (value) {
            j = 0;
            do {
                if (value & 0xffff0000)
                    break;
                ((unsigned int *)glob->scripts[i])[j] = value + glob->scripts[i];
                j++;
                value = ((unsigned int *)glob->scripts[i])[j];
            } while (value);
        }
    }
    for (k = 0; glob->anims[k] & 1; k++) {
        glob->anims[k] = LINK_RESOLVE_0040b390(base, glob->anims[k]);
        first = (unsigned int *)glob->anims[k];
        TracePrintf_Debug_00405390(s_gxlob_anims__d_____x_0045634c, k, first);
        if (*first & 1) {
        anim = first;
        do {
            frames = 0;
            extras = 0;
            *anim = LINK_RESOLVE_0040b390(base, *anim);
            a = (Anim *)*anim;
            if ((a->flags & 1) && (a->f1c & 1))
                a->f1c = LINK_RESOLVE_0040b390(base, a->f1c);
            if ((a->flags & 2) && (a->f20 & 1))
                a->f20 = LINK_RESOLVE_0040b390(base, a->f20);
            if (a->frames & 1) {
                a->frames = LINK_RESOLVE_0040b390(base, a->frames);
                frames = (FrameList *)a->frames;
            }
            if (a->f10 & 1)
                a->f10 = LINK_RESOLVE_0040b390(base, a->f10);
            if (a->extras & 1) {
                a->extras = LINK_RESOLVE_0040b390(base, a->extras);
                extras = (unsigned int *)a->extras;
            }
            if (frames && ((unsigned int)frames->frames & 1)) {
                frames->frames = (unsigned int *)LINK_RESOLVE_0040b390(base, (unsigned int)frames->frames);
                for (m = 0; m <= frames->count; m++) {
                    if (frames->frames[m] & 1)
                        frames->frames[m] = LINK_RESOLVE_0040b390(base, frames->frames[m]);
                }
            }
            for (; *extras & 1; extras++) {
                *extras = LINK_RESOLVE_0040b390(base, *extras);
                extra = (Extra *)*extras;
                if (extra->data & 1) {
                    extra->data = LINK_RESOLVE_0040b390(base, extra->data);
                    if (extra->info & 1)
                        extra->info = LINK_RESOLVE_0040b390(base, extra->info) + 4;
                    GOB_ExtraResolve_00441010(extra->data);
                }
            }
            anim++;
        } while (*anim & 1);
        }
    }
    return glob;
}
}
