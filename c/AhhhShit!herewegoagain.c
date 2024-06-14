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
long long int m[100000];
long long int c[100000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int n, ans = 0, product = 1, P, pb, x, y;
    int k, i;
    scanf("%llu", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%llu", &m[i]);
        product = product * m[i]; // 1100
    }
    for (i = 0; i < k; i++)
    {
        scanf("%llu", &c[i]);
    }//+
    for (i = 0; i < k; i++)
    {
        P = product/m[i];
        n = gcd(P, m[i], &x, &y);
        if (x < 0)
            x += m[i];
        ans = ans + P*((c[i]*x)%m[i]);
        ans %= product;
    }
    printf("%llu", ans);
    return 0;
}
