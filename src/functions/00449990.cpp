extern "C" char * __cdecl FUN_00449990_Registry2(char *text, const char *needle)
{
    if (*needle == 0)
        return text;
    for (char *start = text; *start != 0; ++start) {
        if (*start != *needle)
            continue;
        const char *match = needle + 1;
        char *candidate = start + 1;
        while (*match != 0 && *candidate == *match) {
            ++candidate;
            ++match;
        }
        if (*match == 0)
            return start;
    }
    return 0;
}
