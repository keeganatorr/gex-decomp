extern "C" {
    extern int DAT_0045ffb0;
    extern int CAMERA_XPos_004a2a38;
    extern int DAT_004a2974_CameraX_TrueCam2;
    void VSIT_PlayVoiceSituation_0041f8c0(int);
    void VFX_Play_0041fa80(int);
}

extern "C" void GEX_Target(void)
{
    DAT_0045ffb0 = DAT_0045ffb0 + 1;
    if (DAT_0045ffb0 % 0x3c == 0) {
        VSIT_PlayVoiceSituation_0041f8c0(0x25);
    }
    if (DAT_0045ffb0 % 0xf0 == 0) {
        VFX_Play_0041fa80(0x25);
    }
    CAMERA_XPos_004a2a38 = 0x200000;
    DAT_004a2974_CameraX_TrueCam2 = 0x200000;
}
