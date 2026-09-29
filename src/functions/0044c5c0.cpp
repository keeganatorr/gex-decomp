extern "C" void * __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl __amsg_exit(int);

extern "C" void __cdecl FUN_0044C5C0(void)
{
    int &count = *(int *)0x004a43c0;
    if (count == 0)
        count = 0x200;
    else if (count < 20)
        count = 20;

    void **streams = (void **)calloc(count, 4);
    *(void ***)0x004a33b0 = streams;
    if (streams == 0) {
        count = 20;
        streams = (void **)calloc(20, 4);
        *(void ***)0x004a33b0 = streams;
        if (streams == 0)
            __amsg_exit(0x1a);
    }
    int i;
    for (i = 0; i < 20; ++i)
        streams[i] = (void *)(0x00461778 + i * 0x20);

    unsigned char *handles = *(unsigned char **)0x004a43d0;
    for (i = 0; i < 3; ++i) {
        int handle = *(int *)(handles + i * 8);
        if (handle == 0 || handle == -1)
            *(int *)(0x00461788 + i * 0x20) = -1;
    }
}
