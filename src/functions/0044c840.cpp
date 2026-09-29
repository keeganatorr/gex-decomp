typedef unsigned int uint;
void __cdecl __CopyMan(uint *destination, uint *source)
{
    int count = 3;
    do {
        *source = *destination;
        destination += 1;
        source += 1;
        count -= 1;
    } while (count != 0);
}
