#include <stdio.h>
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int a, b, n;
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
    scanf("%d %d", &a, &b);
    while ((a != 0) && (b != 0))
    {
        if (a >= b)
            a = a % b;
        else
            b = b % a;
    }
    printf("%d\n", a+b);
}
return 0;
}
