int intArrayMax(int a[], int size, int max)
{
    if (size < 0)
        return max;
    else
    {
        if (a[size] > max)
            return intArrayMax(a, size - 1, a[size]);
        else
            return intArrayMax(a, size - 1, max);
    }
}