int ft_strlen(const char *string)
{
    int size;

    size = 0;
    if (!string)
        return 0;
    while (string[size])
    {
        size++;
    }
    return size;
}
