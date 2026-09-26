extern "C" int __cdecl FUN_0040FCE0(int *);
extern "C" int DAT_0045907c;
extern "C" void __cdecl FUN_0041A340(int *, int);
extern "C" int * __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419B80(int *, int);

extern "C" void __cdecl FUN_0041A810();
extern "C" int DAT_0046359c;
extern "C" unsigned char DAT_004A2710[];
extern "C" int DAT_004A2A98;

extern "C" void __cdecl GEX_Target(int *object)
{
    int value;
    int *created;

    if (FUN_0040FCE0(object) == 0) {
        switch (object[0x26]) {
        case 1:
            value = object[0x27] + 1;
            object[0x27] = value;
            if (value <= DAT_0045907c)
                break;

            object[0x27] = 0;
            value = object[0x15] + 1;
            object[0x15] = value;
            if (value <= 7)
                break;

            object[0x26] = 10;
            object[0x14] = 1;
            object[0x15] = 0;
            return;

        case 2:
            if (DAT_0046359c != 0)
                break;

            value = object[0x29];
            if (value == 0) {
                value++;
                object[0x29] = value;
                FUN_0041A340(object, 0xc4);
            }

            value = object[0x27] + 1;
            object[0x27] = value;
            if (value <= DAT_0045907c)
                break;

            object[0x27] = 0;
            value = object[0x15] + 1;
            object[0x15] = value;
            if (value <= 8)
                break;

            object[0x26] = 3;
            object[0x15] = 0;
            object[0x14] = 2;
            return;

        case 3:
            if ((int)DAT_004A2710[DAT_004A2A98] == object[0x2d])
                break;

            object[0x26] = 0;
            object[0x15] = 0;
            object[0x14] = 0;
            return;

        case 10:
            value = object[0x27] + 1;
            object[0x27] = value;
            if (value <= DAT_0045907c)
                break;

            object[0x27] = 0;
            value = object[0x15] + 1;
            object[0x15] = value;
            if (value != 2)
                break;

            object[0x26] = 2;
            created = FUN_004195D0(0x5c, object[0x1e], object[0x1f], object[3]);
            if (created != 0) {
                created[0x18] = (int)FUN_0041A810;
                created[0x14] = 3;
                FUN_00419B80(created, 9);
                DAT_0046359c = 1;
                object[0x26] = 2;
                FUN_0041A340(object, 0xc3);
            }
            break;
        }
    }
}
