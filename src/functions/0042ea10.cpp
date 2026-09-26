extern "C" {
extern int CAMERA_YPos_004a2a1c;
void __cdecl GEX_Target(int y1, int y2, int y3, unsigned int order)
{
    switch (order) {
    case 1:
        CAMERA_YPos_004a2a1c = y1 - ((y1 - y3) + 0xf00000 >> 1);
        return;
    case 2:
        CAMERA_YPos_004a2a1c = y1 - ((y1 - y2) + 0xf00000 >> 1);
        return;
    case 3:
        CAMERA_YPos_004a2a1c = y2 - ((y2 - y3) + 0xf00000 >> 1);
        return;
    case 4:
        CAMERA_YPos_004a2a1c = y2 - ((y2 - y1) + 0xf00000 >> 1);
        return;
    case 5:
        CAMERA_YPos_004a2a1c = y3 - ((y3 - y2) + 0xf00000 >> 1);
        return;
    case 6:
        CAMERA_YPos_004a2a1c = y3 - ((y3 - y1) + 0xf00000 >> 1);
    }
}
}
