#include <stdio.h>
#include <string.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char c [10000];
    scanf("%s", &c);
    int n = 0,k = 0,l = 1,t;
    t=strlen(c);

    while (n<t)
    {
        if (c[n]=='.')
            l=1;
        else
        {
            if (l==1)
            {
                k=k+1;
                l=0;
            }
        }
        n=n+1;
    }

    printf("%d", k);
    return 0;
}
