#include <stdio.h>
#include <string.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char c [10000];
    scanf("%s", &c);
    int n,count = 0,guard = 1,t;
    t=strlen(c);

    for(n=0; n<t; n++)
    {
        if (c[n]=='.')
            guard=1;
        else
        {
            if (guard==1)
            {
                count=count+1;
                guard=0;
            }
        }
    }

    printf("%d", count);
    return 0;
}
