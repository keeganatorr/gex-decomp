typedef struct TextureCache {
    short packed;           /* 0x0 */
    unsigned char offset;   /* 0x2 */
    unsigned char row;      /* 0x3 */
    union {
        unsigned int texture;                       /* 0x4 */
        struct { unsigned short x; unsigned short y; } pos;
    } u;
} TextureCache;
typedef struct ExtraHeader { short offset; short unk2; int unk4; } ExtraHeader;
typedef struct ExtraObject {
    unsigned char unk0[0x10];
    unsigned char flags;    /* 0x10 */
    unsigned char unk11;
    short cacheSlot;        /* 0x12 */
    ExtraHeader headers[1]; /* 0x14 */
} ExtraObject;
extern "C" {
extern int UINT_0046bcf8;
extern TextureCache *gObjectTextureMap_00460f6c;
extern char s_GOB_ExtraResolve_on_x_00461084[];
extern char s_Setting_up_ot_d_prefix_x_head_00461050[];
extern char s_At_position_d_d_0046103c[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl GEX_Target(ExtraObject *object)
{
    ExtraHeader *header;
    TextureCache *cache;
    unsigned int x;
    unsigned char u;
    int y;
    int bank;
    if (object->cacheSlot < 0 && (object->flags & 0x40)) {
        TracePrintf_Debug_00405390(s_GOB_ExtraResolve_on_x_00461084, object);
        object->cacheSlot = (short)UINT_0046bcf8;
        bank = object->flags & 3;
        header = object->headers;
        if (header->offset) {
            do {
                TracePrintf_Debug_00405390(s_Setting_up_ot_d_prefix_x_head_00461050, UINT_0046bcf8, object, header, header->offset);
                cache = &gObjectTextureMap_00460f6c[UINT_0046bcf8];
                x = cache->u.pos.x;
                y = cache->u.pos.y;
                TracePrintf_Debug_00405390(s_At_position_d_d_0046103c, x, y);
                cache->packed = (short)((cache->u.texture >> 20) & 0x10) | (short)((cache->u.texture >> 6) & 0xf) | (short)(bank << 7);
                cache->row = (unsigned char)y;
                switch (bank) {
                case 1:
                    u = (x & 0x3f) * 2;
                    break;
                case 2:
                    u = x & 0x3f;
                    break;
                default:
                    u = x << 2;
                    break;
                }
                header++;
                cache->offset = u;
                UINT_0046bcf8++;
            } while (header->offset);
        }
    }
}
}
