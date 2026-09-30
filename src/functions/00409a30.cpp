// Adapted from pc_decomp_backup/src/functions/FUN_00409A30.cpp
// Historical source SHA256: af226a878b65e2c2ffe655974066ec0d94b9cac298ca6afbae3d17357e564633
extern "C" {
extern int DAT_00455B38;
extern int DAT_00455B88;
extern int DAT_00455B8C;
extern int DAT_00455B90;
extern int DAT_00455BE4;
extern int DAT_00455C48;
extern int DAT_00456018;
extern int DAT_00458C78;
extern int DAT_00458C7C;
extern int DAT_00458C80;
extern int DAT_00458C84;
extern int DAT_00458C88;
extern int DAT_004593B8;
extern int DAT_004626F0;
extern int DAT_004626F4;
extern int DAT_004A23D0;
extern int DAT_004A23D4;
extern int DAT_004A23D8;
extern int DAT_004A23DC;
extern int DAT_004A2940;
extern int DAT_004A293C;
extern int DAT_004A2948;
extern int DAT_004A2950;
extern int DAT_004A2960;
extern int DAT_004A2974;
extern int DAT_004A2978;
extern int DAT_004A2988;
extern int DAT_004A2990;
extern int DAT_004A2994;
extern int DAT_004A2A04;
extern int DAT_004A2A08;
extern int DAT_004A2A14;
extern int DAT_004A2A1C;
extern int DAT_004A2A20;
extern int DAT_004A2A24;
extern int DAT_004A2A38;
extern int DAT_004A2A40;
extern int DAT_004A2A78;
extern int DAT_004A2A7C;
extern int DAT_004A2A88;
extern int DAT_004A2A90;
extern int DAT_004A2A94;
extern int DAT_004A2A96;
extern int DAT_004A2A98;
extern int DAT_004A2ABC;
extern int DAT_004A2ACC;
extern int DAT_004A2AD0;
extern int DAT_004A2AD4;
extern int DAT_004A2B04;
extern int DAT_004A27FC;
extern int DAT_004A282C;
extern int DAT_004A2830;
extern int DAT_004A288C;
extern int DAT_004A2928;
extern int DAT_004A292C;
extern int DAT_004A2964;
extern int DAT_004A2968;
extern int DAT_004A2AC0;
extern int DAT_004A2AC8;
extern int DAT_004A2A0C;
extern int DAT_00455C28;
extern int DAT_00455C3C;
extern int DAT_00455C4C;
extern int DAT_00456ADC;
extern int DAT_00456AE0;
extern int DAT_00456AEC;
extern int DAT_00456AD8;
extern int DAT_00456AE4;
extern int DAT_00456AF0;
extern int DAT_00456AF4;
extern int DAT_00456AF8;
extern int DAT_00456B04;
extern int DAT_004577B0;
extern int DAT_004A2710;
extern int DAT_004626FC;
extern int DAT_00455B70;
extern int DAT_00455B74;
extern int DAT_004A2924;
extern int DAT_00455CC4;
extern int DAT_00455D54;
extern int DAT_00455D30;
extern int DAT_00455CF4;
extern int DAT_00455D0C;

extern int DAT_004A27BC;
extern int DAT_004A27C0;
extern int DAT_004A27C4;
extern int DAT_004A27C8;
extern int DAT_004A27CC;
extern int DAT_004A27D0;

extern "C" void __cdecl FUN_0041B3B0();
extern "C" int __cdecl FUN_004096C0(int);
extern "C" int __cdecl FUN_0040FDA0(int*, int, int, int, int, int, int, int, int);
extern "C" void __cdecl FUN_0040F8C0(int);
extern "C" void __cdecl FUN_00419B20();
extern "C" void __cdecl FUN_00405390(int, int);
extern "C" void __cdecl FUN_00419870();
extern "C" void __cdecl FUN_00417E70();
extern "C" void __cdecl FUN_00410280();
extern "C" void __cdecl FUN_0040F910(int, int, int, int);
extern "C" void __cdecl FUN_00402F50();
extern "C" void __cdecl FUN_00402E70(int);
extern "C" void __cdecl FUN_00402F30();
extern "C" void __cdecl FUN_00402F90();
extern "C" void __cdecl FUN_0040F740(int, int, int);
extern "C" void __cdecl FUN_00409970();
extern "C" void __cdecl FUN_00405350(int, int);
extern "C" int __cdecl GEX_WidescreenWidth(void);

extern "C" void __cdecl M1_EnterLevel_00409a30(int param_1)
{
    int iVar2;
    int object_unk;
    int object_ptr_unk_val;
    int viewportFixed = GEX_WidescreenWidth() << 16;
    int halfViewportFixed = viewportFixed / 2;
    
    DAT_004A2990 = param_1;
    DAT_00455B88 = 0;
    DAT_004593B8 = 0;
    DAT_004A2950 = 0;
    DAT_004A2A20 = 0;
    DAT_004A2ACC = 1;
    DAT_004A2A24 = 1;
    DAT_00455C48 = 1;
    DAT_004A2ABC = 1;
    DAT_004A2B04 = 0;
    DAT_004A2A38 = 0;
    DAT_004A2A1C = 0;
    DAT_004A2978 = 0;
    DAT_004A293C = 0;
    DAT_004A27FC = 0;
    DAT_004A2994 = 0;
    DAT_004A2948 = 0;
    DAT_004A2A7C = 0;
    DAT_00455C4C = 0;
    DAT_004A288C = 0;
    DAT_004A2A90 = 0;
    DAT_004A2940 = 0;
    DAT_00455B8C = 0;
    DAT_00455B90 = 0;
    DAT_004A2A04 = 1;
    DAT_004A2960 = 0;
    DAT_00455BE4 = 0;
    DAT_00458C7C = 0;
    DAT_00458C80 = 0;
    DAT_00458C84 = 0;
    DAT_00458C88 = 0;
    DAT_004626F4 = 1;
    DAT_004A2AC0 = *(unsigned short*)((int)&DAT_004577B0 + DAT_004A2964 * 8) & 0x80;
    DAT_00456018 = 0;
    DAT_00456B04 = 1;
    DAT_00458C78 = 0;
    DAT_004A23DC = 0;
    DAT_004A23D8 = 0;
    DAT_004A23D4 = 0;
    DAT_004A2AC8 = 4;
    DAT_004A282C = -1;
    DAT_004A23D0 = 0;
    FUN_0041B3B0();
    
    if ((DAT_00456ADC < 1) && (*(unsigned char*)((int)&DAT_004A2710 + DAT_004A2964) != 0)) {
        DAT_00456ADC = (unsigned int)*(unsigned char*)((int)&DAT_004A2710 + DAT_004A2964);
    }
    
    DAT_004626FC = 0;
    {
        int* object_ptr_unk = *(int**)(*(int*)(DAT_004A2990 + 4) + 0x24);
        object_unk = *object_ptr_unk;
        while (object_unk != 0) {
            object_ptr_unk++;
            DAT_004626FC++;
            object_unk = *object_ptr_unk;
        }
    }
    
    if (DAT_004626FC != 0) {
        DAT_004A2A78 = (int)FUN_004096C0(DAT_004626FC << 2);
        int* object_ptr_unk = *(int**)(*(int*)(DAT_004A2990 + 4) + 0x24);
        if (*object_ptr_unk != 0) {
            object_unk = 0;
            do {
                int puVar1 = *object_ptr_unk;
                object_ptr_unk++;
                puVar1 = FUN_0040FDA0(
                    (int*)(puVar1 + 4), *(int*)puVar1, (int)&FUN_00419870,
                    viewportFixed, 0xf00000, 0, 0, DAT_00455B70, DAT_00455B74);
                *(int*)(DAT_004A2A78 + object_unk) = puVar1;
                object_unk += 4;
            } while (*object_ptr_unk != 0);
        }
    }
    
    object_unk = 0;
    if (DAT_004626FC > 0) {
        iVar2 = 0;
        do {
            object_unk++;
            FUN_0040F8C0(*(int*)(DAT_004A2A78 + iVar2));
            iVar2 += 4;
        } while (object_unk < DAT_004626FC);
    }
    
    FUN_00419B20();
    FUN_00405390((int)&DAT_00455CC4, DAT_004A2924);
    FUN_00405390((int)&DAT_00455D54, 0);
    
    if (DAT_004A2960 == 0) {
        if (DAT_004A27FC == 0) {
            FUN_00405390((int)&DAT_00455D30, 0);
        } else {
            *(int*)(DAT_004A27FC + 12) = DAT_004A2AD4;
            
            if (DAT_00456ADC < 1) {
                DAT_004A27BC = 0;
                DAT_004A27CC = 0;
                DAT_004A27C8 = 0;
                DAT_004A27C0 = 0;
                DAT_004A27C4 = 0;
                DAT_004A27D0 = 0;
            } else if (DAT_004A282C < 0) {
                FUN_00405350((int)&DAT_00455D0C, DAT_00456ADC);
            } else {
                *(int*)(DAT_004A27FC + 0x78) = DAT_004A282C;
                *(int*)(DAT_004A27FC + 0x7c) = DAT_004A2830;
                *(int*)(DAT_004A27FC + 0x74) = 1;
            }
            
            if ((((DAT_004A2AC0 == 0) && (DAT_004A2964 != 0x44)) && (DAT_00456ADC < 1)) || (DAT_00456AE0 == 1)) {
                FUN_00405390((int)&DAT_00455CF4, 0);
                FUN_00417E70();
                DAT_00455C28 = 0;
            }
            
            DAT_00456AEC = DAT_00456ADC;
            DAT_00456AD8 = -1;
            DAT_00456ADC = -1;
            DAT_00456AE4 = -1;
            DAT_00456AF0 = -1;
            DAT_00456AF4 = -1;
            DAT_00456AF8 = -1;
            DAT_004A292C = *(int*)(DAT_004A27FC + 0x78);
            DAT_004A2A1C = *(int*)(DAT_004A27FC + 0x7c) - 0xa80000;
            DAT_004A2A38 = DAT_004A292C - halfViewportFixed;
            DAT_004A2928 = *(int*)(DAT_004A27FC + 0x7c);
            
            if (DAT_004A2A38 < 0) DAT_004A2A38 = 0;
            if (DAT_004A2A1C < 0) DAT_004A2A1C = 0;
            
            object_unk = *(int*)(*(int*)(DAT_004A2990 + 4) + 4);
            if (object_unk - viewportFixed <= DAT_004A2A38) {
                DAT_004A2A38 = object_unk - viewportFixed - 0x10000;
            }
            if (DAT_004A2A38 < 0) DAT_004A2A38 = 0;
            object_unk = *(int*)(*(int*)(DAT_004A2990 + 4) + 8);
            if (object_unk + -0xf00000 <= DAT_004A2A1C) {
                DAT_004A2A1C = object_unk + -0xf10000;
            }
            
            object_unk = 0x10;
            do {
                FUN_00410280();
                object_unk--;
            } while (object_unk != 0);
        }
    }
    
    DAT_004A2A94 = 0;
    DAT_004A2974 = (unsigned int)DAT_004A2A38;
    DAT_004A2A96 = 0;
    DAT_004A2988 = DAT_004A2A1C;
    
    if (DAT_004A2AD0 == 0) {
        iVar2 = 0;
        DAT_004A2A40 = 1;
        object_unk = 0;
        if (DAT_004626FC > 0) {
            do {
                iVar2++;
                FUN_0040F910(
                    *(int*)(DAT_004A2A78 + object_unk),
                    DAT_004A2A38,
                    DAT_004A2A1C,
                    1);
                object_unk += 4;
            } while (iVar2 < DAT_004626FC);
        }
        DAT_004A2A40 = 0;
    }
    
    if (DAT_004A2A14 != 0) {
        if (DAT_004A2A88 == 0) {
            FUN_00402F50();
        } else {
            FUN_00402E70(DAT_004A2A88);
            FUN_00402F30();
        }
        FUN_00402F90();
        DAT_004A2A08 = DAT_004A2A14;
        DAT_004A2A14 = 0;
    }
    
    if (DAT_004A2A0C != 0) {
        FUN_0040F740(0, DAT_004A2968, 0);
    }
    
    DAT_004626F0 = DAT_00455C3C;
    DAT_004A2A98 = DAT_004A2964;
    FUN_00409970();
}
}
