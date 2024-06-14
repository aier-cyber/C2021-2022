#include <stdio.h>
void getmod(long long int* val)
{
    for(;;)
    {
        if (*val >= 1000000007)
        {
            *val = *val - 1000000007;
        }
        else
        {
            break;
        }
    }
}
long long int solve(long long int val)
{
    //printf(" ----------\nSolver started\n");
    long long int mimic = 1000000005;
    long long int res = 1;
    long long int nev = val;
    long long int nem = 1000000005;
    //printf("%d %d\n", power, mimic);
    // power определён правильно
    for (mimic = 0; mimic < 30; mimic++)
    {
        if (1000000007 & (1<<mimic))
        {
            res = res*nev;
            getmod(res);
        }
        nev = nev*nev;
        getmod(nev);
    }
    //printf("%d %d\n", power, mimic);
    //printf("Solver ended\n ----------\n");
    return res;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int t, n, k, i, s, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        s = 1;
        scanf("%d %d", &n, &k);
        if (k < n/2)
            k = n-k;
        for (j = 0; j < n; j++)
        {
            if (j > k)
            {
              s *= j;
              getmod(s);
            }
            if (j < n - k + 1)
            {
                s *= solve(k);
                getmod(s);
            }
        }
        printf("%lld\n", s);
    }
}
