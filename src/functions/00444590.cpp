// Behavior-focused reconstruction of GOB_DisplayObject from archived source.
// Original translation unit depended on game_types.h and hard-coded addresses;
// this baseline source is self-contained. Exact bytes and behavior remain unproven.
extern "C" int CAMERA_X_004A2974;
extern "C" int CAMERA_Y_004A2988;
extern "C" int FRAME_COUNT_004A2AC8;
extern "C" short CAMERA_DELTA_X_004A2A96;
extern "C" short CAMERA_DELTA_Y_004A2A94;

extern "C" void* __cdecl FUN_0041A500(void**);
extern "C" void __cdecl FUN_0043DC70(char*, short, short, unsigned int, unsigned int, unsigned int, short, short);


extern "C" void __cdecl GOB_DisplayObject_00444590(void** objectPointer)
{
    char* object = (char*)objectPointer;
    char* sprite = (char*)FUN_0041A500(objectPointer);
    if (sprite == 0) {
        return;
    }

    unsigned int objectColour = *(unsigned int*)(object + 0xbc);
    unsigned int objectPalette = *(unsigned int*)(object + 0xc0);
    int screenX = *(int*)(object + 0x78) - CAMERA_X_004A2974;
    int screenY = *(int*)(object + 0x7c) - CAMERA_Y_004A2988;
    short offsetX = 0;
    short offsetY = 0;

    if ((*(unsigned int*)(object + 0xe0) & 0x01000000) == 0 &&
        *(int*)(object + 0x1f4) - FRAME_COUNT_004A2AC8 == -1) {
        int delta = *(int*)(object + 0x78) - *(int*)(object + 0x1f8);
        if (delta < 0) {
            delta += 0x10000;
        }
        offsetX = (short)(delta >> 17) - CAMERA_DELTA_X_004A2A96;

        delta = *(int*)(object + 0x7c) - *(int*)(object + 0x1fc);
        if (delta < 0) {
            delta += 0x10000;
        }
        offsetY = (short)(delta >> 17) - CAMERA_DELTA_Y_004A2A94;

        int absX = offsetX < 0 ? -offsetX : offsetX;
        int absY = offsetY < 0 ? -offsetY : offsetY;
        if (absX + absY >= 0x65) {
            offsetX = 0;
            offsetY = 0;
        }
    }

    unsigned int** celList = *(unsigned int***)(sprite + 0x18);
    for (;;) {
        unsigned int* celEntry = *celList++;
        if (celEntry == 0) {
            return;
        }

        int* cel = (int*)celEntry[2];
        unsigned int celFlags = celEntry[1];
        int width = cel[0];
        int height = cel[1];
        if ((short)cel[5] == 0) {
            continue;
        }

        unsigned int packedOffset = celEntry[0];
        int x = (celFlags & 0x80000000) == 0 ? cel[2] : width - cel[2];
        if ((*(unsigned int*)(object + 0x6c) & 0x80000000) == 0) {
            x += (packedOffset & 0xffff0000) + screenX;
        } else {
            x = (screenX - x) - (packedOffset & 0xffff0000);
        }

        unsigned int combinedFlags = *(unsigned int*)(object + 0x6c) ^ celFlags;
        int clippedX;
        if ((combinedFlags & 0x80000000) == 0) {
            clippedX = x;
            if (width + x < 0) {
                continue;
            }
        } else {
            if (x < 0) {
                continue;
            }
            clippedX = x - width;
        }
        if (clippedX >= 0x1400000) {
            continue;
        }

        int y = (celFlags & 0x40000000) == 0 ? cel[3] : height - cel[3];
        if ((*(unsigned int*)(object + 0x6c) & 0x40000000) == 0) {
            y += packedOffset * 0x10000 + screenY;
        } else {
            y = (screenY - y) + packedOffset * -0x10000;
        }

        int clippedY;
        if ((combinedFlags & 0x40000000) == 0) {
            clippedY = y;
            if (height + y < 0) {
                continue;
            }
        } else {
            if (y < 0) {
                continue;
            }
            clippedY = y - height;
        }
        if (clippedY >= 0x0f00000) {
            continue;
        }

        unsigned int palette = objectColour != 0 ? objectColour : celEntry[4];
        unsigned int colour = objectPalette != 0 ? objectPalette : celEntry[3];
        FUN_0043DC70((char*)cel, (short)((unsigned int)x >> 16), (short)((unsigned int)y >> 16),
                     colour, palette, combinedFlags, offsetX, offsetY);
    }
}
