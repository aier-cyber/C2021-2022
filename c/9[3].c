#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    return (x - y);
}

void main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, n;
    long long int sum=0;
    int *arr;
    scanf ("%d", &n);
    arr = malloc(sizeof(int) * n);

    for (i=0; i<n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    int long long mimic = 0;
    qsort(arr, n, sizeof(long int), comp);
        for (i=0; i<n; i++)
        {
            sum=sum+mimic;
            mimic=mimic+arr[i];
        }
    printf("%lld", sum);
}
