#include <stdio.h>
#include <stdlib.h>

int comparator (const void *a, const void *b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}
void main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int *a;
    a = malloc(sizeof(int) * n);
    for(int i=0; i < n; ++i)
        scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    int *b;
    b = malloc(sizeof(int) * m);
    for(int i=0; i < m; ++i)
        scanf("%d", &b[i]);
    qsort(a, n, sizeof(int), comparator);
    qsort(b, m, sizeof(int), comparator);
    int *arr;
    arr = malloc(sizeof(int) * n);
    int *arrcopyofarr;
    arrcopyofarr = malloc(sizeof(int) * n);
    int ci = 0;
    int j = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] > b[j] && j < m)
        {
            ++j;
        }
        else if (((a[i] < b[j]) || (j >= m)) && arrcopyofarr[ci-1] != a[i])
        {
            arrcopyofarr[ci] = a[i];
            ++ci;
            ++i;
        }
        else if (a[i] == b[j])
        {
            ++i;
        }
        else
        {
            ++i;
        }
    }

    printf("%d\n", ci);
    for (int i=0; i < ci; ++i)
        printf("%d ", arrcopyofarr[i]);
}
