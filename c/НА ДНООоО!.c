#include <stdio.h>
int arr[100000];
int mimic[10001];
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int n,c,i,count = 0;
scanf("%d", &n);
for (i = 1; i <= n; i++)
    scanf("%d", &arr[i]);

for (i = 1; i <= n; i++)
{
    mimic[arr[i]]++;
}

for (i= 1; i<= 10001; i++)
{
    if (mimic[i] != 0)
        printf("%d: %d\n", i, mimic[i]);
}

return 0;
}
