/**
 * is_prime_number - checks if a number is a prime number
 * @n: the number to check
 *
 * Return: 1 if the number is prime, otherwise 0
 */
int is_prime_number(int n)
{
    int i;

    if (n <= 1) /* 0 and 1 are not prime numbers */
        return (0);
    if (n == 2) /* 2 is a prime number */
        return (1);
    if (n % 2 == 0) /* even numbers other than 2 are not prime */
        return (0);
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return (0);
    }
    return (1);
}

