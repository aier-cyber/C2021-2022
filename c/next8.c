#include <stdio.h>

typedef union mask {
double x;
unsigned long long int y;
} mask;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, ans, n;
    float a, b;
    unsigned long long int c;

    scanf("%d", &n);
    union mask list;

    for(i = 0; i < n; i++)
    {
        scanf("%e/%e xor %llx", &a, &b, &c);
        list.x = a/b;
        list.y ^= c;
        printf("%0.15g\n", list.x);
    }
    return 0;
}
