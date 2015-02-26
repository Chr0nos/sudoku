void *ft_memcpy(void *dest, const void *src, int n)
{
    int i;
    char *d;
    const char *s;

    i = 0;
    s = src;
    d = dest;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return dest;
}
