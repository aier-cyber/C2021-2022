#include <stdio.h>
long long int gcd (long long int a, long long int b, long long int *x, long long int *y) {
	if (a == 0)
    {
		*x = 0;
		*y = 1;
		return b;
	}
	long long int sx, sy, d;
	d = gcd (b%a, a, &sx, &sy);
	*x = sy - (b / a) * sx;
	*y = sx;
	return d;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int N, K, i, j, t, ans, anst, x, y;
    scanf("%llu", &j);
    for (i = 0; i < j; i++)
    {
        ans = 1;
        anst = 1;
        scanf("%llu %llu", &N, &K);
        if (K < N/2)
            K = N-K;
        for (t = 1; t <= N; t++)
        {
            if (t >= K+1)
            {
                ans *= t;
                ans %= 1000000007;
            }
            if (t <= N-K)
            {
                anst *= t;
                anst %= 1000000007;
            }
        }
        t = gcd(anst, 1000000007, &x, &y);
        if (x < 0)
            x += 1000000007;
        ans *= x;
        ans %= 1000000007;
        printf("%llu\n", ans);
    }
    return 0;
}
