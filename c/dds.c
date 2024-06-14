#include <stdio.h>
int func (int *a, int *b)
{
    *a=*a+*b;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
printf("%d", func(5, 7));
}
