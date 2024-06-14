#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void* b){
return (*(int*)a - *(int*)b);
}

long long int arr[300000];
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
long long int sum = 0;
int i, j, n;
scanf("%d", &n);
for (i = 0; i < n; i++)
{
    scanf("%lld", &arr[i]);
}

qsort(arr, n, 8, comp);
for (i = 0; i < n; i++)
{
    sum += arr[i]*(n-i-1);
}
printf("%lld", sum);
return 0;
}
