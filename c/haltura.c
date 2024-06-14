#include <stdio.h>
int Euklid (int a, int b)
{
    while ((a != 0) && (b != 0))
    {
        if (a >= b)
            a = a % b;
        else
            b = b % a;
    }
    return a+b;
}
long long int EuklidExtra (long long int a, long long int b)
{
    if (a%b == 1)
        return 1;
    if (a > b)
        return (Euklid(a, b) - b * (EuklidExtra(b, a%b)))/a;
    if (b > a)
        return (Euklid(a, b) - b * (EuklidExtra(a, b%a)))/a;
}

long long int THE_LASIEST(long long int n, long long int k, long long int m)
{
    long long int h = n - k, i, all = 1, addition = 1;
    for (i = 1; i <= n; i++)
    {
        if (i > k)
        {
            all *= i;
            all %= m;
        }
        if (i <= n-k)
        {
            addition *= i;
            addition %= m;
        }
    }
    return ((all*EuklidExtra(addition, m)) % m);
}

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
long long int n, k, m, t;
int i;
scanf("%lld", &t);
for (i = 0; i < t; i++)
{
    scanf("%lld %lld", &n, &k);
}
i = EuklidExtra(17, 3);
printf("%d", i);

return 0;
}
