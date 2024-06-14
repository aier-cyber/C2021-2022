#include <stdio.h>
int NOD(int a, int b)
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

long long int solve(int val, int degree, int mod)
{
    //printf(" ----------\nSolver started\n");
    int power = 0, res = 1, mimic = degree;
    long long int nev = (long long int)val;
    long long int nem = (long long int)mod;
    while (mimic != 0)
    {
        power++;
        mimic = mimic/2;
    }
    //printf("%d %d\n", power, mimic);
    // power определён правильно
    for (mimic = 0; mimic < power; mimic++)
    {
        if (degree & (1<<mimic))  // max mim = 3 => 1<<3 = 0b00001000 = 8
        {
            res = res*nev;
            res %= nem;
        }
        nev = nev*nev;
        nev %= nem;
    }
    //printf("%d %d\n", power, mimic);
    //printf("Solver ended\n ----------\n");
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, M, i, n, k;
    long long int b;
    scanf("%d %d", &n, &M);
    k = M-2;
    //printf("***%d***\n", k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if ((NOD(a, M) == 1) && (a != 0))
        {
            b = solve(a, k, M);
            printf("%d\n", b);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
