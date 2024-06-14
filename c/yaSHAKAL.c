#include <stdio.h>
#include <string.h>
/*int ezSolver (int n, int k, mod m)
{
    printf("Entry a new step. n = %d, k = %d\n", n, k);
    if ((k == 0) || (n == 0))
        return 1;
    int a = ezSolver(n-1, k-1);
    int b (a * (n-k)) /
    int b = a + (a * (n-k)) / k;
    printf("This step results: a = %d, b = %d\n", a, b);
    return b;
} //---Это для модуля--- */
long long int ezSolver (long long int n, long long int k)
{
    //printf("Entry a new step. n = %d, k = %d\n", n, k);
    if ((k == 0) || (n == 0))
        return 1;
    long long int a = ezSolver(n-1, k-1);
    long long int b = a + (a * (n-k)) / k;
    //printf("This step results: a = %d, b = %d\n", a, b);
    return b;
} //---Это без модуля--- */
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int n, k, i, mod, T, ans;
    scanf("%lld %lld", &mod, &T);
    for (i = 0; i < T; i++)
    {
        scanf("%lld %lld", &n, &k);
        if ((k < 0) || (n < k))
        {
            printf("0\n");
        }
        else
        {
            if (k > n/2)
            {
                k = n-k;
            }
            long long int c = ezSolver (n, k);
            //printf("----%lld----\n", c);
            c = c % mod;
            printf("%lld\n", c);
        }
    }
    return 0;
}
