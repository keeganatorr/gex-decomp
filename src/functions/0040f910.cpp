// Adapted from pc_decomp_backup/src/functions/FUN_0040F910.cpp
// Historical source SHA256: 920abb08d51712544744c7ea56b234bc159917cfd8964878b93e119816aec63c
extern "C" {
typedef void (__cdecl *ObjectCallback)(unsigned int*, int*);

extern "C" void __cdecl OBI_IntroduceObjects_0040f910(int* objectSet, int cameraX, int cameraY, int initialize)
{
    unsigned int* objects = (unsigned int*)objectSet[0];
    int radius = objectSet[13];
    int left = cameraX - radius;
    int right = cameraX + objectSet[11] + radius;
    int top = cameraY - radius;
    int bottom = cameraY + objectSet[12] + radius;
    int deltaX = cameraX - objectSet[9];
    int last = objectSet[2] - 1;
    int deltaY = cameraY - objectSet[10];
    ObjectCallback callback = (ObjectCallback)objectSet[1];

    if (initialize != 0) {
        unsigned int value = objects[0];
        unsigned int* object = objects;
        int index;
        for (index = 0; ((int)(value & 0xffff0000) < left && index != last); ++index) {
            value = object[4];
            object += 4;
        }
        objectSet[5] = index < 1 ? index : index - 1;
        objectSet[6] = index;
        deltaX = 1;

        unsigned int* sorted = objects + 1;
        value = objects[(objects[1] >> 16) * 4];
        for (index = 0; ((int)(value << 16) < top && index != last); ++index) {
            sorted += 4;
            value = objects[((*sorted) >> 16) * 4];
        }
        objectSet[7] = index < 1 ? index : index - 1;
        objectSet[8] = index;
        deltaY = 1;
    }

    if (deltaX < 0) {
        int index = objectSet[5];
        unsigned int* object = objects + index * 4;
        unsigned int value = *object;
        while (left <= (int)(value & 0xffff0000)) {
            if (top <= (int)(value << 16) && (int)(value << 16) <= bottom &&
                (object[1] & 0x8000) == 0) {
                callback(object, objectSet);
            }
            if (index == 0) break;
            --index;
            object -= 4;
            value = *object;
        }
        objectSet[5] = index;

        index = objectSet[6];
        object = objects + index * 4;
        while (right < (int)(*object & 0xffff0000)) {
            if (index == 0) break;
            --index;
            object -= 4;
        }
        if (index < last) ++index;
        objectSet[6] = index;
    } else if (deltaX > 0) {
        int index = objectSet[6];
        unsigned int* object = objects + index * 4;
        unsigned int value = *object;
        while ((int)(value & 0xffff0000) <= right) {
            if (top <= (int)(value << 16) && (int)(value << 16) <= bottom &&
                (object[1] & 0x8000) == 0) {
                callback(object, objectSet);
            }
            if (index == last) break;
            ++index;
            object += 4;
            value = *object;
        }
        objectSet[6] = index;

        index = objectSet[5];
        object = objects + index * 4;
        while ((int)(*object & 0xffff0000) < left) {
            if (index == last) break;
            ++index;
            object += 4;
        }
        if (index != 0) --index;
        objectSet[5] = index;
    }

    if (deltaY < 0) {
        int index = objectSet[7];
        unsigned int* sorted = objects + index * 4 + 1;
        unsigned int objectIndex = *sorted >> 16;
        unsigned int* object = objects + objectIndex * 4;
        unsigned int value = *object;
        while (top <= (int)(value << 16)) {
            if (left <= (int)(value & 0xffff0000) && (int)(value & 0xffff0000) <= right &&
                (object[1] & 0x8000) == 0) {
                callback(object, objectSet);
            }
            if (index == 0) break;
            --index;
            sorted -= 4;
            objectIndex = *sorted >> 16;
            object = objects + objectIndex * 4;
            value = *object;
        }
        objectSet[7] = index;

        index = objectSet[8];
        sorted = objects + index * 4 + 1;
        while (bottom < (int)(objects[(*sorted >> 16) * 4] << 16) && index != 0) {
            --index;
            sorted -= 4;
        }
        objectSet[8] = index;
    } else if (deltaY > 0) {
        int index = objectSet[8];
        unsigned int* sorted = objects + index * 4 + 1;
        unsigned int objectIndex = *sorted >> 16;
        unsigned int* object = objects + objectIndex * 4;
        unsigned int value = *object;
        while ((int)(value << 16) <= bottom) {
            if (left <= (int)(value & 0xffff0000) && (int)(value & 0xffff0000) <= right &&
                (object[1] & 0x8000) == 0) {
                callback(object, objectSet);
            }
            if (index == last) break;
            ++index;
            sorted += 4;
            objectIndex = *sorted >> 16;
            object = objects + objectIndex * 4;
            value = *object;
        }
        objectSet[8] = index;

        index = objectSet[7];
        sorted = objects + index * 4 + 1;
        while ((int)(objects[(*sorted >> 16) * 4] << 16) < top) {
            if (index == last) break;
            ++index;
            sorted += 4;
        }
        if (index != 0) --index;
        objectSet[7] = index;
    }

    objectSet[9] = cameraX;
    objectSet[10] = cameraY;
}
}
