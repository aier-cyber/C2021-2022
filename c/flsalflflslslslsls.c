#include <stdio.h>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, c, i, f;
    scanf("%d", &n);
    int a[n];
    int b[10000];
    for (i=1; i<=10000; ++i)
    {
        b[i]=0;
    }
    c=0;
    for (i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        b[a[i]]=b[a[i]]+1;
        if (a[i]>c)
        {
            c=a[i];
        }
    }
    for (i=1; i<=10000; ++i)
    {
        if (b[i]==0)
        {
        }
        else
        {
            printf("%d: %d\n", i, b[i]);
        }
    }
    return 0;
}
