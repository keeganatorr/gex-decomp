extern "C" {
int* RemoteFindWithLevel_00429b40(int level);
int* GOB_FindWithWork0_0040c110(int type, int work);
void assertfail_00405350(const char* msg, int level);
int* FUN_00429bd0_Object_unk(void);
int* GOB_FindFirstWithType_00429c60(int type);
extern int LEVELID_004a2a74;
extern char s_ERROR__Couldn_t_find_TV_for_leve_0045af9c[];
int GEX_Target(int* gOb, int frame);
}

int GEX_Target(int* gOb, int frame)
{
    int* l_gOb;
    int* l_gOb2;
    int doorId;

    if (frame != 0) {
        l_gOb = GOB_FindWithWork0_0040c110(0xdc, frame);
    }
    else {
        l_gOb = RemoteFindWithLevel_00429b40(LEVELID_004a2a74);
        if (l_gOb != 0) goto LAB;
        l_gOb = RemoteFindWithLevel_00429b40(0x37);
    }
    if (l_gOb == 0) {
        assertfail_00405350(s_ERROR__Couldn_t_find_TV_for_leve_0045af9c, LEVELID_004a2a74);
        l_gOb = FUN_00429bd0_Object_unk();
        if (l_gOb == 0) {
            l_gOb = GOB_FindFirstWithType_00429c60(0xdc);
        }
    }
LAB:
    l_gOb2 = 0;
    doorId = l_gOb[0x2d];
    if (doorId <= 0) {
        doorId = l_gOb[0x2a];
        if (doorId <= 0) {
            doorId = l_gOb[0x2b];
            if (doorId <= 0) goto SKIP;
        }
    }
    l_gOb2 = GOB_FindWithWork0_0040c110(0xdd, doorId);
SKIP:
    if (l_gOb2 == 0) {
        l_gOb2 = l_gOb;
    }
    gOb[0x1e] = l_gOb2[0x1e];
    gOb[0x1f] = l_gOb2[0x1f];
    return l_gOb[0x26];
}
