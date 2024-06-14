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
    a %= MOD;
    if (a < 0)
    {
        return (a+MOD);
    }
    else
    {
        return a;
    }
}

int padd(int a, int b){
    return pnorm(pnorm(a) + pnorm(b));
}

int psub(int a, int b){
    return pnorm(a - b);
}

int pmul(int a, int b){
    long long int typeMagick = (long long int)pnorm(a) * (long long int)pnorm(b);
    typeMagick %= MOD;
    int typeMagikc = pnorm((int)typeMagick);
    return typeMagikc;
}

int pdiv(int a, int b){
    int x,y;
    gcd(b, MOD, &x, &y);
    x = pnorm(x);
    return pmul(a, x);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    MOD = 10000019;
    printf("%d\n", pdiv(10000018, 10000018));

    return 0;
}
