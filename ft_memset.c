void *ft_memset(void *s, int c, unsigned long size) {
    char *x;
    unsigned long pos;

    if (!s) return 0;
    pos = size;
    while (pos)
    {
        x = s;
        x[pos] = c;
        pos--;
    }
    return s;
}
