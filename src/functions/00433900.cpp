typedef int (__cdecl *EventHandler)(void**);

extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void __cdecl FUN_00439090(void**);
extern "C" void __cdecl FUN_004390D0(void**);
extern "C" void* __cdecl FUN_00433590(void**, void*, void*, int);

extern "C" void __cdecl GOB_ProcessEvents_00433900(void** objectType)
{
    if (objectType[0x57] == 0 && FUN_0040FCE0(objectType) != 0) return;

    objectType[0x1b] = (void*)((unsigned)objectType[0x1b] & 0xe0ffffff);
    if ((unsigned)objectType[0x1b] & 0x4000) FUN_00439090(objectType);
    if ((unsigned)objectType[0x1b] & 0x8000) FUN_004390D0(objectType);

    if (objectType[4] != 0) {
        objectType[4] = FUN_00433590(objectType, (void*)(objectType + 4), objectType[4], 0);
    }
    if (objectType[0xc] != 0) {
        objectType[0xc] = FUN_00433590(objectType, (void*)(objectType + 0xc), objectType[0xc], -1);
    }

    int count;
    int* event;
    event = (int*)(objectType + 0x65);
    count = 12;
    do {
        int eventNumber = event[0];
        if (eventNumber != 0) {
            if (((EventHandler*)0x0045f00c)[eventNumber](objectType) != 0) {
                FUN_00433590(objectType, (void*)0x00464258, (void*)event[1], eventNumber);
            }
        }
        event += 2;
        count--;
    } while (count != 0);
}