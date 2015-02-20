int my_strlen(const char *string)
{
    int size;

    size = 0;
    while (string[size])
    {
        size++;
    }
    return size;
}
