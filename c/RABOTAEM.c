#include <stdio.h>
#include <math.h>
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int b,k,a,n;
long long sum = 0;
scanf("%d", &n);
for (a=1; a<=cbrt(n); a++)
{
    for (b=a; b<=sqrt(n); b++)
    {
        if (n/(a*b)-b+1 < 0)
        { break; }
        if (n/(a*b) < b)
        { break; }
        sum=sum+(n/(a*b))-b+1;
    }
}
printf("%lld", sum);

return 0;
}
