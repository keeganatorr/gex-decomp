extern "C" void __cdecl GOB_PhysicsStepY_0040f2a0(int* p)
{
    int maxVel;
    int vel = p[0x23] + p[0x25];
    maxVel = p[0x24];
    p[0x23] = vel;
    if (maxVel < vel) {
        p[0x23] = maxVel;
    } else if (vel < -maxVel) {
        p[0x23] = -maxVel;
    }
    p[0x1f] += p[0x23];
}
