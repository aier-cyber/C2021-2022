#include <stdio.h>
void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a = 5, b = 10;
    swap (&a, &b);
    printf ("%d %d", a, b);
    return 0;
}
