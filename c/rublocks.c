#include <stdio.h>
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int n, i, k, c, d, e, m;
int a[10000], b[10000], j[10000];
scanf("%d", &n);
for (i=0; i<n; ++i)
{
    scanf("%d", &a[i]);
}
scanf("%d", &k);
for (i=0; i<k; ++i)
{
    scanf("%d", &b[i]);
}
m=0;
for (i=0; i<n; ++i)
{
    d=0;
    for  (c=0; c<k; ++c)
    {
        if (a[i]==b[c])
        {
            d=1;
        }
    }
    if (d == 0)
    {
        e=i-1;
        while (e>=0)
        {
            if (a[i]==a[e])
            {
                break;
            }
            e=e-1;
        }
        if (e==-1)
        {
            m=m+1;
            j[m]=a[i];
        }
    }
}
if (m==0)
{
    printf("0");
}
else
{
    printf("%d\n", m); // j[m] ikc
    for (e=1; e<=m; ++e)
    {
        c=100001;
        for (i=1; i<=m; ++i)
        {
            if (j[i]<c)
            {
                c=j[i];
                k=i;
            }
        }
        printf("%d ", c);
        j[k]=100001;
    }
}
return 0;
}
