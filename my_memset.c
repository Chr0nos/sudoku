void *my_memset(void *s, int c, unsigned long size) {
    char *x;
    unsigned long pos;

    pos = size;
    while (pos)
    {
        x = s;
        x[pos] = c;
        pos--;
    }
    return s;
}
