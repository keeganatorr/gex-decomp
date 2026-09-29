typedef struct WallCollisionStruct { unsigned short id; short unk2; int unk4; int unk8; int unkC; } WallCollisionStruct;
typedef struct BlockAnim {
    WallCollisionStruct *frames;  /* 0x0: ends with id == -1 */
    int tile;                     /* 0x4: table index << 5 | entry */
    int frame;                    /* 0x8 */
    int time;                     /* 0xc */
    int speed;                    /* 0x10 */
} BlockAnim;
typedef struct GexTileStruct {
    unsigned char unk0[0x14];
    WallCollisionStruct **tileData;  /* 0x14 */
    int unk18;
    BlockAnim *anims;                /* 0x1c */
} GexTileStruct;
extern "C" {
void __cdecl M1_ProcessBlockAnims_0041f710(GexTileStruct *level)
{
    BlockAnim *anim;
    WallCollisionStruct *frame;
    for (anim = level->anims; anim->frames; anim++) {
        anim->time += anim->speed;
        if (anim->time > 0x10000) {
            anim->time -= 0x10000;
            frame = &anim->frames[++anim->frame];
            if (frame->id == 0xffff) {
                anim->frame = 0;
                frame = anim->frames;
            }
            level->tileData[anim->tile >> 5][anim->tile & 0x1f] = *frame;
        }
    }
}
}
