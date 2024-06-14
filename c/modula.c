#include <stdio.h>

int MOD;

int gcd (int a, int b, int *x, int *y) {
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

int pnorm(int a){
    if (a < 0)
    {
        a *= -1;
        a %= MOD;
        return (MOD - a);
    }
    else
    {
        return (a % MOD);
    }
}

int padd(int a, int b){
    return pnorm(pnorm(a) + pnorm(b));
}

int psub(int a, int b){
    return pnorm(pnorm(a) - pnorm(b));
}

int pmul(int a, int b){
    return pnorm(pnorm(a)*pnorm(b));
}

int pdiv(int a, int b){
    int x,y;
    gcd(a, b, &x, &y);
    x = pnorm(x);
    return pmul(a, x);
}
