#include <stdio.h>
int all[2001][2001];
void fill(long long int mod)
{
    int n, k;
    all[0][0] = 1;
    all[1][0] = 1;
    all[1][1] = 1;
    for (n = 2; n < 2001; n++)
    {
        for (k = 0; k <= n; k++)
        {
            all[n][k] = all[n-1][k-1]+all[n-1][k];
            all[n][k] %= mod;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, K, M, T, i;
    scanf("%d %d", &M, &T);
    fill(M);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &K);
        if ((K > N) || (K < 0))
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", all[N][K]);
    }
    return 0;
}
