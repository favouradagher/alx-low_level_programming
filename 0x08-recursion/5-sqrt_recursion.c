/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number @n,
 *         or -1 if @n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
    int i;

    if (n < 0)
        return (-1);
    if (n == 0 || n == 1)
        return (n);
    for (i = 1; i * i <= n; i++)
        if (i * i == n)
            return (i);
    return (-1);
}

