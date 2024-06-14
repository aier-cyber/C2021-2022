#include <stdio.h>
int gcd (int a, int b, int *x, int *y) {
    {
        printf("ABOBA bda bda bda bda %d %d\n", *x, *y);
    }
	if (a == 0)
    {
		*x = 0;
		*y = 1;
		return b;
	}
	int sx, sy, d;
	d = gcd (b%a, a, &sx, &sy);
	*x = sy - (b / a) * sx;
	*y = sx;
	return d;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x, y;
    int a = 10;
    int b = 17;
    n = gcd(a, b, &x, &y);
    if (x < 0)
        x += b;
    if (y < 0)
        y += a;
    printf("gcd = %d, x = %d, y = %d", n, x, y);
    return 0;
}
