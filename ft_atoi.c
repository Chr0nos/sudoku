int ft_atoi(const char* string)
{
    int pos;
    int result;
    char cint;

    pos = 0;
    result = 0;
    while (string[pos++] != '\0')
    {
        cint = string[pos] - '0';
        result += cint * ((pos -1) * 10);
    }
    return pos;
}
