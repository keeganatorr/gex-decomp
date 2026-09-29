struct CacheSlot {
    CacheSlot *next;
    CacheSlot *prev;
    short *owner;
    unsigned char opaque[8];
};

extern "C" {
extern CacheSlot DrawCacheEntry_ARRAY_00467188[];
extern CacheSlot gpDrawCacheEntries_00465358;
extern unsigned char *PTR_004a2ae4;
extern unsigned char *DAT_004a2adc_Tiles2;
extern unsigned char *DAT_004a2ae0_TilesBack1;
extern const char s_ERROR__empty_image__x_0046011c[];
extern const char s_ERROR__invalid_cache_slot_number_004600f4[];
void __cdecl assertfail_00405350(const char *, ...);
void __cdecl IMG_Unpack_0043e730(void *, const void *, int);
void __cdecl FUN_0043e800_ProcessTileData(CacheSlot *, void *, void *, unsigned int);
void * __cdecl _alloca(unsigned int);
}

extern "C" CacheSlot *__cdecl FUN_0043e580_Image_Clean1(unsigned char *image)
{
    unsigned char * volatile data;
    unsigned char * volatile processed;
    unsigned char *initialData;
    CacheSlot *slot;
    unsigned int format;
    short index;
    int empty;

    _alloca(0);
    initialData = image + 20;
    empty = (*(unsigned short *)initialData == 0);
    data = initialData;
    if (empty)
        assertfail_00405350(s_ERROR__empty_image__x_0046011c, image);

    index = *(short *)(image + 18);
    if (index < -1 || index >= 660)
        assertfail_00405350(s_ERROR__invalid_cache_slot_number_004600f4, (int)index);

    index = *(short *)(image + 18);
    if (index >= 0) {
        slot = &DrawCacheEntry_ARRAY_00467188[index];
        slot->prev->next = slot->next;
        slot->next->prev = slot->prev;
    } else {
        format = image[16] & 3;
        if (image[16] & 4) {
            unsigned char alignedHeight = (unsigned char)((data[2] + 7) & 248);
            int size;
            unsigned char *next;
            unsigned char *unpacked;

            switch (format) {
            case 1:
                size = data[3] * alignedHeight;
                break;
            case 2:
                size = data[3] * alignedHeight * 2;
                break;
            default:
                size = (data[3] * alignedHeight) >> 1;
                break;
            }

            next = PTR_004a2ae4 + size;
            if (DAT_004a2adc_Tiles2 < next) {
                PTR_004a2ae4 = DAT_004a2ae0_TilesBack1 + size;
                unpacked = DAT_004a2ae0_TilesBack1;
            } else {
                PTR_004a2ae4 = next;
                unpacked = next - size;
            }
            processed = unpacked;
            IMG_Unpack_0043e730(processed, data + 16, size);
            processed = processed - 36;
        } else {
            processed = image;
        }

        slot = gpDrawCacheEntries_00465358.prev;
        if (slot->owner != 0)
            *slot->owner = -1;
        gpDrawCacheEntries_00465358.prev = slot->prev;
        slot->prev->next = &gpDrawCacheEntries_00465358;
        slot->owner = (short *)(image + 18);
        *(short *)(image + 18) = (short)(slot - DrawCacheEntry_ARRAY_00467188);
        FUN_0043e800_ProcessTileData(slot, data, processed, format);
    }

    slot->next = gpDrawCacheEntries_00465358.next;
    slot->prev = &gpDrawCacheEntries_00465358;
    slot->next->prev = slot;
    gpDrawCacheEntries_00465358.next = slot;
    return slot;
}
