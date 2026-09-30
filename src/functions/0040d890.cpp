// The pinned 0040d890 routine returns the separator (or final NUL) in EAX.
// HelpBoxDraw uses that pointer to advance through a multiline message.
extern "C" char *__cdecl HelpBoxGetLine_0040d890(char *line, unsigned int *flags)
{
    char *end = line;
    while (*end && *end != '\\')
        ++end;

    unsigned int result = (end[1] == 'C' || end[1] == 'c') ? 4 : 2;
    if (*end)
        *end = 0;
    else
        result = 1;
    *flags = result;
    return end;
}
