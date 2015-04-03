int ft_pow(const int numeric, const int power)
{
    int result;
    int i;

    if (!numeric) return 0;
    i = 0;
    result = 1;
    while (i < power)
    {
        result *= numeric;
        i++;
    }
    return result;
}
