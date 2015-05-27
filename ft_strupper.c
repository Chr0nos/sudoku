char*   ft_strupper(char *s)
{
    char    *str;

    str = s;
    while (*s != '\0')
    {
        if ((*s >= 'a') && (*s <= 'z'))
        {
            *s -= 32;
        }
        s++;
    }
    return str;
}
