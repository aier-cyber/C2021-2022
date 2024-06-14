#include <stdio.h>
// 1000000005 = 1110 1110 0110 1011 0010 1000 0001 01
int BinAr[] = {1, 1, 1, 0,/*4*/ 1, 1, 1, 0,/*8*/ 0, 1, 1, 0,/*12*/ 1, 0, 1, 1,/*16*/ 0, 0, 1, 0,/*20*/ 1, 0, 0, 0,/*24*/ 0, 0, 0, 1,/*28*/ 0, 1};
long long int solve(long long int val)
{
    int i;
    long long int res = 1;
    for (i = 29; i >= 0; i--)
    {
        if (BinAr[i] == 1)
        {
            res = res*val;
            res %= 1000000007;
        }
        val = val*val;
        val %= 1000000007;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int N, K, i, j, t, ans;
    scanf("%d", &j);
    for (i = 0; i < j; i++)
    {
        ans = 1;
        scanf("%d %d", &N, &K);
        if (K < N/2)
            K = N-K;
        for (int h = N-1; h > N-K; h--)
        {
            ans = ans * h;
            ans = ans % 1000000007;
            ans = ans * solve(N-h);
            ans = ans % 1000000007;
        }
        ans = ans * N;
        ans = ans % 1000000007;
        ans = ans * solve (K);
        ans = ans % 1000000007;
        printf("%d\n", ans);
    }
    return 0;
}
